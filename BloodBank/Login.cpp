#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <stdio.h>

using namespace std;

void Login(string cat) {
    donorList donor[20];
    recipientList recipient[20];
    recipientList admin[5];
    string inName, inPassword, record, col;
    int currentUser;
    bool loginStatus = false;
    cin.ignore();

    string fileName = (cat + "s.txt");
    vector<vector<string>> v1;
    vector<string> v2;
    ifstream f(fileName);

    if (!f.is_open()) {
        cout << "Could not open file\n";
    }
    while (getline(f, record, '|')) {
        stringstream s(record);
        while (getline(s, col, ',')) {
            v2.push_back(col);
        }
        v1.push_back(v2);
    }
    if (cat == "donor")
    {
        for (int i = 0; i < v1.size(); i++)
        {
            donor[i].username = v1[i][0];
            donor[i].password = v1[i][1];
            donor[i].fname = v1[i][2];
            donor[i].lname = v1[i][3];
            donor[i].dob = v1[i][4];
            donor[i].nationality = v1[i][5];
            donor[i].ethnicity = v1[i][6];
            donor[i].gender = v1[i][7];
            donor[i].existingConditions = v1[i][8];
            donor[i].bloodType = v1[i][9];
            donor[i].contactNumber = v1[i][10];
            donor[i].email = v1[i][11];
            donor[i].address = v1[i][12];
            donor[i].lastDonation = v1[i][13];
        }
    }
    else if (cat == "recipient")
    {
        for (int i = 0; i < v1.size(); i++)
        {
            recipient[i].username = v1[i][1];
            recipient[i].password = v1[i][2];
            recipient[i].name = v1[i][3];
            recipient[i].address = v1[i][4];
            recipient[i].email = v1[i][5];
            recipient[i].contactNumber = v1[i][6];

        }
    }
    else if (cat == "admin")
    {
        for (int i = 0; i < v1.size(); i++)
        {
            admin[i].username = v1[i][0];
            admin[i].password = v1[i][1];
        }
    }
    
    f.close();
    cat[0] = toupper(cat[0]);
    cout << "\n\t\t\t\t" << cat << " Login";
    line(100, '-');
    int maxAttempts = 0;
    do
    {
        cout << "\n" << "Enter Username: ";
        getline(cin, inName);
        cout << "Enter Password: ";
        getline(cin, inPassword);

        // cout << inName << " " << inPassword << " " << donor[0].username << " " << donor[0].password << " " << loginStatus;
        if (cat == "Donor") {
            if (!loginStatus)
            {
                for (int i = 0; i < v1.size(); i++)
                {
                    if (inName == donor[i].username && inPassword == donor[i].password)
                    {
                        loginStatus = true;
                        donor[i].currentUser = i;
                        cout << "\n\nLogin Successful\n" << "Welcome, " << donor[i].username;
                        goto success;
                    }
                }
            }
        }
        else if (cat == "Recipient") {
            if (!loginStatus)
            {
                for (int i = 0; i < v1.size(); i++)
                {
                    if (inName == recipient[i].username && inPassword == recipient[i].password)
                    {
                        loginStatus = true;
                        recipient[i].currentUser = i;
                        cout << "\n\nLogin Successful\n" << "Welcome, " << donor[i].username;
                        goto success;
                    }
                }
            }
        }
        else if (cat == "Admin") {
            if (!loginStatus)
            {
                for (int i = 0; i < v1.size(); i++)
                {
                    if (inName == admin[i].username && inPassword == admin[i].password)
                    {
                        loginStatus = true;
                        admin[i].currentUser = i;
                        cout << "\n\nLogin Successful\n" << "Welcome, " << donor[i].username;
                        goto success;
                    }
                }
            }
        }
        
        cout << "Incorrect name or password\n";
        maxAttempts++;
    } while (maxAttempts <= 3 || loginStatus == true);

    cout << "\nRan out of attempts.\n\nExiting program...\n\n";
    exit(EXIT_SUCCESS);

success:;
    if (cat == "donor") {
        donorScreen();
    } else if (cat == "recipient") {
        recipientScreen();
    } else if (cat == "admin") {
        adminScreen();
    }
}