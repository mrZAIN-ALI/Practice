#include"RabinKarp.h"
#include<string>
#include<cmath>
#include<iostream>
#include<fstream>
const int primeVal= 31;
RabinKarp::RabinKarp()
{
	cntr = 0;
	nameOfFile = " ";
}
bool RabinKarp::setFileName(string name)
{
	nameOfFile = name;
	fstream file;
	file.open(name, ios::in);
	if (file)
	{
		file.close();
		return 1;
	}
	else
	{

		return 0;
	}
}
void RabinKarp::recrreateHashForSubString(long& prevHashVal, int m, char& oldChar, char& newChar)
{	prevHashVal -= oldChar;

	prevHashVal /= primeVal;
	prevHashVal += (newChar * pow(primeVal, m - 1));
}
long RabinKarp::getHashOfSubString(string& subString, int i, int m)
{
	long hash = 0;

	for (int j = 0; j < m; j++) {
		hash += subString[i + j] * pow(primeVal,j);
	}

	return hash;
}
void RabinKarp::searchByRabinKarp(string lineOfString,string stringToSearch)
{
	int stringToSeatchLnth = stringToSearch.length();

	if (stringToSeatchLnth > lineOfString.length())
	{
		return;
	}

	long stringToSearchHash = getHashOfSubString(stringToSearch, 0, stringToSeatchLnth);
	long SubStringhashVal = 0;
	
	for (int i = 0; i <= lineOfString.length() - stringToSearch.length(); i++) 
	{
		if (i == 0) 
		{
			SubStringhashVal = getHashOfSubString(lineOfString, 0, stringToSeatchLnth);
		}
		else 
		{
			recrreateHashForSubString(SubStringhashVal, stringToSeatchLnth, lineOfString[i - 1], lineOfString[i + stringToSeatchLnth - 1]);
		}

		if (SubStringhashVal == stringToSearchHash) 
		{
			int k = 0;

			for (; k < stringToSeatchLnth; k++) 
			{

				if (stringToSearch[k] != lineOfString[i + k]) 
				{
					break;
				}

			}

			if (k == stringToSeatchLnth) 
			{
				cntr++;
				return;
			}
		}
	}
	
}
void RabinKarp::displayFile()
{
	string line;
	fstream inFile;
	inFile.open(nameOfFile, ios::in);
	if (inFile)
	{
		while (!inFile.eof())
		{

			getline(inFile, line);
			cout << line<<endl;
			
		}


	}
	else
	{
		cout << "Can't load file fetal error\n";
	}
	inFile.close();
}