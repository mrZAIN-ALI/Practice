#pragma once
#include<string>
using namespace std;
class RabinKarp
{
	string nameOfFile;
	int cntr;
public:
	RabinKarp();
	bool setFileName(string name);
	int incrementCounter() { return (++cntr); }

	void recetCounter() { cntr = 0; }
	int getCounter() { return cntr; }
	string getFileName() { return nameOfFile; }
	void displayFile();

	bool wordFound() { return (cntr > 0); }
	void recrreateHashForSubString(long& , int , char& , char& );
	long getHashOfSubString(string& , int, int);
	void searchByRabinKarp(string,string );

};
