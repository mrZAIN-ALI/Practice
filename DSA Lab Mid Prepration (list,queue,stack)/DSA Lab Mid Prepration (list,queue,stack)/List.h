#pragma once
class Node
{
	int data;
	Node* next;
public:
	Node* getNext() { return next; }
	Node(int val) { data = val,next=nullptr; }
	int getData() { return data; }
	friend class List;
};
class List
{
	Node* head,
		* last;
public:
	List();
	bool isEmpt();
	Node* getHead() { return head; }
	void setHead(Node* h) { head = h; }
	Node* getLast() { return last; }
	void setLast(Node* l) { last = l; }
	Node* insert(int);
	void delete_Last();
	bool delete_By_val(int);
	void display();
};
