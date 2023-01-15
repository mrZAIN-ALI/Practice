#include"List.h"
#include<iostream>
using namespace std;
int main()
{
    List list;
    list.insert(43);
    list.insert(323);
    list.insert(143);
    list.insert(212);
    list.insert(7);
    list.insert(700);

    list.display();
    return 0;
}