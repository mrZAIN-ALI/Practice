#include<iostream>
#include"Stack.h"
using namespace std;
Node_* Stack::push(int val)
{
	Node_* newNode = new Node_(val);
	if (isEmpt())
	{
		head = newNode;
	}
	else
	{
		Node_* temp=head;
		head = newNode;
		head->next = temp;
	}

	return newNode;
}
void Stack::pop()
{
	if (isEmpt())
	{
		cout << "stack is Emplty\n";
	}
	else
	{
		Node_* temp = head;
		head = head->next;
		delete temp;
	}
}
Node_* Stack::top()
{
	if (isEmpt())
	{
		cout << "stack is Emplty\n";
		return nullptr;
	}
	else
	{
		Node_* temp = head;
		return temp;
	}
}
void Stack::display()
{
	if (isEmpt())
	{
		cout << "stack is Emplty\n";
		return ;
	}
	Node_* traversingNode = head;
	while (traversingNode)
	{
		cout << traversingNode->data << " ";
		traversingNode = traversingNode->getNext();
	}
	cout << endl;
}