#include"Stack.h"
#include<iostream>
using namespace std;
int main()
{
    Stack stack;
    stack.push(10.3,'u');
    stack.push(7.3,'c');
    stack.push(.564,'a');
    stack.push(9.5,'w');
    stack.display();
    
    return 0;
}