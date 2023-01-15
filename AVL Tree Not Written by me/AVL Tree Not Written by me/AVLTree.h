#include<iostream>
using namespace std;
#pragma once
class Node {

    int data;
    Node* left;
    Node* right;


    Node(int v)
    {
        data = v;
        left = NULL;
        right = NULL;
    }
public:
    void setData(int v) { data = v; }
    int getData() { return data; }
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    friend class AVLTree;
};

class AVLTree {
    Node* root;

public:
    Node* getRoot() { return root; }
    void setRoot(Node* r) { root = r; }
    AVLTree()
    {
        root = NULL;
    }
    int height(Node* r);
    bool isTreeEmpty();
    Node* right_Rotate(Node* y);
    Node* left_Rotate(Node* x);
    int getBalanceFactor(Node* n);
    Node* minValueNode(Node* node);
    Node* insert(Node* r, Node* new_node);
    void displayPreorder(Node* r);
    void displayPostorder(Node* r);
    void displayInorder(Node* r);
    Node* recursiveSearch(Node* r, int val);
    Node* deleteNode(Node* r, int key);
      

};