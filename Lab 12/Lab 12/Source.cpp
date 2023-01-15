#include <iostream>
#include <algorithm>
#include"heap.h"
using namespace std;

int main()
{
    cout << "Creating Array\n";
    const int maxSize = 9; 
    int array[maxSize] = { 0, 8, 4, 6, -1, 5, 3, 7 ,9};

    cout << "Building Max heap through heapify and buildHeap  function\n";
    heap heap(array,maxSize);
    heap.buildMAXHeap(array,maxSize-1);

    cout << "Print : ";
    heap.display(maxSize);
    cout << "Array aftr using Heapify Function: \n";
    
    cout << "using heap sort Algorithm\n";
    heap.heapSort(array,maxSize-1);
    heap.display(maxSize);

    return 0;
}


