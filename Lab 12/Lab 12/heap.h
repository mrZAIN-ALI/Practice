#pragma once
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
class heap
{
	int sizeOFArray;
	int *nodes;
public:
	int gatMaxSizr() { return sizeOFArray; }
	void setMaxSize(int s) { sizeOFArray = s; }
	int getLeft(int n) { return n * 2; }
	int getRight(int n) { return (n * 2) + 1; }

	void minHeap(int* arr, int i, int n);
	void maxHeap(int* arr, int i, int n);
	void buildMAXHeap(int* arr, int n);
	void buildMINHeap(int* arr, int n);
	void heapSort(int* arr, int n);
	void display(int);


	void LevelOrderTraversal(int*);
	int* getarrayPtr() { return nodes; }
	void setArrayPtr(int*p) { nodes = p; }
	heap(int* arr,int n);	
	int return_Index_Of_LeftChild(int nodeIndex);
	int return_Index_Of_RightChild(int nodeIndex);
	
	
};
heap::heap(int *arr,int n)
{
	sizeOFArray = n;
	nodes = arr;

}
void heap::buildMAXHeap(int* arr, int n)
{
	for (int i = n / 2; i >= 1; i--)
	{
		maxHeap(arr, i, n);
	}
}
void heap::minHeap(int* arr, int i, int n)
{
	int leftIndex = getLeft(i);
	int rightIndex = getRight(i);
	int smallestIndex;
	if (leftIndex <= n and arr[leftIndex] < arr[i])
	{
		smallestIndex = leftIndex;
	}
	else
	{
		smallestIndex = i;
	}
	if (rightIndex <= n and arr[rightIndex] < arr[smallestIndex])
	{
		smallestIndex = rightIndex;
	}
	if (smallestIndex != i)
	{
		swap(arr[i], arr[smallestIndex]);
		minHeap(arr, smallestIndex, n);
	}


}
void heap::maxHeap(int* arr, int i, int n)
{
	int leftIndex = getLeft(i);
	int rightIndex = getRight(i);
	int largestIn;
	if (leftIndex <= n and arr[leftIndex] > arr[i])
	{
		largestIn = leftIndex;
	}
	else
	{
		largestIn = i;
	}
	if (rightIndex <= n and arr[rightIndex] > arr[largestIn])
	{
		largestIn = rightIndex;
	}
	if (largestIn != i)
	{
		swap(arr[i], arr[largestIn]);
		maxHeap(arr, largestIn, n);
	}


}
void heap::buildMINHeap(int* arr, int n)
{
	for (int i = n / 2 ; i >= 1; i--)
	{
		minHeap(arr, i, n);
	}
}
void heap::display(int n)
{
	for (int i = 1; i < n; i++)
	{
		cout << nodes[i] << "  ";

	}
}
void heap::heapSort(int *arr, int n)
{
	buildMAXHeap(arr, n);

	for (int i = n-1 ; i >= 0; i--) 
	{
		swap(arr[0], arr[i]);
		maxHeap(arr, i-1, gatMaxSizr());
	}
}


void heap::LevelOrderTraversal(int *arr)
{
	int index = 1;
	if (arr[index] == (-1))
	{
		return;
	}

	queue<int> queue;
	queue.push(arr[index]);

	while (!queue.empty())
	{

		int currentNodeVal = queue.front();
		queue.pop();

		cout << currentNodeVal << " ";
		if (arr[return_Index_Of_LeftChild(index)] != -1)
		{
			queue.push(arr[return_Index_Of_LeftChild(index)]);
			index++;
		}
		if (arr[return_Index_Of_RightChild(index)] != -1)
		{
			queue.push(arr[return_Index_Of_RightChild(index)] != -1);
			index++;

		}
	}
}
int heap::return_Index_Of_LeftChild(int nodeIndex)
{
	if (nodeIndex > sizeOFArray || nodeIndex < 0)
	{
		return -1;
	}
	else {

		return ((nodeIndex * 2));
	}
}
int heap::return_Index_Of_RightChild(int nodeIndex)
{
	if (nodeIndex > sizeOFArray || nodeIndex < 0)
	{
		return -1;
	}
	else {

		return ((nodeIndex * 2) + 1);
	}
}
