#pragma once

#include <memory>
#include <functional>
#include <utility>
#include <iostream>


struct MenuNode : public Menu {

  private:
    std::string data;
    std::weak_ptr<MenuNode> parent;
    std::vector<std::shared_ptr<MenuNode>> children;
    std::vector<std::function<void(int64_t)>> funcs;

  public:
    explicit MenuNode(std::string val) : data(std::move(val)) {}
    MenuNode(std::string val, std::weak_ptr<MenuNode> parent) : data(std::move(val)), parent(std::move(parent)) {
        for (const auto & i : children) {
            if (!i) continue;
            entries.push_back(i->data);
        }
    }

    bool isLeaf() { return children.empty(); }
    bool isRoot() {
        auto empty = std::weak_ptr<MenuNode>();
        return !parent.owner_before(empty) && !empty.owner_before(parent);
    }

    void setData(std::string val) { data = std::move(val); }
    void addChild(const std::shared_ptr<MenuNode>& n, std::weak_ptr<MenuNode> thiz) {
        n->parent = std::move(thiz);
        children.push_back(n);
        entries.push_back(n->data);
    }
    void setChild(const std::string& val, const std::shared_ptr<MenuNode>& thiz, size_t which) {
        setChild(val, std::weak_ptr<MenuNode>(thiz), which);
    }
    void setChild(const std::string& val, const std::weak_ptr<MenuNode>& thiz, size_t which) {
        children[which] = std::make_shared<MenuNode>(val, thiz);
    }
    void setParent(std::weak_ptr<MenuNode> val) { parent = std::move(val); }

    std::string getData() { return data; }
    std::shared_ptr<MenuNode> getChild(size_t which) { return children[which]; }
    std::weak_ptr<MenuNode> getParent() { return parent; }

    void iterate(const std::function<void(const std::string)>& func) const {
        func(this->data);
        for (const auto & i : children) {
            if (i) i->iterate(func);
        }
    }

    void generateFuncs(std::shared_ptr<MenuNode>& pNode) {
        for (const auto & i : children) {
            if (!i) continue;
            funcs.emplace_back([&pNode](int64_t i){ pNode = pNode->getChild(i); });
        }
    }

    void display() override {
        if (entries.size() > 1) return Menu::display();
        if (entries.empty()) return;

        std::cout << entries[0] << std::endl;
        dispatch(0);
    }

    void dispatch(int64_t i) override {
        if (funcs.empty()) std::cout << "Dispatch not initialized!" << std::endl;
        funcs[i](i);
    }
};
