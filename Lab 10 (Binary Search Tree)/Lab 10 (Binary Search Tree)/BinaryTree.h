#pragma once
#include<iostream>
using namespace std;
class BstNode
{
    int data;

    BstNode* left,
        * right,
        * parent;
   
    BstNode(int val) { left = right = parent = nullptr, data = val; }
    void setData(int d) { data = d; }
    friend class BstTree;
public:
    BstNode() { left = right = parent = nullptr, data = 0 ; }
    int getData() { return data; }
    
};

class BstTree
{
    BstNode* root;
public:
    BstTree() { root = nullptr; }
    BstNode* getRoot() { return root; }
    void setRoot(BstNode* r) { root = r; }

    BstNode* insert( BstNode*,int val);
    BstNode* search(BstNode* n, int key);
    void preOrderDisplay(BstNode* rot);
    void inOrderDisplay(BstNode* rot);
    void postOrderDisplay(BstNode* rot);
    BstNode* FindmaxVal(BstNode* rot);
    BstNode* FindminVal(BstNode* rot);
    BstNode* Delete(BstNode* node, int key);
};