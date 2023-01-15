#pragma once
class Node_
{
	int data;
	Node_* next;
public:
	Node_* getNext() { return next; }
	Node_(int val) { data = val, next = nullptr; }
	int getData() { return data; }
	friend class Stack;
};
class Stack
{
	Node_* head;
public:
	Stack() { head = nullptr; }
	bool isEmpt() { return head == nullptr; }
	Node_* getHead() { return head; }
	void setHead(Node_* h) { head = h; }
	Node_* push(int);
	void pop();
	Node_* top();
	void  display();
};
