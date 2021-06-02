#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>

using namespace std;

void Login(string cat) {
    donorList donor[10];
    string loginName, loginPassword, inName, inPassword, record, col, test;
    string fileName = (cat + "s.txt");
    vector<vector<string>> v1;
    vector<string> v2;
    cin.ignore();
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
    
    cat[0] = toupper(cat[0]);
    cout << "\n\t\t\t\t" << cat << " Login";
    line(100, '-');

    while (3)
    {
        cout << "\n" << "Enter Username: ";
        getline(cin, inName);
        cout << "Enter Password: ";
        getline(cin, inPassword);

        for (int i = 0; i < v1.size(); i++)
        {
            if (inName == donor[i].username && inPassword == donor[i].password)
            {
                cout << "Login Successful\n" << "Welcome, " << donor[i].username;
                break;
            }
            cout << "Incorrect name or password\n";
        }
    }

    cout << "Ran out of attempts.";

    if (cat == "donor") {
        
    } else if (cat == "recipient") {
        
    }

    f.close();
}