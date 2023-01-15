#pragma once
class QNode
{
	int data;
	QNode* next;
public:
	QNode* getNext() { return next; }
	QNode(int val) { data = val, next = nullptr; }
	int getData() { return data; }
	friend class Queue;
};
class Queue
{
	QNode* head,
		* last;
public:
	Queue() { head = last = nullptr; }
	bool isEmpt() { return (last == nullptr || head==nullptr); }
	QNode* getHead() { return head; }
	void setHead(QNode* h) { head = h; }
	QNode* getLast() { return last; }
	void setLast(QNode* l) { last = l; }
	
	void enQueue(int);
	void deQueue();
	QNode* front();
	void display();
};
