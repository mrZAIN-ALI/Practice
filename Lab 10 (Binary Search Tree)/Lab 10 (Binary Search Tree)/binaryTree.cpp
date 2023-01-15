#include"BinaryTree.h"
#include<iostream>
using namespace std;
void BstTree::preOrderDisplay(BstNode* rot)
{
    if (rot != nullptr)
    {
        cout << rot->getData() << " ";
        preOrderDisplay(rot->left);
        preOrderDisplay(rot->right);
    }

}
void BstTree::inOrderDisplay(BstNode* rot)
{
    if (rot != nullptr)
    {
        inOrderDisplay(rot->left);
        cout << rot->getData() << " ";
        inOrderDisplay(rot->right);
    }

}
void BstTree::postOrderDisplay(BstNode* rot)
{
    if (rot != nullptr)
    {
        postOrderDisplay(rot->left);
        postOrderDisplay(rot->right);
        cout << rot->getData() << " ";
    }

}

BstNode* BstTree::insert(BstNode* rot, int val)
{
    BstNode* newNode = new BstNode(val);
    if (rot == nullptr)
    {
        rot = newNode;
        return newNode;
    }
    if (val < rot->getData())
    {
        rot->left = insert(rot->left, val);


    }
    else
    {
        rot->right = insert(rot->right, val);


    }

    return rot;
}

BstNode* BstTree::search(BstNode* rot, int key)
{
    BstNode* returnNode;
    if (rot == nullptr)
    {
        return nullptr;
    }
    else if (rot->getData() == key)
    {
        return rot;
    }

    if (rot->data > key)
    {
        search(rot->left, key);
    }
    else
    {

        search(rot->right, key);
    }



}
BstNode* BstTree::FindmaxVal(BstNode* rot)
{
    if (rot == nullptr)
    {
        return nullptr;
    }
    if (rot->right == nullptr)
    {
        return rot;
    }
    return FindmaxVal(rot->right);
}
BstNode* BstTree::FindminVal(BstNode* rot)
{
    if (rot == nullptr)
    {
        return nullptr;
    }
    if (rot->left == nullptr)
    {
        return rot;
    }
    return FindminVal(rot->left);
}
BstNode* BstTree::Delete(BstNode* node, int key)
{
    BstNode* temp;
    if (!(search(getRoot(), key)))
    {
        cout << "value not exixt\n\n";
        return NULL;
    }
    int cp = key - node->getData();

    if (cp < 0)
    {
        temp = Delete(node->left, key);
        node->left = temp;
        if (temp != NULL)
            temp->parent = node;
    }
    else if (cp > 0)
    {
        temp = Delete(node->right, key);
        node->right = temp;
        if (temp != NULL)
            temp->parent = node;
    }

    else if (node->left != NULL && node->right != NULL)
    {
        BstNode* min_Node;

        min_Node = FindminVal(node->right);
        node->data = min_Node->getData();
        temp = Delete(node->right,
            min_Node->getData());
        node->right = temp;
        if (temp != NULL)
            temp->parent = node;
    }
    else
    {
        BstNode* deleteIt = node;
        if (node->left == nullptr)
        {
            node = node->right;
        }
        else if (node->right == nullptr)
        {
            node = node->left;
        }
        else
        {
            node = nullptr;
        }
        delete deleteIt;
    }
    return node;
}
