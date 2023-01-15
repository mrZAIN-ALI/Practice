#pragma once
class Node
{
public:
    int data;
    Node* next;
    int getVal() { return data; }
    Node* getNext() { return next; }
    Node(int val) { data = val, next = nullptr; }

};
class LinkedList
{
    Node* tail;
    Node* head;
public:
    Node* getHead() { return head; }
    void setHead(Node* h) { head = h; }
    LinkedList() { head = nullptr, tail = nullptr; }
    bool isEmpty();

    Node* insertAtTail(Node* , int );
    void display(Node*);
    bool search(Node* , int );
    int findGreatest(Node*);

};