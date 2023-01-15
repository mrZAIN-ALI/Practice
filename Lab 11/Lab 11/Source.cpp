#include<iostream>
#include"BstTree.h"
using namespace std;
int main()
{
	//Creating Tree
	BstTree tree;
	tree.setRoot(tree.insert(tree.getRoot(), 8));
	tree.insert(tree.getRoot(), 3);
	tree.insert(tree.getRoot(), 10);
	tree.insert(tree.getRoot(), 1);
	tree.insert(tree.getRoot(), 6);
	tree.insert(tree.getRoot(), 14);
	tree.insert(tree.getRoot(), 4);
	tree.insert(tree.getRoot(), 7);
	tree.insert(tree.getRoot(), 13);
	tree.insert(tree.getRoot(), 37);

	//problem 1
	cout << "Finding Min And Max Value\n";
	cout << "Minumum Value is : " << (tree.findMinVal(tree.getRoot()))->getData() << endl << endl;
	cout << "Maximum Value is : " << (tree.finMaxVal(tree.getRoot()))->getData() << endl << endl;


	//problem 2
	cout << "Deleteing 13 in tree : \n";
	tree.remove(tree.getRoot(), 13);

	
	//problem 3
	cout << "Printing Tree Data in Decending Order\n\n";
	tree.DecendingDisplay(tree.getRoot());
	cout << endl << endl;
	
	//problem 4
	cout << "Now Shwowing Level Order Traversal\n";
	tree.LevelOrderTraversal(tree.getRoot());
	cout << endl;
	
	
	//problem 5
	cout << "Now identifying Rotations in Tree\n";
	tree.identifyRoatation(tree.getRoot());
	return 0;

}