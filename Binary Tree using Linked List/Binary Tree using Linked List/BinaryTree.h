#include"TreeNode.h"
#pragma once
class BinaryTree
{
	TreeNode* rootNode;
public:
	void insertAtleft(TreeNode root, int val);
	void insertRight(TreeNode root, int val);
	bool del(int key);
	void setRoot(TreeNode* r) { rootNode = r; }
	TreeNode* getRootNode() { return rootNode; }
};