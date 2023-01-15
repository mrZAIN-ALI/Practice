#include"Clist.h"
#include<iostream>
using namespace std;
Clist::Clist()
{
	front = back = nullptr;
	/*front = new Dnode;
	back = new Dnode;*/
}
void Clist::insertAtLast(int val)
{
	Cnode* newNode = new Cnode(val);
	if (isEmpty())
	{
		front = newNode;
		back = newNode;
		back->next = front;
	}
	else
	{
		back->next = newNode;
		newNode->prev = back;
		back = newNode;
		back->next = front;
	}
}
void Clist::deletFront()
{
	Cnode* tempNode = front;
	if (isEmpty())
	{
		cout << "List is empty\n";
		return;
	}
	if (front == back)
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
		back->next = front;
	}
}
void Clist::display()
{
	if (isEmpty())
	{
		cout << "List is empty\n";
		return;
	}
	Cnode* traversinNode = front;
	
		cout << traversinNode->val << " ";
	do
	{
		traversinNode = traversinNode->next;
		cout << traversinNode->val << " ";

	} while (traversinNode != back);
	cout << endl;
}
void Clist::deleteByVal(int val)
{
	Cnode* traversing_Node = nullptr;
	Cnode* previous_Node = nullptr;

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
			back->next = front;
		}
		else
		{

			traversing_Node = front;
			previous_Node = nullptr;
			do
			{
				previous_Node = traversing_Node;
				traversing_Node = traversing_Node->next;

			} while (traversing_Node != back && traversing_Node->val != val);

			if (traversing_Node)
			{
				previous_Node->next = traversing_Node->next;
				delete traversing_Node;
				back = previous_Node;
				back->next = front;
			}

		}

	}
}