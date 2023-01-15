#include"TreeNode.h"
TreeNode::TreeNode()
{
	Parent = left = right = nullptr;
	Data = 0;
}
TreeNode::TreeNode(int val)
{
	Parent = left = right = nullptr;
	Data = val;
}
int TreeNode::getData()
{
	return Data;
}
void TreeNode::setData(int val)
{
	Data = val;
}
TreeNode* TreeNode::getLeft() { return left; }
TreeNode* TreeNode::getRight() { return right; }
TreeNode* TreeNode::getParen() { return Parent; }

void TreeNode::setLeft(TreeNode* leftnode) { left = leftnode; }
void TreeNode::setRight(TreeNode* rightnode) { right = rightnode; }
void TreeNode::setParen(TreeNode* parentNode) { Parent = parentNode; }