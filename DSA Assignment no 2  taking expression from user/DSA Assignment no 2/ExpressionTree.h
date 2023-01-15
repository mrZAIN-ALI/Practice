#pragma once
#include<string>
#include<time.h>
#include<iostream>
#include<cstdlib>
using namespace std;
class Node
{

	char variable;
	int data;

	Node* left,
		* right,
		* parent;
public:
	Node(char var = ' ') :variable(var), data(0)
		, left(nullptr), right(nullptr), parent(nullptr) {};

	void setLeft(Node* l) { left = l; }
	void setRifht(Node* r) { right = r; }
	void setParent(Node* p) { parent = p; }
	void setVar(char v) { variable = v; }
	void setData(int d) { data = d; }

	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	Node* getParen() { return parent; }
	int getData() { return data; }
	char getVariable() { return variable; }

};
class ExpresTree
{

	Node* root;
	string givenExpress;
	int width=10;
public:

	ExpresTree(string =" ");
	Node* inFixToExpressTree(string);
	void display(Node*, int wid = 0);
	void valueAssignedDisplay(Node*, int wid = 0);
	void dispAfterExecution(Node*, int wid = 0);
	string inFixToPostFix(string);
	int evaluate(Node*);
	void randomlyAssignVal(Node*);
	int getRand(int max = 30, int min = 0);

	void setNewExpr(string exp) { givenExpress = exp; }
	string getGivenExp() { return givenExpress; }
	void setRoot(Node* r) { root = r; }
	Node* getRoot() { return root; }
	void preOrder(Node* rot);
	void postOrder(Node* rot);
	void inOrder(Node* rot);
};