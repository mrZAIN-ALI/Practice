#pragma once
class Node
{
	int data;
	Node* parent,
		* left,
		* right;
public:
	Node() { data = 0, left = right = parent = nullptr; }
	Node(int val) { data = val, left = right = parent = nullptr; }

	Node* getParent() { return parent; }
	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	int getData() { return data; }

	void setData(int d) { data = d; }
	void setParent(Node* p) { parent = p; }
	void setLeft(Node* l) { left = l; }
	void setRight(Node* r) { right = r; }
	friend class BST;
};
class BST
{

	Node* root;
	int deptH,
		heighT,
		size;
	int width = 10;
public:
	BST();
	bool isParent(Node*);
	bool isExternal(Node*);
	bool isInternal(Node*);

	void setRoot(Node* r) { root = r; }
	Node* getRoot() { return root; }
	int getSize() { return size; }

	int incrementSize() { return size++; }

	void levelOrderDisplay(Node*);
	Node* getMin(Node*);
	Node* getMax(Node*);
	
	void horizontalDisplay(Node*, int wid=0);
	void inOrder(Node*);
	void postOrder(Node*);
	void preOrder(Node*);
	
	int height(Node*);
	int depth(Node*);
	Node* insert(Node*,int);
	Node* Delete(Node*, int);
	Node* search(Node*,int);
};