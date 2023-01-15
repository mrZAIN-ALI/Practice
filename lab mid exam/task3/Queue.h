#pragma once
#include<iostream>
using namespace std;
class QNode
{
	int data;
	QNode* next;
public:
	QNode* getNext() { return next; }
	QNode(int val) { data = val, next = nullptr; }
	int getData() { return data; }
	void setData(int va) { data = va; }
	friend class Queue;
};
class Queue
{
	QNode* head,
		* last;
	int lenth=0;
public:
	Queue() { head = last = nullptr; }
	bool isEmpty() { return (last == nullptr || head == nullptr); }
	QNode* getHead() { return head; }
	void setHead(QNode* h) { head = h; }
	QNode* getLast() { return last; }
	void setLast(QNode* l) { last = l; }

	void enQueue(int);
	void deQueue();
	QNode* front();
	void display();
	void sort(QNode*);
};
void Queue::sort(QNode* headPtr)
{
	if (headPtr == nullptr)
	{
		return;
	}

	QNode* currentNode = headPtr;
	QNode* nextTOCurrentNode = headPtr->getNext();

	if (nextTOCurrentNode != nullptr)
	{
		
		if (currentNode->getData() > nextTOCurrentNode->getData())
		{
			int temp = currentNode->getData();
			currentNode->setData(nextTOCurrentNode->getData());
			nextTOCurrentNode->setData(temp);
		}
	
	}

		sort(headPtr->getNext());



}

void Queue::enQueue(int val)
{

	QNode* newNode = new QNode(val);
	if (isEmpty())
	{
		last = newNode;
		head = newNode;
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}
	lenth++;
	for (int i = 0; i < lenth; i++)
	{
		sort(head);

	}

	
}
void Queue::deQueue()
{
	if (isEmpty())
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
	if (isEmpty())
	{
		cout << "Queu is empty\n";
	}
	else
	{
		QNode* traversingNode = head;
		while (traversingNode)
		{
			cout << traversingNode->getData() << " ";
			traversingNode = traversingNode->getNext();
		}
		cout << endl;
	}
}
QNode* Queue::front()
{
	return head;
}