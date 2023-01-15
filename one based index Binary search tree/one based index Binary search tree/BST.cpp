#include"BST.h"
#include<iostream>
using namespace std;
BST::BST()
{
	nodes = new int[MaxSize];
	for (int i = 0; i < MaxSize; i++)
	{
		nodes[i] = -1;
	}
}
bool BST::isLeaf(int nodeIndex)
{
	return ((nodes[getLeftIndexVal(nodeIndex)] == -1) && nodes[getRighIndexVal(nodeIndex)]);
}bool BST::addRootNodeVal(int val)
{
	nodes[1] = val;
	return true;
}
bool BST::addVal(int val)
{
	int targetNode = 1, ind=1;
	if (nodes[1]== (-1))
	{
		nodes[1] = val;
		return true;
	}
	else
	{
		while (nodes[ind]!= (-1))
		{
			if (nodes[ind]>val)
			{
				targetNode = getLeftIndexVal(ind);
				ind = targetNode;
				
			}
			else if(nodes[ind]<val)
			{
				targetNode = getRighIndexVal(ind);
				ind = targetNode;

			}
			
		}
		nodes[targetNode] = val;
		return true;
	
	

	}
	
	return false;
}
void BST::inOreder(int index)
{
	if (nodes[index]==(-1))
	{
		return;
	}
	else
	{
		inOreder(getLeftIndexVal(index));
		cout << nodes[index]<<" ";
		inOreder(getRighIndexVal(index));
	}
}
void BST::preOreder(int index)
{
	if (nodes[index] == (-1))
	{
		return;
	}
	else
	{
		cout << nodes[index] << " ";
		preOreder(getLeftIndexVal(index));
		preOreder(getRighIndexVal(index));
	}
}
bool BST::search(int key)
{
	int targetNode = 1, ind = 1;
	if (nodes[1] == (key))
	{
		return true;
	}
	else
	{
		while (nodes[ind] != (-1))
		{
			if (nodes[ind] > key)
			{
				targetNode = getLeftIndexVal(ind);
				ind = targetNode;

			}
			else if (nodes[ind] < key)
			{
				targetNode = getRighIndexVal(ind);
				ind = targetNode;

			}

			if (key == nodes[targetNode])
			{
				return true;
			}
		}


	}

	return false;
}