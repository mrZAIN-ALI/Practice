#include"BstTree.h"
#include<queue>
#include<iostream>
using namespace std;
BstNode* BstTree::insert(BstNode* rot, int val)
{

	BstNode* newNode = new BstNode(val);
	if (rot == nullptr)
	{
		rot = newNode;
		return newNode;
	}
	else if (val > rot->getData())
	{
		rot->setRight(insert(rot->getRight(), val));
	}
	else if (val < rot->getData())
	{
		rot->setLeft(insert(rot->getleft(), val));
	}
	else
	{
		cout << "NO duplicate values are allowed\n";
	}
	return rot;
}
BstNode* BstTree::findMinVal(BstNode* rot)
{
	if (rot == nullptr)
	{
		return nullptr;
	}
	if (rot->getleft() == nullptr)
	{
		return rot;
	}
	return findMinVal(rot->left);
}

BstNode* BstTree::finMaxVal(BstNode* rot)
{
	if (rot == nullptr)
	{
		return nullptr;
	}
	if (rot->getRight() == nullptr)
	{
		return rot;
	}
	return finMaxVal(rot->getRight());
}

BstNode* BstTree::search(BstNode* rot, int key)
{
	BstNode* returnNode = nullptr;
	if (rot == nullptr)
	{
		return nullptr;
	}
	else if (rot->getData() == key)
	{
		return rot;
	}

	if (rot->getData() > key)
	{
		search(rot->getleft(), key);
	}
	else
	{

		search(rot->getRight(), key);
	}



}

BstNode* BstTree::remove(BstNode* node, int key)
{
	BstNode* temp;
	if (!(search(getRoot(), key)))
	{
		cout << "value not exixt\n\n";
		return NULL;
	}
	int cpVal = key - node->getData();

	if (cpVal < 0)
	{
		temp = remove(node->getleft(), key);
		node->setLeft(temp);
		if (temp != NULL)
			temp->parent = node;
	}
	else if (cpVal > 0)
	{
		temp = remove(node->getRight(), key);
		node->right = temp;
		if (temp != NULL)
			temp->setParent(node);
	}

	else if (node->left != NULL && node->right != NULL)
	{
		BstNode* min_Node;

		min_Node = findMinVal(node->getRight());
		node->data = min_Node->getData();
		temp = remove(node->getRight(), min_Node->getData());
		node->right = temp;
		if (temp != NULL)
			temp->setParent(node);
	}
	else
	{
		BstNode* deleteIt = node;
		if (node->getleft() == nullptr)
		{
			node = node->getRight();
		}
		else if (node->getRight() == nullptr)
		{
			node = node->getleft();
		}
		else
		{
			node = nullptr;
		}
		delete deleteIt;
	}
	return node;
}
void BstTree::DecendingDisplay(BstNode* rot)
{
	if (rot != nullptr)
	{
		DecendingDisplay(rot->getRight());
		cout << rot->getData() << " ";
		DecendingDisplay(rot->getleft());
	}

}
void BstTree::LevelOrderTraversal(BstNode* rot)
{
	if (rot == nullptr)
	{
		return;
	}

	queue<BstNode*> queue;
	queue.push(rot);

	while (!queue.empty())
	{

		BstNode* currentNode = queue.front();
		queue.pop();

		cout << currentNode->getData() << " ";
		if (currentNode->getleft() != nullptr)
		{
			queue.push(currentNode->getleft());
		}
		if (currentNode->getRight() != nullptr)
		{
			queue.push(currentNode->getRight());
		}
	}
}
int BstTree::height(BstNode* r)
{
	if (r == NULL)
		return -1;
	else {

		int lheight = height(r->left);
		int rheight = height(r->right);


		if (lheight > rheight)
			return (lheight + 1);
		else return (rheight + 1);
	}
}
int BstTree::getBalanceFactor(BstNode* n)
{

	int lHeight = height(n->left);

	int rHeight = height(n->right);

	int bFactor = lHeight - rHeight;

	return bFactor;
}
void BstTree::identifyRoatation(BstNode* r)
{
	if (r == NULL)
	{

		//cout << "successfully" << endl;
		return;
	}

	if (r->getleft())
	{
		identifyRoatation(r->getleft());
	}
	if (r->getRight())
	{
		identifyRoatation(r->getRight());

	}


	int bFactor = getBalanceFactor(r);
	cout << "BF is : " << bFactor << " Of nod " << r->getData() << endl;

	if (bFactor == 2 && r->getRight() == nullptr)
	{
		cout << "First Left Rotate then Right Rotate\n";
		return;
	}
	if (bFactor == -2 && r->getleft() == nullptr)
	{
		cout << "First right Rotate then left Rotate\n";
		return;

	}
	if (bFactor > 1)
		cout << "Right rotate\n";
	if (bFactor < -1)
		cout << "Left rotate\n";


}