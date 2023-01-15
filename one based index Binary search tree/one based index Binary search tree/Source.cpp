#include"BST.h"
#include<iostream>
using namespace std;
int main()
{
	BST bst;

	bst.addVal(4);
	bst.addVal(5);
	bst.addVal(6);
	bst.addVal(1);
	bst.addVal(7);
	bst.addVal(2);
	bst.addVal(10);
	bst.addVal(3);
	bst.addVal(8);

	bst.inOreder(1);
	cout << endl;
	bst.preOreder(1);
	cout << endl;
	
	cout << bst.search(10);

	return 0;
}