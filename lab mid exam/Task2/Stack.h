#pragma once
#include<iostream>
using namespace std;
class StackNode
{
	float data;
    char cData;
	StackNode* next;
public:
	StackNode* get_Next() { return next; }
	StackNode(float val,char c) { data = val,cData=c, next = nullptr; }
	float get_Data() { return data; }
	friend class Stack;
};
class Stack
{
	StackNode* head;
public:
	Stack() { head = nullptr; }
	bool is_Empty() { return head == nullptr; }
	StackNode* get_Head() { return head; }
	void set_Head(StackNode* h) { head = h; }
	StackNode* push(float,char);

	void pop();
	StackNode* top();
	void  display();
};
StackNode* Stack::push(float val,char c)
{
	StackNode* newStackNode = new StackNode(val,c);
	if (is_Empty())
	{
		head = newStackNode;
	}
	else
	{
		StackNode* temp=head;
		head = newStackNode;
		head->next = temp;
	}

	return newStackNode;
}
void Stack::pop()
{
	if (is_Empty())
	{
		cout << "stack is Emplty\n";
	}
	else
	{
		StackNode* temp = head;
		head = head->next;
		delete temp;
	}
}
StackNode* Stack::top()
{
	if (is_Empty())
	{
		cout << "stack is Emplty\n";
		return nullptr;
	}
	else
	{
		StackNode* temp = head;
		return temp;
	}
}
void Stack::display()
{
	if (is_Empty())
	{
		cout << "stack is Emplty\n";
		return ;
	}
	StackNode* traversingStackNode = head;
	while (traversingStackNode)
	{
		cout <<"Float valur you have entered is ==> "<< traversingStackNode->data << " |||| And Char value you have entered is ==>"<<traversingStackNode->cData<<" \n";
		traversingStackNode = traversingStackNode->get_Next();
	}
	cout << endl;
}