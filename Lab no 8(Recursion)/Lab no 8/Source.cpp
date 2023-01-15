#include"LinkedList.h"
#include<iostream>
#include<conio.h>
using namespace std;
double MultiplyTwoNumbers(double, double);
double Find_Nth_Power(double, int);
int facrotrial(int);
int nthFabbiNumber(int);

char menu();

//Main Function
int main()
{
    LinkedList l;
    char choice = '0';
    do
    {

        choice = menu();
        double num1 = 0, num2 = 0;
        switch (choice)
        {
        case ('1'):
        {
            cout << "Enter Numebr 1 : ";
            cin >> num1;
            cout << "Enter Numebr 2 : ";
            cin >> num2;
            cout << "Their Product is : "<<MultiplyTwoNumbers(num1, num2) << endl;
            break;
        }
        case ('2'):
        {
            cout << "Enter Base numebr : ";
            cin >> num1;
            cout << "Enter exponent number : ";
            cin >> num2;
            cout << "Nth power of base is  : " << Find_Nth_Power(num1,num2) << endl;
            break;
         
        }
        case ('3'):
        {
            cout << "Enter Positive integer to find factorial: ";
            cin >> num1;
            cout << "it's Factorial is :  " << facrotrial(num1) << endl;
            break;
        }
        case ('4'):
        {
  
            cout << "Enter Positive integer to find fabonacci numebr: ";
            cin >> num1;
            cout << "it's nth fabonacci valuei s :  " << nthFabbiNumber(num1) << endl;
            break;
        }
        case ('5'):
        {

            
            if (l.isEmpty())
            {
                cout << "List is Empty\n";
            }
            else
            {
                cout << "Enter  integer to find in linked list: ";
                cin >> num1;
                if (l.search(l.getHead(), num1))
                {
                    cout << num1 << " Found\n";
                }
            }
            break;
        }case ('6'):
        {

            cout << "Enter  integer to Insert At tail: ";
            cin >> num1;
            l.setHead(l.insertAtTail(l.getHead(), num1));
            cout << "Insertion done\n";
            break;
        }case ('7'):
        {
            if (l.isEmpty())
            {
                cout << "List is empty\n";
            }
            else
            {
                cout << "Greatest Value is "<<l.findGreatest(l.getHead())<<endl;
            }
            break;
        }case ('8'):
        {
            if (l.isEmpty())
            {
                cout << "List is empty\n";
            }
            else
            {
                cout << "Displaying in Reverse order " << endl;
                l.display(l.getHead());
            }
            
            break;
        }
        }
    } while (choice != '9');

    
 
    return 0;
}

char menu()
{
    char choice = 0;

    cout <<
        "\n++++++++++++++++++++++++++++++++++"
        "\n\nSelect One of The following \n"
        "1) To Multiply Two numbers \n"
        "2) T0 Find the nth Power\n"
        "3) To Factorial\n"
        "4) To Find nth fabbonaci number\n"
        "5) To search value in linked list\n"
        "6) To insert value at tail\n"
        "7) To Find Greatest Value\n"
        "8) To Display List in reverse order\n"
        "9) To Exit\n>>"
        ;

    choice = _getch();
    while (choice < '1' || choice > '9')
    {
        cout << "Invalid Choice ! >> ";
        cin >> choice;
    }

    return choice;
}

double Find_Nth_Power(double base, int n)
{
    if (n == 0)
    {
        return 1;
    }


    return (base * Find_Nth_Power(base, n - 1));
}
double MultiplyTwoNumbers(double first_num, double second_num)
{
    if (second_num == 0)
    {
        return 0;
    }

    if (first_num < second_num)
    {
        swap(first_num, second_num);
    }

    return (first_num + MultiplyTwoNumbers(first_num, second_num - 1));

}
int facrotrial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * facrotrial(n - 1);
}
int nthFabbiNumber(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    return nthFabbiNumber(n - 1) + nthFabbiNumber(n - 2);
}