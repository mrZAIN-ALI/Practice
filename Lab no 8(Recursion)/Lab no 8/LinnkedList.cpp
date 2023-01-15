#include"LinkedList.h"
#include<iostream>
using namespace std;
bool LinkedList::isEmpty()
{
    return head == nullptr;
}

Node* LinkedList::insertAtTail(Node* headPtr, int val )
{
    if (headPtr == nullptr) {
        Node* newnode = new Node(val);
        return newnode;
    }
    else {
        headPtr->next = insertAtTail(headPtr->next, val);
    }
    return headPtr;

}
void LinkedList::display(Node* headPtr)
{
    if (!headPtr)
    {
        return;
    }
    display(headPtr->getNext());
    cout << headPtr->getVal() << " ";

}
bool LinkedList::search(Node* headPtr, int val)
{
    if (headPtr == nullptr)
    {
        return false;
    }


    if (headPtr->getVal() == val)
    {
        return true;
    }

    return search(headPtr->getNext(), val);
}
int LinkedList::findGreatest(Node* headPtr)
{
    
    
        int x = 0;
        if (headPtr == nullptr)
            return -1;
        else
        {
            x = findGreatest(headPtr->next);
            if (x > headPtr->data)
                return x;
            else
                return headPtr->data;
        }
    
    
}
