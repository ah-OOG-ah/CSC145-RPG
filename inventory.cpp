    #include "inventory.h"
    #include <cstdint>
    #include <string>
    #include <iostream>

    Inventory::Inventory() {}

    Inventory::Inventory(Item* firstItem)
    {
        index = firstItem;
        start = firstItem;
        end = firstItem;
    }

    void Inventory::GoToNext() 
    { 
        if(index->GetNext() != nullptr)
        {
            index = index->GetNext(); 
        }
    }
    void Inventory::GoToPrev() 
    { 
        if(index->GetPrev() != nullptr)
        {
        index = index->GetPrev(); 
        }
    }
    void Inventory::GoToStart() { index = start; }
    void Inventory::GoToEnd() { index = end; }
    void Inventory::GoToPosition(int64_t pos)
    {
        GoToStart();
        for(int i = 0; i < pos; i++)
        {
            GoToNext();
        }
    }

    void Inventory::GoToName(std::string name)
    {
        GoToStart();
        do
        {
            if(name == index->GetName())
            {
                break;
            }
            else
            {
                GoToNext();
            }
        } while (index->GetNext() != nullptr);
        
    }
    
    /*std::string Inventory::GetIndexName() { return index->GetName(); }
    int64_t Inventory::GetIndexAmnt() { return index->GetAmount(); }
    std::string Inventory::GetIndexText() { return index->GetAmntText(); }*/
    Item* Inventory::GetIndex() { return index; }
    Item* Inventory::GetStart() { return start; }
    Item* Inventory::GetEnd() { return end; }


    void Inventory::ChangeIndexAmnt(int64_t amnt)
    {
        index->ChangeAmount(amnt);
    }

    void Inventory::ChangeItemAmnt(int64_t amnt, int64_t pos)
    {
        if(pos == 0)
        {
            start->ChangeAmount(amnt);
        }
        else if(pos == (size - 1))
        {
            end->ChangeAmount(amnt);
        }
        else
        {
            GoToStart();
            GoToPosition(pos);
            index->ChangeAmount(amnt);
        }
    }
    void Inventory::ChangeItemAmnt(int64_t amnt, std::string searchName)
    {
        if(end->GetName() == searchName) //Checks to see if the end's name is equal to the search name
        {
            end->SetName(searchName);
            return;
        }
        else
        {
            GoToStart();
            do
            {
                if(index->GetName() == searchName)
                {
                    index->ChangeAmount(amnt);
                    return;
                }
                else
                {
                    GoToNext();
                }
            }  while (index->GetNext() != nullptr);
        }
    }
    void Inventory::InsertItem(Item* newItem, int64_t pos)
    {
        GoToPosition(pos);
        newItem->SetPrev(index);
        (index->GetNext())->SetPrev(newItem);
        newItem->SetNext((index->GetNext()));
        index->SetNext(newItem);
        size++;
    }
    void Inventory::RemoveItem(int64_t pos)
    {
        GoToPosition(pos);
        ((index->GetNext())->GetNext())->SetPrev(index);
        index->SetNext(((index->GetNext())->GetNext()));
        size--;
    }
    void Inventory::RemoveItem(std::string name)
    {
        GoToStart();
        do
        {
            if(index->GetName() == name)
            {
                ((index->GetNext())->GetNext())->SetPrev(index);
                index->SetNext(((index->GetNext())->GetNext()));
                return;
            }
            else if(index->GetNext() != nullptr)
            {
                GoToNext();
            }
        } while (index->GetNext() != nullptr);
        size--;
    }

    void Inventory::PushBackItem(Item* newItem)
    {
        if(index == nullptr)
        {
            index = newItem;
            start = newItem;
            end = newItem;
        }
        else
        {
            end->SetNext(newItem);
            newItem->SetPrev(end);
            end = newItem;
        }
        size++;
    }

    Item* Inventory::PopBackItem()
    {
        GoToEnd();
        Item* formerEnd = end;
        GoToPrev();
        end = index;
        end->SetNext(nullptr);
        formerEnd->SetPrev(nullptr);
        size--;
        return formerEnd;
    }
    
    //Made ToString and Print because I want to figure out which one will be more pratical
    std::string Inventory::ToString()
    {
        GoToStart();
        std::string invenString;
        for(int i = 0; i < size; i++)
        {
            invenString += index->GetName();
            invenString += index->GetAmntText();
            invenString += std::to_string((index->GetAmount()));
            invenString += "\n";
            GoToNext();
        }
    }
    //void Inventory::PrintInven();