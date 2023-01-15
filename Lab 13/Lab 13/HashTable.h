#pragma once
#include <string>
#include <math.h>
using namespace std;
class Node
{
public:
    int key;
    string val;
    Node* next;

    Node() : key(0), val(""), next(0) {};
    Node(int Key, string Value) : key(Key), val(Value), next(0) {};
    Node(Node const& data) : key(data.key), val(data.val), next(data.next) {};
};

class HashTable
{
    int size;
    int   cnt;
    Node** table;

public:

    void insert(Node);
    int hashFun(int);
    void del(int);
    string search(int);
    void printTable();
    void tableDoubl();
    void tableShrnk();
    void hashAgain(int);
    HashTable() {};
    HashTable(int n) : size(n), cnt(0)
    {   table = new Node * [size];
        for (int i = 0; i < size; i++)
        {
            table[i] = 0;
        }
    }
};