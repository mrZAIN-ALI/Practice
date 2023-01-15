#include<iostream>
#include<cstdlib>
#include"AVLTree.h"
using namespace std;
int main() 
{
    AVLTree tree;
    int choice, val;

    do 
    {
        cout <<" Select Option number ... Enter 0 to exit" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. display in All three mode" << endl;
        cout << "0. Exit Program" << endl;

        cin >> choice;
       
        Node* new_node = new Node();

        switch (choice)
        {
        case(0):
            break;
        case(1):
        {
            cout << "Enter value insert in AVL Tree : ";
            cin >> val;
            new_node->setData(val);
            tree.setRoot(tree.insert(tree.getRoot(), new_node));
            cout << endl;
            break;
        }
        case(2):
        {
            cout << "Enter VALUE to SEARCH in AVL Tree : ";
            cin >> val;
            new_node = tree.recursiveSearch(tree.getRoot(), val);
            if (new_node != NULL) {
                cout << "Value found" << endl;
            }
            else {
                cout << "Value NOT found" << endl;
            }
            break;
        }
        case(3):
        {
            cout << "Enter VALUE to DELETE in AVL: ";
            cin >> val;
            new_node = tree.recursiveSearch(tree.getRoot(), val);
            if (new_node != NULL)
            {
                tree.setRoot(tree.deleteNode(tree.getRoot(), val));
                cout << "Value is Deleted" << endl;
            }
            else
            {
                cout << "Sorry Value Nit found" << endl;
            }
            break;
        }
        case(4):
        {
            cout << "InOrder: ";
            tree.displayInorder(tree.getRoot());
            cout << endl;
            cout << "PreOrder: ";

            tree.displayPreorder(tree.getRoot());
            cout << endl;

            cout << "PostOrder: ";
            tree.displayPostorder(tree.getRoot());
            system("pause");
        }
        default:
            cout << "Chose correct option " << endl;
        }
        system("cls");
     
    } while (choice != 0);

    return 0;
}