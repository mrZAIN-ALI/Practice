#include"Queue.h"
#include<iostream>
using namespace std;
void Queue::enQueue(int val)
{
	QNode *newNode = new QNode(val);
	if (isEmpt())
	{
		last = newNode;
		head = newNode;
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}
	
}
void Queue::deQueue()
{
	if (isEmpt())
	{
		cout << "Queu is empty\n";
	}
	else
	{
		QNode* tempNOde = head;
		head = head->getNext();
		delete tempNOde;
	}
}
void Queue::display()
{
	if (isEmpt())
	{
		cout << "Queu is empty\n";
	}
	else
	{
		QNode* traversingNode = head;
		while (traversingNode)
		{
			cout << traversingNode->data<<" ";
			traversingNode = traversingNode->getNext();
		}
		cout << endl;
	}
}
QNode *Queue::front()
{
	return head;
}