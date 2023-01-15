#include"ExpressionTree.h"
#include<stack>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
using namespace std;
ExpresTree::ExpresTree(string s)
{
	givenExpress = s;
	root = nullptr;
	srand(time(0));
}
Node* ExpresTree::inFixToExpressTree(string s)
{
	string postFix = inFixToPostFix(s);
	stack<Node*> stack;
	Node* retRoot=nullptr;
	for (int i = 0; i < postFix.length(); i++)
	{
		if (postFix[i] >= 'a' && postFix[i] <= 'z')
		{
			Node* newNode = new Node(postFix[i]);
			stack.push(newNode);
		}
		else if ( postFix[i] == '+' || postFix[i] == '-' ||postFix[i] == '*' || postFix[i] == '/' || postFix[i] == '%' || postFix[i] == '^')
		{
			Node* newNode = new Node(postFix[i]);
			if (!stack.empty())
			{
				Node* left=nullptr, * right=nullptr;
				right = stack.top();
				stack.pop();
				if (!stack.empty())
				{
					left = stack.top();
					stack.pop();
				}

				newNode->setLeft(left);
				newNode->setRifht(right);
				stack.push(newNode);
			}
		}
	}
	return stack.top();

}
void ExpresTree::display(Node* rot, int wid)
{
	if (rot == nullptr)
	{
		return;
	}
	wid += width;
	display(rot->getRight(), wid);

	cout << endl;
	for (int i = width; i < wid; i++)
	{
		cout << " ";
	}
	cout<<"( " << rot->getVariable() <<" )" << "\n";

	display(rot->getLeft(), wid);
}

int presedence(char operend)
{
	if (operend == '^')
		return 3;
	else if (operend == '*' || operend == '/')
		return 2;
	else if (operend == '+' || operend == '-')
		return 1;
	else return -1;
}
string inFix_to_PostFix(const string& inFix)
{
	string postFix;
	stack<char> stack;

	for (int i = 0; i < inFix.length(); i++)
	{
		if (inFix[i] == '(')
		{
			stack.push(inFix[i]);
		}
		else if (inFix[i] == ')')
		{
			while (stack.top() != '(')
			{
				postFix += stack.top();
				stack.pop();
			}
			stack.pop();
		}
		else if (inFix[i] >= 'a' && inFix[i] <= 'z')
		{
			postFix += inFix[i];
		}
		else if (stack.empty())
		{
			stack.push(inFix[i]);
		}
		else if (!stack.empty() && presedence(inFix[i]) >= presedence(stack.top()))
		{
			stack.push(inFix[i]);
		}
		else if (!stack.empty() && presedence(inFix[i]) <= presedence(stack.top()))
		{
			while (!stack.empty() && presedence(inFix[i]) <= presedence(stack.top()))
			{

				postFix += stack.top();
				stack.pop();

			}
			stack.push(inFix[i]);
		}
	}
	while (!stack.empty())
	{
		postFix += stack.top();
		stack.pop();
	}

	return postFix;
}

string ExpresTree::inFixToPostFix(string s)
{
	return inFix_to_PostFix(s);
}

void ExpresTree::inOrder(Node* rot)
{
	if (rot == nullptr)
	{
		return;
	}

	inOrder(rot->getLeft());
	cout << rot->getVariable() << " ";
	inOrder(rot->getRight());

}
void ExpresTree::postOrder(Node* rot)
{
	if (rot == nullptr)
	{
		return;
	}

	postOrder(rot->getLeft());
	postOrder(rot->getRight());
	cout << rot->getVariable() << " ";
}
void ExpresTree::preOrder(Node* rot)
{
	if (rot == nullptr)
	{
		return;
	}

	cout << rot->getData() << " ";
	preOrder(rot->getLeft());
	preOrder(rot->getRight());
}
int ExpresTree::getRand(int max , int min )
{

	return (rand() % (max - min + 1) - min);
}
void ExpresTree::randomlyAssignVal(Node* rot)
{
	if(rot == nullptr)
	{
		return;
	}

	randomlyAssignVal(rot->getLeft());
	if (rot->getVariable()>= 'a'&& rot->getVariable()<='z')
	{
		rot->setData(getRand(10,0));
	}
	randomlyAssignVal(rot->getRight());
}

void ExpresTree::valueAssignedDisplay(Node* rot, int wid)
{
	if (rot == nullptr)
	{
		return;
	}
	wid += width;
	valueAssignedDisplay(rot->getRight(), wid);

	cout << endl;
	for (int i = width; i < wid; i++)
	{
		cout << " ";
	}
	if (rot->getVariable() >= 'a' && rot->getVariable() <= 'z')
	{		
		cout << "( " << rot->getVariable()<<" = " << rot->getData() << " )" << "\n";
	}
	else
	{
		cout << "( " << rot->getVariable() << " )" << "\n";

	}

	valueAssignedDisplay(rot->getLeft(), wid);
}
int ExpresTree::evaluate(Node* rot)
{
	if (rot==nullptr)
	{
		return 0;
	}

	if (!rot->getLeft() && !rot->getRight())
	{
		
		return rot->getData();
	}
	int retVal=0;
	int left = evaluate(rot->getLeft());
	int right= evaluate(rot->getRight());

	if (rot->getVariable() == '+')
	{
		retVal = left + right;
		rot->setData(retVal);		
		return retVal;
	}
	else if (rot->getVariable() == '-')
	{
		retVal = left - right;
		rot->setData(retVal);
		return retVal;
	}
	else if (rot->getVariable() == '*')
	{
		retVal = left * right;
		rot->setData(retVal);
		return retVal;
	}
	else if (rot->getVariable() == '/')
	{
		retVal = left / right;
		rot->setData(retVal);
		return retVal;
	}
	else if (rot->getVariable() == '^')
	{
		retVal = pow( left , right);
		rot->setData(retVal);
		return retVal;
	}
	else if (rot->getVariable() == '%')
	{
		retVal = left % right;
		rot->setData(retVal);
		return retVal;
	}
	
}
void ExpresTree::dispAfterExecution(Node* rot, int wid)
{

	if (rot == nullptr)
	{
		return;
	}
	wid += width;
	dispAfterExecution(rot->getRight(), wid);

	cout << endl;
	for (int i = width; i < wid; i++)
	{
		cout << " ";
	}
	cout << "( " << rot->getData() << " )" << "\n";

	dispAfterExecution(rot->getLeft(), wid);
}