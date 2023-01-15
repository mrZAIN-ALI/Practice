#pragma once
#include<iostream>
using namespace std;
class BstNode
{
	int data;
	
	BstNode* left,
		* right,
		* parent;

public:
	BstNode(int val) :data(val), left(nullptr), right(nullptr), parent(nullptr) {};
	BstNode() :data(0), left(nullptr), right(nullptr), parent(nullptr) {};

	void setLeft(BstNode* l) { left = l; }
	BstNode* getleft() { return left; }

	void setRight(BstNode* r) { right = r; }
	BstNode* getRight() { return right; }

	void setParent(BstNode* p) { parent = p; }
	BstNode* getParent() { return parent; }

	void setData(int val) { data = val; }
	int getData() { return data; }
	friend class BstTree;
};
class BstTree
{
	BstNode* root;
public:
	void setRoot(BstNode* r) { root = r; }
	BstNode* getRoot() { return root; }
	BstTree() { root = nullptr; }

	BstNode* insert(BstNode*, int);
	BstNode* findMinVal(BstNode*);
	BstNode* finMaxVal(BstNode*);
	BstNode* search(BstNode*, int);
	BstNode* remove(BstNode*, int);
	void DecendingDisplay(BstNode*);
	void LevelOrderTraversal(BstNode*);
	int height(BstNode*);
	int getBalanceFactor(BstNode*);
	void identifyRoatation(BstNode*);

};
