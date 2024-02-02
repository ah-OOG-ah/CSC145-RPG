    #include "inventory.h"
    #include <cstdint>
    #include <string>


    void Inventory::GoToNext() { index = index->GetNext(); }
    void Inventory::GoToPrev() { index = index->GetPrev(); }
    void Inventory::GoToStart() { index = start; }
    void Inventory::GoToEnd()
    {
        while(index->GetNext() != nullptr)
        {
            GoToNext();
        }
    }
    
    std::string Inventory::GetIndexName() { return index->GetName(); }
    int64_t Inventory::GetIndexAmnt() { return index->GetAmount(); }
    int64_t Inventory::GetIndexTitle() { return index->GetAmntTitle(); }

    void Inventory::ChangeItemAmnt(int64_t amnt)
    {
        index->ChangeAmount(amnt);
    }
    void Inventory::ChangeItemAmnt(int64_t amnt, int64_t pos)
    {
        GoToStart();
        for(int i = 0; i < pos; i++)
        {
            if(index->GetNext() != nullptr)
            {
                GoToNext();
            } 
            else
            {
                break;
            }
        }
        index->ChangeAmount(amnt);
    }
    void Inventory::ChangeItemAmnt(int64_t amnt, std::string name)
    {
        GoToStart();
        while(index->GetNext() != nullptr)
        {
            if(index->GetName() == name)
            {
                index->ChangeAmount(amnt);
                return;
            }
            else
            {
                GoToNext();
            }
        }
        GoToEnd();
        if(index->GetName() == name)
        {
            index->ChangeAmount(amnt);
        }
    }
    /*void Inventory::InsertItem(Item* newItem, int64_t pos);
    void Inventory::RemoveItem(int64_t pos);
    void Inventory::RemoveItem(std::string name);
    //Made ToString and Print because I want to figure out which one will be more pratical
    std::string Inventory::ToString();
    void Inventory::PrintInven(); */