#pragma once
class BST
{
	const int MaxSize = 2000;
	int* nodes;

public:
	BST();
	int* getRoot() { return nodes; }
	int getLeftIndexVal(int nodeIndex) { return (2 * nodeIndex); }
	int getRighIndexVal(int nodeIndex) { return ((2 * nodeIndex) + 1); }
	int getPaerntIndexVal(int nodeIndex){ return (nodeIndex / 2) - 1; }
	bool isLeaf(int);
	bool addRootNodeVal(int);
	bool addVal(int val);  
	void inOreder(int);
	void preOreder(int);
	bool search(int);
};