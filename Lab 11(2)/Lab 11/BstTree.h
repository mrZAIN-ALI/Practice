#pragma once
#include<iostream>
using namespace std;
class Node
{
	int data;
	
	Node* left,
		* right,
		* parent;

public:
	Node(int val) :data(val), left(nullptr), right(nullptr), parent(nullptr) {};
	Node() :data(0), left(nullptr), right(nullptr), parent(nullptr) {};

	void setLeft(Node* l) { left = l; }
	Node* getleft() { return left; }

	void setRight(Node* r) { right = r; }
	Node* getRight() { return right; }

	void setParent(Node* p) { parent = p; }
	Node* getParent() { return parent; }

	void setData(int val) { data = val; }
	int getData() { return data; }
	friend class BstTree;
};
class BstTree
{
	Node* root;
public:
	void setRoot(Node* r) { root = r; }
	Node* getRoot() { return root; }
	BstTree() { root = nullptr; }

	Node* insert(Node*, int);
	Node* findMinVal(Node*);
	Node* finMaxVal(Node*);
	Node* search(Node*, int);
	Node* remove(Node*, int);
	void DecendingDisplay(Node*);
	void LevelOrderTraversal(Node*);
	int height(Node*);
	int getBalanceFactor(Node*);
	void identifyRoatation(Node*);

};
