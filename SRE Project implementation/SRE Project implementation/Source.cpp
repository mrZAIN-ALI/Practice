#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include<Windows.h>
#include <stdio.h>
#include"Student.h"
using namespace std;
const int MAX_ITEMS = 100;

int main()
{
    Student studentObject;
    int switchMainCases;
    Inventory inventory[MAX_ITEMS];
    int numItems = 0;
    char choice;
    bool working_on_Inven_record = true;
    fstream inVentoryItems;
    fstream inFile;
    string tempString,
        stringForInvent;
    
    do
    {
        system("cls");
        working_on_Inven_record = true;
        cout << "\t\t\t-------------------------------------------" << endl;
        cout << "\t\t\t|        HOSTEL MANAGEMENT SYSTEM         |" << endl;
        cout << "\t\t\t-------------------------------------------" << endl;
        cout << "\t\t\t-------------------------------------------" << endl;
        cout << "\t\t\t1.Student Information" << endl;
        cout << "\t\t\t2.Employee Show Information" << endl;
        cout << "\t\t\t3.Inventory Information" << endl;
        cout << "\t\t\t4.Exit" << endl;
        cout << "\t\t\t-------------------------------------------" << endl;
        cout << "\t\t\tEnter your choice: ";
        cin >> switchMainCases;
        switch (switchMainCases)
        {
        case 1:
            studentObject.menu();
            break;
        case 2:
            cout << "\t\t\t-------------------------------------------" << endl;
            cout << "\t\t\t|          HOSTEL MANAGEMENT SYSTEM       |" << endl;
            cout << "\t\t\t-------------------------------------------" << endl;
         
            puts("\t\t\tEMPLOYEE INFORMATION:");
            cout << "\t\t\tName------------Status-----------Number" << endl;
            cout << "\t\t\t" << endl;
           
            inFile.open("employeeInfo.txt", ios::in);
            if (inFile)
            {
                
                while (!inFile.eof())
                {
                    getline(inFile, tempString);
                    cout<<"\t\t\t" << tempString <<"\n\n" ;
                }
            }
            else
            {
                cout << "Can not load Employee info database\n";
            }

            system("Pause");
            break;
        case 3:
            while (working_on_Inven_record) 
            {
                cout << "\t\t\t-------------------------------------------" << endl;
                cout << "\t\t\t|             INVENTORY RECORD            |" << endl;
                cout << "\t\t\t-------------------------------------------" << endl;
                cout << "\t\t\t1. Add new item" << endl;
                cout << "\t\t\t2. View all items" << endl;
                cout << "\t\t\t3. Save and exit" << endl;
                cout << "\t\t\tEnter your choice: ";
                cin >> choice;

                switch (choice) 
                {
                case '1':
                    // Add new item
                    if (numItems < MAX_ITEMS) 
                    {
                        cout << "\t\t\tEnter item name: ";
                        cin >> inventory[numItems].name;
                        cout << "\t\t\tEnter item quantity: ";
                        cin >> inventory[numItems].quantity;
                        cout << "\t\t\tEnter item price: ";
                        cin >> inventory[numItems].price;
                        numItems++;
                    }
                    else 
                    {

                        cout << "\t\t\tError: Inventory is full!" << endl;
                    }

                    inVentoryItems.open("inventory.txt", ios::app);
                    for (int i = 0; i < numItems; i++) {
                        inVentoryItems << inventory[i].name << "," << inventory[i].quantity << "," << inventory[i].price << endl;
                    }
                    inVentoryItems.close();

                    break;
                case '2':
                    // View all items
                    cout << "\t\t\tInventory List:" << endl;
               
                    cout << "\t\t\tName----Quantity---Price" << endl;
                    cout << "\t\t\t" << endl;

                    inVentoryItems.open("inventory.txt", ios::in);

                    if (inVentoryItems)
                    {
                        while (!inVentoryItems.eof())
                        {
                            getline(inVentoryItems, stringForInvent);
                            cout << "\t\t\t" << stringForInvent << "\n\n";

                        }
                    }
                    else
                    {
                        cout << "inventory File not loaded\n";
                    }
                    break;
                case '3':
                 
                    working_on_Inven_record = false;
                    inVentoryItems.close();
                    break;
                default:
                    cout << "\t\t\tInvalid choice. Try again." << endl;
                }
            }
            break;
     
        }
    }while (switchMainCases != 4);
    return 0;
}
