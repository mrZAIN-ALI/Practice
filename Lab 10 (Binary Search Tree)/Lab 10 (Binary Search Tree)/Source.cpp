#include<iostream>
using namespace std;
#include"BinaryTree.h"
int main()
{
    //Creating Instance
    BstTree bstTree;
    //Inserting values to Tree
    bstTree.setRoot(bstTree.insert(bstTree.getRoot(), 8));
    bstTree.insert(bstTree.getRoot(), 3);
    bstTree.insert(bstTree.getRoot(), 10);
    bstTree.insert(bstTree.getRoot(), 1);
    bstTree.insert(bstTree.getRoot(), 6);
    bstTree.insert(bstTree.getRoot(), 14);


    //Searchin in tree for 110
    cout << "Searching in Tree : ";
    if (bstTree.search(bstTree.getRoot(), 110))
    {
        cout << "Give Value Found\n";
    }
    else
    {
        cout << "Given Value Not Found\n";
    }
    cout << "\n\n";
    // Display
    cout << "Pre-Order display : ";
    bstTree.preOrderDisplay(bstTree.getRoot());
    cout << endl;
    cout << "\n\n";

    cout << "Post-Order Display : ";
    bstTree.postOrderDisplay(bstTree.getRoot());
    cout << endl;
    cout << "\n\n";

    cout << "In-Order Display : ";
    bstTree.inOrderDisplay(bstTree.getRoot());
    cout << endl;
    cout << "\n\n";

  
    
    //Finding Minimum Value
    cout<<"Minimum Value is : " << (bstTree.FindminVal(bstTree.getRoot()))->getData()<<endl;
    cout << "Maximum Value is : " << (bstTree.FindmaxVal(bstTree.getRoot()))->getData() << endl;
    cout << "\n\n";

    //Deleting Node having value 20
    bstTree.Delete(bstTree.getRoot(), 6);

    cout << "After Deletion of 6 \n";
    cout << "\n\n";

    // Display
    cout << "Pre-Order display : ";
    bstTree.preOrderDisplay(bstTree.getRoot());
    cout << endl;
    cout << "\n\n";

    cout << "Post-Order Display : ";
    bstTree.postOrderDisplay(bstTree.getRoot());
    cout << endl;
    cout << "\n\n";

    cout << "In-Order Display : ";
    bstTree.inOrderDisplay(bstTree.getRoot());
    cout << endl;
    cout << "\n\n";

    return 0;
}