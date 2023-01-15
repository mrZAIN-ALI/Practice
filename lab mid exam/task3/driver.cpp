#include"Queue.h"
#include<iostream>
using namespace std;

int main()
{
	int size;
	int val;
	Queue queue;
	cout << "How many time you want to enter value in queue:";
	cin >> size;
	for (int i = 0; i < size; i++)
	{

		cout << "Please Enter val :";
		cin >> val;
		queue.enQueue(val);
	}
	
    cout<<"Sortes Queu in Accending order is :";
	queue.display();



	return 0;
}