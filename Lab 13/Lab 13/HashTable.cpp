#include <iostream>
#include"HashTable.h"
using namespace std;
void HashTable::insert(Node data)
{
    cnt++;
    if (cnt > size)
    {
        tableDoubl();
    }

    int index = hashFun(data.key);
    Node* newNode = new Node(data);

    if (table[index] == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        Node* next = table[index]->next;
        table[index]->next = newNode;
        newNode->next = next;
    }
}

void HashTable::del(int key)
{
    int index = hashFun(key);
    Node* current = table[index],
        * prev = NULL;

    while (current != NULL && current->key != key)
    {
        prev = current;
        current = current->next;
    }


    if (current == NULL)
    {
        cout << "Data not found!\n\n";
        return;
    }
    else
    {
        if (prev == NULL)
        {
            table[index] = current->next;
        }

        else
        {
            prev->next = current->next;
        }
        delete current;
        current = 0;
    }

    cnt--;
    if (cnt < size / 4)
    {
        tableShrnk();
    }
}

string HashTable::search(int key)
{
    int index = hashFun(key);
    Node* current = table[index];

    while (current != NULL)
    {
        if (current->key == key)
            return current->val;
        current = current->next;
    }
    return "\nValue not FOund";
}

int HashTable::hashFun(int key)
{
    return key % 10;
}

void HashTable::tableDoubl()
{
    int mainSize = size;
    size *= 2;
    hashAgain(mainSize);
}

void HashTable::tableShrnk()
{
    int size_orig = size;
    size /= 2;
    hashAgain(size_orig);
}

void HashTable::hashAgain(int size_orig)
{
    Node** newtable = new Node * [size];
    for (int i = 0; i < size; i++)
    {
        newtable[i] = 0;
    }

    for (int i = 0; i < size_orig; i++)
    {

        Node* current = table[i],
            * prev = NULL;

        while (current != NULL)
        {
            prev = current->next;

            int index = hashFun(current->key);


            if (newtable[index] == NULL)
            {
                newtable[index] = current;
                newtable[index]->next = 0;
            }
            else
            {
                Node* next = newtable[index]->next;
                newtable[index]->next = current;
                current->next = next;
            }
            current = prev;
        }
    }
    delete[] table;
    this->table = newtable;
}


void HashTable::printTable()
{
    for (int i = 0; i < size; i++)
    {
        cout << "index " << i << " ==>";
        Node* current = table[i];
        while (current != NULL)
        {
            cout << " [ " << current->key << "," << current->val << " ] ";
            current = current->next;
        }
        cout << endl;
    }
    cout << endl;
}
