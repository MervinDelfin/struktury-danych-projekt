#include "SelfSortList.h"
#include<fstream>

SelfSortList::SelfSortList()
{
	head = nullptr;
	rear = nullptr;
}

void SelfSortList::Insert(int num)
{
    
    Snode* temp = new Snode;

   
    temp->val = num;
    temp->count = 0;
    temp->next = nullptr;

    
    if (head == nullptr)
        head = rear = temp;

 
    else {
        rear->next = temp;
        rear = temp;
    }
}

bool SelfSortList::Search(int key)
{
    Snode* current = head;


    Snode* prev = nullptr;

    while (current != nullptr) {

        if (current->val == key) {

            current->count = current->count + 1;

  
            if (current != head) {
                Snode* temp = head;
                Snode* temp_prev = nullptr;
                while (current->count < temp->count) {
                    temp_prev = temp;
                    temp = temp->next;
                }

                if (current != temp) {
                    prev->next = current->next;
                    current->next = temp;

                    if (temp == head)
                        head = current;
                    else
                        temp_prev->next = current;
                }
            }
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}

void SelfSortList::Print()
{
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Snode* temp = head;
    std::cout << "List: ";

    while (temp != nullptr) {
        std::cout << temp->val << "(" << temp->count << ")";
        if (temp->next != nullptr)
            std::cout << " --> ";

        temp = temp->next;
    }
    std::cout << std::endl<< std::endl;
}

void SelfSortList::SaveToFile(std::string file)
{
    std::ofstream Save(file + ".txt");
    if (head == nullptr) {
        Save << "List is empty" << "\n";
        return;
    }

    Snode* temp = head;
    Save << "List: ";
    int i = 0;
    while (temp != nullptr) {
        Save << i<<") " << temp->val << "(" << temp->count << ")";
        if (temp->next != nullptr)
            Save << " \n ";

        temp = temp->next;
        i++;
    }
    Save << "\n" << "\n";
    Save.close();
}

void SelfSortList::Remove(int key)
{
    Snode* current = head;

    while (current-> next ->val != key) {

        if (current->next == nullptr)
            return;
        else
        {
            current = current->next;
        }
        
    }
    Snode* todelete = current->next;
    current->next = todelete->next;
    delete[] todelete;
}


Snode::Snode()
{
    val = 0;
    count = 0;
    next = nullptr;
}
