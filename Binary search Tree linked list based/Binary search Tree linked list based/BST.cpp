#include"BST.h"
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
BST::BST()
{
	root = nullptr;
	size = 0;
	heighT = 0;
	deptH = 0;

}
bool BST::isParent(Node* rot)
{
	return (rot->getLeft() != nullptr || rot->getRight() != nullptr);
}
bool BST::isExternal(Node* rot)
{
	return (rot->getLeft() == nullptr && rot->getRight() == nullptr);
}
bool BST::isInternal(Node* rot)
{
	return isParent(rot);
}
void BST::levelOrderDisplay(Node* rot)
{
	if (rot==nullptr)
	{
		return;
	}
	else
	{
		queue<Node*> q;

		q.push(rot);

		while (!q.empty())
		{
			Node* currentTop = q.front();
			q.pop();
	

			cout << currentTop->getData() ;
			
			if (currentTop->getLeft()!=nullptr)
			{
				q.push(currentTop->getLeft());
			}
			if (currentTop->getRight()!=nullptr)
			{
				q.push(currentTop->getRight());
			}
		}
	}
}
Node* BST::getMin(Node* rot)
{
	if (rot==nullptr)
	{
		return nullptr;
	}
	else if (rot->getLeft() == nullptr)
	{
		return rot;
	}
	return getMin(rot->getLeft());
}
Node* BST::getMax(Node* rot)
{
	if (rot == nullptr)
	{
		return nullptr;
	}
	else if (rot->getRight() == nullptr)
	{
		return rot;
	}
	return getMax(rot->getRight());
}
void BST::inOrder(Node* rot)
{
	if (rot==nullptr)
	{
		return;
	}

	inOrder(rot->getLeft());
	cout << rot->getData()<<" ";
	inOrder(rot->getRight());

}
void BST::postOrder(Node* rot)
{
	if (rot == nullptr)
	{
		return;
	}

	inOrder(rot->getLeft());
	inOrder(rot->getRight());
	cout << rot->getData() << " ";
}
void BST::preOrder(Node* rot)
{
	if (rot == nullptr)
	{
		return;
	}

	cout << rot->getData() << " ";
	inOrder(rot->getLeft());
	inOrder(rot->getRight());
}
int BST::height(Node* rot)
{
	int heigh=0,
		leftH = 0,
		rightH = 0,
		mH=0;
	if (rot==nullptr)
	{
		return heigh;
	}
	else
	{
		leftH = height(rot->getLeft());
		rightH = height(rot->getRight());
		
		mH = max(leftH, rightH);
		heigh = mH + 1;
	}
	return heigh;
}
Node* BST::insert(Node* rot,int val)
{
	if (rot==nullptr)
	{
		Node* newNode = new Node(val);
		rot = newNode;

		return rot;
	}

	if (rot->getData()>val)
	{
		rot->setLeft(insert(rot->getLeft(),val));
	}
	else if (rot->getData() < val)
	{
		rot->setRight(insert(rot->getRight(),val));
	}
	return rot;
}
Node* BST::search(Node* rot, int key)
{
	Node* returnNode = nullptr;
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
		search(rot->getLeft(), key);
	}
	else
	{

		search(rot->getRight(), key);
	}



}
Node* BST::Delete(Node* node, int key)
{
	Node* temp;
	if (!(search(getRoot(), key)))
	{
		cout << "value not exixt\n\n";
		return NULL;
	}
	int cpVal = key - node->getData();

	if (cpVal < 0)
	{
		temp = Delete(node->getLeft(), key);
		node->setLeft(temp);
		if (temp != NULL)
			temp->setParent(node);
	}
	else if (cpVal > 0)
	{
		temp = Delete(node->getRight(), key);
		node->setRight( temp );
		if (temp != NULL)
			temp->setParent(node);
	}

	else if (node->left != NULL && node->right != NULL)
	{
		Node* min_Node;

		min_Node = getMin(node->getRight());
		node->data = min_Node->getData();
		temp = Delete(node->getRight(), min_Node->getData());
		node->right = temp;
		if (temp != NULL)
			temp->setParent(node);
	}
	else
	{
		Node* deleteIt = node;
		if (node->getLeft() == nullptr)
		{
			node = node->getRight();
		}
		else if (node->getRight() == nullptr)
		{
			node = node->getLeft();
		}
		else
		{
			node = nullptr;
		}
		delete deleteIt;
	}
	return node;
}
void BST::horizontalDisplay(Node* rot,int wid)
{
	if (rot == nullptr)
	{
		return;
	}
	wid += width;
	horizontalDisplay(rot->getRight(), wid); 
	
	cout << endl;
	for (int i = width; i < wid; i++)
	{
		cout << " ";
	}
	cout << rot->getData() << "\n";

	horizontalDisplay(rot->getLeft(), wid);
}