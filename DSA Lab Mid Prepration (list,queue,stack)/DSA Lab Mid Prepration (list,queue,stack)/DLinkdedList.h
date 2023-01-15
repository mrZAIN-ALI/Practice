#pragma once
class Dnode
{
	int val;
	Dnode* next;
	Dnode* prev;
	Dnode(int va){ val = va, next = prev = nullptr; }
	Dnode() { val = 0, next = prev = nullptr; }
	friend class Dlist;
};
class Dlist
{
	Dnode* front;
	Dnode* back;
public:
	Dnode* getFront() { return front; }
	Dnode* getBack() { return back; }
	bool isEmpty() { return front == nullptr; }
	Dlist();
	void insertAtLast(int);
	void deletFront();
	void deleteByVal(int);
	void display();
};