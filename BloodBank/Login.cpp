#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <stdio.h>

using namespace std;

void Login(Data data, string cat) {
    
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
    int v1Size = v1.size();
    if (cat == "donor")
    {
        for (int i = 0; i < v1Size; i++)
        {
            data.donor[i].username = v1[i][0];
            data.donor[i].password = v1[i][1];
            data.donor[i].fname = v1[i][2];
            data.donor[i].lname = v1[i][3];
            data.donor[i].dob = v1[i][4];
            data.donor[i].nationality = v1[i][5];
            data.donor[i].ethnicity = v1[i][6];
            data.donor[i].gender = v1[i][7];
            data.donor[i].existingConditions = v1[i][8];
            data.donor[i].bloodType = v1[i][9];
            data.donor[i].contactNumber = v1[i][10];
            data.donor[i].email = v1[i][11];
            data.donor[i].address = v1[i][12];
            data.donor[i].lastDonation = v1[i][13];
        }
    }
    else if (cat == "recipient")
    {
        for (int i = 0; i < v1Size; i++)
        {
            data.recipient[i].username = v1[i][0];
            data.recipient[i].password = v1[i][1];
            data.recipient[i].name = v1[i][2];
            data.recipient[i].address = v1[i][3];
            data.recipient[i].email = v1[i][4];
            data.recipient[i].contactNumber = v1[i][5];

        }
    }
    else if (cat == "admin")
    {
        for (int i = 0; i < v1Size; i++)
        {
            data.admin[i].username = v1[i][0];
            data.admin[i].password = v1[i][1];
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

        if (cat == "Donor") {
            if (!loginStatus)
            {
                for (int i = 0; i < v1Size; i++)
                {
                    if (inName == data.donor[i].username && inPassword == data.donor[i].password)
                    {
                        loginStatus = true;
                        currentUser = i;
                        cout << "\n\nLogin Successful\n" << "Welcome, " << data.donor[i].username;
                        goto success;
                    }
                }
            }
        }
        else if (cat == "Recipient") {
            if (!loginStatus)
            {
                for (int i = 0; i < v1Size; i++)
                {
                    if (inName == data.recipient[i].username && inPassword == data.recipient[i].password)
                    {
                        loginStatus = true;
                        currentUser = i;
                        cout << "\n\nLogin Successful\n" << "Welcome, " << data.recipient[i].username;
                        goto success;
                    }
                }
            }
        }
        else if (cat == "Admin") {
            if (!loginStatus)
            {
                for (int i = 0; i < v1Size; i++)
                {
                    if (inName == data.admin[i].username && inPassword == data.admin[i].password)
                    {
                        loginStatus = true;
                        currentUser = i;
                        cout << "\n\nLogin Successful\n" << "Welcome, " << data.admin[i].username;
                        goto success;
                    }
                }
            }
        }
        
        cout << "Incorrect name or password\n";
        maxAttempts++;
    } while (maxAttempts < 3);

    cout << "\n\nYou have ran out of login attempts.\n\nGoing back to main menu . . .\n\n";
    system("PAUSE");
    main();

success:;
    if (cat == "donor") {
        donorScreen(currentUser);
    } else if (cat == "recipient") {
        recipientScreen(currentUser);
    } else if (cat == "admin") {
        adminScreen(currentUser);
    }
}