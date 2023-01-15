#pragma once
const int sizeOFArray=500;
class BinaryTree
{
	int nodes[sizeOFArray];
public:
	BinaryTree();
	bool isLeaf(int nodeIndex);
	int return_Index_Of_Parent(int nodeIndex);
	int return_Index_Of_LeftChild(int nodeIndex);
	int return_Index_Of_RightChild(int nodeIndex);
	bool addRootNode(int val);
	bool addLeftChlid(int val, int parentIndex);
	bool addRightChlid(int val, int parentIndex);

};
