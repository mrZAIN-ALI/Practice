#include"AVLTree.h"
#include<iostream>
using namespace std;
Node* AVLTree::left_Rotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}
Node* AVLTree::right_Rotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}
int AVLTree::height(Node* r)
{
    if (r == NULL)
        return -1;
    else {

        int lheight = height(r->left);
        int rheight = height(r->right);


        if (lheight > rheight)
            return (lheight + 1);
        else return (rheight + 1);
    }
}
bool AVLTree::isTreeEmpty()
{
    if (root == NULL) {
        return true;
    }
    else {
        return false;
    }
}
int AVLTree:: getBalanceFactor(Node* n)
{
    if (n == NULL)
        return -1;
    return (height(n->left) - height(n->right));
}
Node* AVLTree::insert(Node* r, Node* new_node)
{
    if (r == NULL)
    {
        r = new_node;
        cout << "Inserted successfully" << endl;
        return r;
    }

    if (new_node->data < r->data)
    {
        r->left = insert(r->left, new_node);
    }
    else if (new_node->data > r->data)
    {
        r->right = insert(r->right, new_node);
    }
    else
    {
        cout << "No duplicate  allowed" << endl;
        return r;
    }

    int bFactor = getBalanceFactor(r);

    if (bFactor > 1 && new_node->data < r->left->data)
        return right_Rotate(r);


    if (bFactor < -1 && new_node->data > r->right->data)
        return left_Rotate(r);

    if (bFactor > 1 && new_node->data > r->left->data)
    {
        r->left = left_Rotate(r->left);
        return right_Rotate(r);
    }

    if (bFactor < -1 && new_node->data < r->right->data)
    {
        r->right = right_Rotate(r->right);
        return left_Rotate(r);
    }

    return r;

}
Node* AVLTree::recursiveSearch(Node* r, int val)
{
    if (r == NULL || r->data == val)
    {
        return r;
    }

    else if (val < r->data)
    {
        return recursiveSearch(r->left, val);
    }

    else
        return recursiveSearch(r->right, val);
}
Node* AVLTree::deleteNode(Node* r, int key)
{

    if (r == NULL)
    {
        return NULL;
    }

    else if (key < r->data)
    {
        r->left = deleteNode(r->left, key);
    }

    else if (key > r->data)
    {
        r->right = deleteNode(r->right, key);
    }

    else
    {

        if (r->left == NULL)
        {
            Node* temp = r->right;
            delete r;
            return temp;
        }
        else if (r->right == NULL)
        {
            Node* temp = r->left;
            delete r;
            return temp;
        }
        else
        {

            Node* temp = minValueNode(r->right);
            r->data = temp->data;
            r->right = deleteNode(r->right, temp->data);

        }
    }

    int bFactor = getBalanceFactor(r);

    if (bFactor == 2 && getBalanceFactor(r->left) >= 0)
        return right_Rotate(r);

    else if (bFactor == 2 && getBalanceFactor(r->left) == -1)
    {
        r->left = left_Rotate(r->left);
        return right_Rotate(r);
    }

    else if (bFactor == -2 && getBalanceFactor(r->right) <= -0)
        return left_Rotate(r);

    else if (bFactor == -2 && getBalanceFactor(r->right) == 1) {
        r->right = right_Rotate(r->right);
        return left_Rotate(r);
    }

    return r;
}
Node* AVLTree::minValueNode(Node* node)
{
    Node* current = node;

    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
void AVLTree::displayPreorder(Node* r)
{
    if (r == NULL)
        return;

    cout << r->data << " ";
    displayPreorder(r->left);
    displayPreorder(r->right);
}
void AVLTree::displayInorder(Node* r)
{
    if (r == NULL)
        return;

    displayInorder(r->left);
    cout << r->data << " ";
    displayInorder(r->right);
}
void AVLTree::displayPostorder(Node* r)
{
    if (r == NULL)
        return;

    displayPostorder(r->left);
    displayPostorder(r->right);
    cout << r->data << " ";
}