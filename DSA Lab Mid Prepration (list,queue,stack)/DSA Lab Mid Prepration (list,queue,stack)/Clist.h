#pragma once
class Cnode
{
	int val;
	Cnode* next;
	Cnode* prev;
	Cnode(int va) { val = va, next = prev = nullptr; }
	Cnode() { val = 0, next = prev = nullptr; }
	friend class Clist;
};
class Clist
{
	Cnode* front;
	Cnode* back;
public:
	Cnode* getFront() { return front; }
	Cnode* getBack() { return back; }
	bool isEmpty() { return front == nullptr; }
	Clist();
	void insertAtLast(int);
	void deletFront();
	void deleteByVal(int);
	void display();
};