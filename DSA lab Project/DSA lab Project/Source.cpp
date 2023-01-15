#include"RabinKarp.h"
#include<string>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<iomanip>
#include<windows.h>
using namespace std;
void menu();
void switchFunctionaty();

int main()
{

	switchFunctionaty();

	return 0;

}



void menu()
{
	system("CLS");
	cout << setfill('=') << setw(50) << " ";
	cout << "\n\tDefault file name is test.txt\n";
	cout << setfill('=') << setw(50) << " ";
	cout << "\n\t\tPRESS\n";
	cout << setfill('=') << setw(50) << " ";
	cout<< "\n1.To Enter File Name  \n"
		<< "2.To search any Word in File\n"
		<< "3.Display loaded file\n"
		<< "4.To Eixt\n";
	cout << setfill('=') << setw(50) << " ";
	cout << "\n\n>";
}
void switchFunctionaty()
{
	string nameOfFile=" ",
		searchWord=" ",
		lineFormFile;
	char choice = '0';
	bool flag = false;

	RabinKarp rabin;
	do
	{
		menu();
		rabin.recetCounter();
		choice = _getch();
		switch (choice)
		{
		case('1'):
		{

			cout << "\nName (Name of default file is test.txt):";
			cin >> ws;
			getline(cin, nameOfFile);
			rabin.setFileName(nameOfFile);
			while (!rabin.setFileName(nameOfFile))
			{
				cout << "Can't load File  Try Again  :";
				cin >> ws;
				getline(cin, nameOfFile);
			}
			cout << "Loading File SuccessFul\n";
			cout << setfill('=') << setw(50) << " \n";
			system("PAUSE");
			break;
		}
		case('2'):
		{
			
			cout << "Enter Word To find in loaded file : ";
			cin.ignore(NULL);
			getline(cin, searchWord);
			fstream inFile;
			inFile.open(rabin.getFileName(), ios::in);
			if (inFile)
			{
				while (!inFile.eof())
				{

					getline(inFile, lineFormFile);
					if (lineFormFile.length() == 0)
					{
						continue;
					}
					rabin.searchByRabinKarp(lineFormFile, searchWord);
				}


			}
			else
				cout << "can't load file fetal error "<<rabin.getFileName()<<endl;

			
			rabin.getCounter();
			if (rabin.wordFound())
			{
				cout << endl;
				cout << setfill('=') << setw(50) << " " << endl;
				cout << "Given Pice of String (WORD) found\n";
				Sleep(3000);
				cout << setfill('=') << setw(50) << " " << endl;
				cout << "Number of repetion of word is : " << rabin.getCounter() << endl;
				Sleep(3000);
				cout << setfill('=') << setw(50) << " " << endl;

			}
			else
			{

				cout << "Given Word not found\n";
			}
			system("PAUSE");
			break;
		}
		case('3'):
		{
			cout << setfill('=') << setw(80) << " " << endl;
			Sleep(3000);
			rabin.displayFile();
			cout << setfill('=') << setw(80) << " " << endl;
			system("PAUSE");
			break;
		}
		}


	} while (choice != '4');
}