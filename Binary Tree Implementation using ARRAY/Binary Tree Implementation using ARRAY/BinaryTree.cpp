#include"BinaryTree.h"
BinaryTree::BinaryTree()
{
	for (int i = 0; i < sizeOFArray; i++)
	{
		nodes[i] = -1;
	}
}
bool BinaryTree::isLeaf(int nodeIndex)
{
	if (nodeIndex>sizeOFArray||nodeIndex<0)
	{
		return -1;
	}
	else {

		return (nodes[return_Index_Of_LeftChild(nodeIndex)] == -1 &&
			nodes[return_Index_Of_RightChild(nodeIndex)] == -1);
	}
}
int BinaryTree::return_Index_Of_Parent(int nodeIndex)
{
	if (nodeIndex > sizeOFArray || nodeIndex < 0)
	{
		return -1;
	}
	else {

		return ((nodeIndex - 1) / 2);
	}
}
int BinaryTree::return_Index_Of_LeftChild(int nodeIndex)
{
	if (nodeIndex > sizeOFArray || nodeIndex < 0)
	{
		return -1;
	}
	else {

		return ((nodeIndex * 2) + 1);
	}
}
int BinaryTree::return_Index_Of_RightChild(int nodeIndex)
{
	if (nodeIndex > sizeOFArray || nodeIndex < 0)
	{
		return -1;
	}
	else {

		return ((nodeIndex * 2) + 2);
	}
}
bool BinaryTree::addRootNode(int val)
{
	nodes[0] = val;
	return true;
}
bool BinaryTree::addLeftChlid(int val, int parentIndex)
{
	if (parentIndex > sizeOFArray || parentIndex < 0)
	{
		return false;
	}
	else {

		int index = return_Index_Of_LeftChild(parentIndex);

		nodes[index] = val;
		return true;
	}
}

bool BinaryTree::addRightChlid(int val, int parentIndex)
{
	if (parentIndex > sizeOFArray || parentIndex < 0)
	{
		return false;
	}
	else {

		int index = return_Index_Of_RightChild(parentIndex);

		nodes[index] = val;
		return true;
	}
}

