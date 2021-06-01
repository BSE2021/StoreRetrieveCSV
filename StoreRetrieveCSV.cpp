// StoreRetrieveCSV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream> //string stream to read a column and separate
#include <fstream>
using namespace std;

struct Employee {
    string empname;
    int empid;

    //constructor to initialize
    Employee(string ename = "", int eid = 0) {
        empname = ename;
        empid = eid;
    }
};

int main()
{
    Employee emp[3];
    Employee employee;
   /* ofstream myfile("emp.csv", ios::out);
    int i;
    for (i = 0; i < 3; i++) {
        cin.ignore();
        cout << "\nEnter the name of the employee: ";
        getline(cin, emp[i].empname);

        cout << "\nEnter the id of the employee: ";
        cin >> emp[i].empid;

        myfile << emp[i].empname << "," << emp[i].empid << endl;
    }
    myfile.close();*/

    ifstream myfile;
    myfile.open("emp.csv", ios::in);
   // struct Employee transaction;
    string line; //to store the line that is read from the line
    int linenum = 0; //used as loop index

    while (getline(myfile, line)) { //reads a line from csv file
        //cout << line;
        istringstream linestream(line); //stringstream separates the line values
        string item;
        getline(linestream, item, ',');//read separated linestream values and store in item and add comma

        employee.empname = item; //store the separated value in structure member empname

        getline(linestream, item, ',');
        stringstream ss(item); //convert the data type from string to int
        ss >> employee.empid;//store the separated value in structure member empid
        emp[linenum] = employee;//push the structure into the array 
        linenum++; //index variable incremented
    }
    cout << "\n";
    string searchName;
    cin.ignore(); //clear the buffer before reading the string
    cout << "\nEnter a name to search and get the id: ";
    getline(cin, searchName);

    for (int i = 0; i < 3; i++) {
        //searching and filtering
        if (emp[i].empname == searchName)
        cout << emp[i].empname << "\t" << emp[i].empid << endl;

        //sorting
    }




    myfile.close();
    return 0;
}