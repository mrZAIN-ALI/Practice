#pragma once
class TreeNode
{
	int Data;
	TreeNode* Parent,
		* left,
		* right;
public:
	TreeNode();
	TreeNode(int val);
	int getData();
	void setData(int val);
	TreeNode* getLeft();
	TreeNode* getRight();
	TreeNode* getParen();

	void setLeft(TreeNode* leftnode);
	void setRight(TreeNode* rightnode);
	void setParen(TreeNode* parentNode);

	int isLeaf() { return (left == nullptr && right == nullptr); }
};