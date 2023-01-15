#include<iostream>
#include<string>
#include"ExpressionTree.h"
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include<iomanip>
using namespace std;
char menu(string);
void switchCase(string);
int main()
{
	string infixExpression = "(a+b)*(c*(d^e))";
	
	switchCase(infixExpression);

	return 0;
}
char menu(string exp)
{
	char choice='0';
	system("CLS");
	cout << setfill('=') << setw(70)<<" ";
	cout << "\n\t\tGiven Expression is :" << exp << endl;
	cout << "\n\t\tPRESS One of The Following\n";
	cout << setfill('=') << setw(70)<<" ";
	cout << "\n\n1.To Convert the Shown Expression Into Expression Tree\n"
		<< "2.To Display Expression Tree \n"
		<< "3.To Evaluate Expression Tree and Show Values of variable\n"
		<< "4.To Exit\n\n";
	cout<< setfill('=') << setw(70)<<" \n>";
	choice = _getch();


	while (choice<'1'|| choice>'4')
	{
		cout << "Invalid choice please Chose carefully\nPress Again \n";
		cout << setfill('=') << setw(70) << " ";
		cout << "\n>";
		choice=_getch();
	}
	cout << setfill('=') << setw(70) << " ";
	cout << endl;

	return choice;
}
void switchCase(string expression)
{

	bool isTreeCreated=false;
	ExpresTree tree(expression);
	char choice = '0';
	do
	{
		choice=menu(tree.getGivenExp());
		switch (choice)
		{
		case('1'):
		{
			tree.setRoot(tree.inFixToExpressTree(tree.getGivenExp()));
			isTreeCreated = true;
			cout << "\nExpression Tree Created!\n";
			cout << setfill('=') << setw(70) << " \n";
			system("PAUSE");
			break;
		}
		case('2'):
		{
			if (!isTreeCreated)
			{
				cout << "Expression Tree is not Created \nCreate it first\n";
			}
			else
			{
			
				tree.display(tree.getRoot());

			}
			cout << setfill('=') << setw(70) << " \n";
			system("PAUSE");

			break;
		}
		case('3'):
		{
			if (!isTreeCreated)
			{
				cout << "Expression Tree is not Created \nCreate it first\n";
			}
			else
			{
				cout << "Given Expression Tree is\n\n";
				cout << setfill('=') << setw(70) << " \n";
				Sleep(6000);
				tree.display(tree.getRoot());
				cout << endl;

				cout << setfill('=') << setw(70) << " \n";
				Sleep(6000);
				cout << "After Randomly Assigning Value\n";
				tree.randomlyAssignVal(tree.getRoot());
				tree.valueAssignedDisplay(tree.getRoot());

				cout << setfill('=') << setw(70) << " \n";
				long finalResult = tree.evaluate(tree.getRoot());
				Sleep(6000);
				cout << "Solved Tree is\n";
				tree.dispAfterExecution(tree.getRoot());

				cout << setfill('=') << setw(70) << " \n";
				Sleep(6000);
				cout << "Final Result is : " << finalResult<<endl;
				cout << setfill('=') << setw(70) << " \n";

			}
			system("PAUSE");

			break;
		}
		}


	} while (choice != '4');

}