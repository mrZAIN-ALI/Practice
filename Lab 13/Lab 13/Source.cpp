#include <iostream>
#include <string>
#include"HashTable.h"
using namespace std;

int main()
{
    cout << "Creating Hash Table Of Size 10 initialy \n";
    HashTable hTable(10);
    cout << "Insertng Values In Table \n\n";
    hTable.insert(Node(22,"g"));
    hTable.insert(Node(43,"f"));
    hTable.insert(Node(75,"e"));
    hTable.insert(Node(34,"q"));
    hTable.insert(Node(24,"a"));
    hTable.printTable();

    hTable.insert(Node(569, "u"));
    cout << "After inserting key(564)\n";
    hTable.printTable();


    cout << "Searching for  key(75) \n Value associate with key is : "
        << hTable.search(75) << "\n\n";

    cout << "Searching for  key(71) \n Value associate with key is : "
        << hTable.search(71) << "\n\n";
   
    cout << "NOw deleting 75\n";
    hTable.del(24);

    cout << "\n\nAfter Deleteing key(24)  Table is : \n";
    hTable.printTable();

    return 0;
}