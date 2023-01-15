#include"DLinkdedList.h"
#include<iostream>
using namespace std;
Dlist::Dlist()
{
	front = back = nullptr;
	/*front = new Dnode;
	back = new Dnode;*/
}
void Dlist::insertAtLast(int val)
{
	Dnode* newNode = new Dnode(val);
	if (isEmpty())
	{
		front = newNode;
		back = newNode;
	}
	else
	{
		back->next = newNode;
		newNode->prev = back;
		back = newNode;
	}
}
void Dlist::deletFront()
{
	Dnode* tempNode = front;
	if (isEmpty())
	{
		cout << "List is empty\n";
		return;
	}
	if (front==back)
	{
		tempNode = front;
		front = back = nullptr;
		delete tempNode;
	
	}
	else
	{

		front = front->next;
		tempNode->next->prev = front;
		delete tempNode;
	}
}
void Dlist::display()
{
	if (isEmpty())
	{
		cout << "List is empty\n";
		return;
	}
	Dnode* traversinNode = front;
	while (traversinNode)
	{
		cout << traversinNode->val << " ";
		traversinNode = traversinNode->next;
	}
	cout << endl;
}
void Dlist::deleteByVal(int val)
{
	Dnode* traversing_Node = nullptr;
	Dnode* previous_Node = nullptr;

	if (!front)
	{
		return;
	}
	else
	{
		if (front->val == val)
		{
			traversing_Node = front->next;
			delete front;
			front = traversing_Node;
		}
		else
		{

			traversing_Node = front;
			previous_Node = nullptr;
			while (traversing_Node != nullptr && traversing_Node->val != val)
			{
				previous_Node = traversing_Node;
				traversing_Node = traversing_Node->next;
			}

			if (traversing_Node)
			{
				previous_Node->next = traversing_Node->next;
				delete traversing_Node;
			}

		}

	}
}