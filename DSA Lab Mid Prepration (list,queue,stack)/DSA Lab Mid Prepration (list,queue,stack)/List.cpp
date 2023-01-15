#include"List.h"
#include<iostream>
using namespace std;
bool List::isEmpt()
{
	return head == nullptr;
}
List::List()
{
	head = nullptr;
	last = nullptr;
}
Node* List::insert(int val)
{
	Node* neweNode = new Node(val);
	if (isEmpt())
	{
		head = neweNode;
		last = neweNode;

	}
	else
	{
		Node* temp= head;
		head = neweNode;
		neweNode->next = temp;
	}
	return neweNode;
}
void List::delete_Last()
{
	if (isEmpt())
	{
		return ;
	}
	Node* traversonNOde = head,
	
		*temp_ptr=nullptr;
	while (traversonNOde->next)
	{
		temp_ptr = traversonNOde;
		traversonNOde = traversonNOde->next;
	}
	if (temp_ptr ==head)
	{
		head = nullptr;
		last = nullptr;
		return ;
	}
	temp_ptr->next = nullptr;
	last = temp_ptr;
	temp_ptr = last;
	delete traversonNOde;
	return;
}
void List::display()
{
	if (isEmpt())
	{
		cout << "list is Empty nothing to show\n";
		return;
	}
	Node* traversingNode = head;
	while (traversingNode)
	{
		cout << traversingNode->getData() << " ";
		traversingNode = traversingNode->getNext();
	}
	cout << endl;
}
bool List::delete_By_val(int val)
{
	if (isEmpt())
	{
		return false;
	}

	Node* traversingNode = head,
		*prevNode=nullptr,
		*temp=nullptr;
	
	if (traversingNode->getData() == val)
	{
		temp = head;
		head = temp->next;
		prevNode = temp;
		delete temp;
		return true;
	}

	while (traversingNode)
	{
		if (traversingNode->getData() == val) {
			
			temp = traversingNode;
			prevNode->next = temp->getNext();
			delete traversingNode;
			return true;
		}
		prevNode = traversingNode;
		traversingNode = traversingNode->getNext();
	}
	return false;
}