#include<iostream>
#include"BST.h"
using namespace std;
int main()
{
	BST t;
	t.setRoot(t.insert(t.getRoot(), 5));
	t.setRoot(t.insert(t.getRoot(), 4));
	t.setRoot(t.insert(t.getRoot(), 3));
	t.setRoot(t.insert(t.getRoot(), 1));
	t.setRoot(t.insert(t.getRoot(), 6));
	t.setRoot(t.insert(t.getRoot(), 8));
	//t.inOrder(t.getRoot());
	t.horizontalDisplay(t.getRoot());
	t.levelOrderDisplay(t.getRoot());
	return 0;
}