#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <string_view>
#include <regex>
#include<Windows.h>
#include <stdio.h>
#include"Student.h"
using namespace std;

void Student::menu()
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t-------------------------------------------" << endl;
    cout << "\t\t\t|        HOSTEL MANAGEMENT SYSTEM         |" << endl;
    cout << "\t\t\t-------------------------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. To Return to previous menu" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option!" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tEnter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case (1):
        do
        {
            insert();
            cout << "\n\t\t\t Add Another Student Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case (2):
    {

        display();
        break;
    }
    case (3):
    {

        modify();
        break;
    }
    case (4):
    {

        search();
        break;
    }
    case (5):
    {

        deleted();
        break;
    }
    case (6):
    {

        return;
    }
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    _getch();
    goto menustart;
}
void Student::insert() // add student details
{
    system("cls");
    fstream appendFile;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Student Details ---------------------------------------------" << endl;

    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_no;
    cout << "\t\t\tEnter Room No: ";
    cin >> room_no;
    cout << "\t\t\tEnter Email Id: ";
    cin >> email_id;
    cout << "\t\t\tEnter Session: ";
    cin >> session;
    cout << "\t\t\tEnter Degree Program: ";
    cin >> degree;
    appendFile.open("studentRecord.txt", ios::app | ios::out);
    appendFile << " " << name << " " << roll_no << " " << room_no << " " << email_id << " " << session << " " << degree << "\n";
    appendFile.close();
}

void Student::display() // display students details
{
    system("cls");
    fstream inFile;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    inFile.open("studentRecord.txt", ios::in);
    if (!inFile)
    {

        cout << "\n\t\t\tNo Data Is Present...";
        inFile.close();
    }
    else
    {
        inFile >> name
            >> roll_no
            >> room_no
            >> email_id
            >> session
            >> degree;
        while (!inFile.eof())
        {
            cout << "\n\n\t\t\t Student No.: " << total++ << endl;
            cout << "\t\t\t Student Name: " << name << endl;
            cout << "\t\t\t Student Roll No.: " << roll_no << endl;
            cout << "\t\t\t Student Room NO.: " << room_no << endl;
            cout << "\t\t\t Student Email Id.: " << email_id << endl;
            cout << "\t\t\t Student Session: " << session << endl;
            cout << "\t\t\t Student Degree Program: " << degree << endl;
            inFile >> name
                >> roll_no
                >> room_no
                >> email_id
                >> session
                >> degree;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    inFile.close();
}
void Student::modify() // Modify Students Details
{
    system("cls");
    fstream inFile, tempFile;
    string nameOfStndToModify;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    inFile.open("studentRecord.txt", ios::in);
    if (!inFile)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Name of Student which you want to Modify: ";
        cin >> nameOfStndToModify;
        tempFile.open("tempFile.txt", ios::app | ios::out);
        inFile >> name >> roll_no >> room_no >> email_id >> session >> degree;
        while (!inFile.eof())
        {
            if (nameOfStndToModify != name)

                tempFile << " " << name << " " << roll_no << " " << room_no << " " << email_id << " " << session << " " << degree << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "\t\t\tEnter Room No.: ";
                cin >> room_no;
                cout << "\t\t\tEnter Email Id: ";
                cin >> email_id;
                cout << "\t\t\tEnter Session: ";
                cin >> session;
                cout << "\t\t\tEnter Degree Program: ";
                cin >> degree;
                tempFile << " " << name << " " << roll_no << " " << room_no << " " << email_id << " " << session << " " << degree << "\n";
                found++;
            }
            inFile >> name >> roll_no >> room_no >> email_id >> session >> degree;
            if (found == 0)
            {
                cout << "\n\n\t\t\t Student Name Not Found....";
            }
        }
        tempFile.close();
        inFile.close();
        remove("studentRecord.txt");
        rename("tempFile.txt", "studentRecord.txt");
    }
}
void Student::search() // search data of student
{
    system("cls");
    fstream inFile;
    int found = 0;
    inFile.open("studentRecord.txt", ios::in);
    if (!inFile)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string nameToSearch;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n Enter Name of Student Which You Want to Search: ";
        cin >> nameToSearch;
        inFile >> name
            >> roll_no
            >> room_no
            >> email_id
            >> session
            >> degree;
        while (!inFile.eof())
        {
            if (nameToSearch == name)
            {
                cout << "\n\t\t\t Student Name: " << name << endl;
                cout << "\t\t\t Student Roll No.: " << roll_no << endl;
                cout << "\t\t\t Student course: " << room_no << endl;
                cout << "\t\t\t Student Email Id.: " << email_id << endl;
                cout << "\t\t\t Student Session: " << session << endl;
                cout << "\t\t\t Student Degree Program: " << degree << endl;
                found++;
            }
            inFile >> name
                >> roll_no
                >> room_no
                >> email_id
                >> session
                >> degree;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent Name Not Found...";
        }
        inFile.close();
    }
}
void Student::deleted()
{
    system("cls");
    fstream inFile,
        tempFile;
    int found = 0;
    string nameOFstdntToDelete;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    inFile.open("studentRecord.txt", ios::in);
    if (!inFile)
    {
        cout << "\n\t\t\tNo Data is Present..";
        inFile.close();
    }
    else
    {
        cout << "\nEnter Name of Student which you want Delete Data: ";
        cin >> nameOFstdntToDelete;
        tempFile.open("record.txt", ios::app | ios::out);
        inFile >> name
            >> roll_no
            >> room_no
            >> email_id
            >> session
            >> degree;
        while (!inFile.eof())
        {
            if (nameOFstdntToDelete != name)
            {
                tempFile << " " << name << " " << roll_no << " " << room_no << " " << email_id << " " << session << " " << degree << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            inFile >> name
                >> roll_no
                >> room_no
                >> email_id
                >> session
                >> degree;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Name Not Found....";
        }
        tempFile.close();
        inFile.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}