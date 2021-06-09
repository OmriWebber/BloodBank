#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <stdio.h>

using namespace std;


void donorData(Data data, string fileName) {
    string record, col;
    int t = 0;
    vector<vector<string>> v1;
    vector<string> v2;

    ifstream f(fileName);
    if (!f.is_open()) {
        cout << "Could not open file " << fileName << "\n";
    }
    
    while (getline(f, record, '|')) {
        stringstream s(record);
        while (getline(s, col, ',')) {
            v2.push_back(col);
            
        }
        v1.push_back(v2);
        t++;
    }
    cout << t;
    int donorSize = v1.size();

    for (int i = 0; i < donorSize; i++)
    {
        data.donor[i].username = v1[i][0];
        cout << v1[i][0];
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
        data.donor[i].city = v1[i][13];
        data.donor[i].lastDonation = v1[i][14];
        
    }
    f.close();

    for (int i = 0; i < donorSize; i++)
    {
        cout << data.donor[i].username << " : " << data.donor[i].password << " " << i << "\n" << v1[i][0] << "\n";
    }
}

void recipientData(Data data, string fileName) {
    string record, col;
    vector<vector<string>> v1;
    vector<string> v2;
    ifstream f(fileName);
    if (!f.is_open()) {
        cout << "Could not open file " << fileName << "\n";
    }

    while (getline(f, record, '|')) {
        stringstream s(record);
        while (getline(s, col, ',')) {
            v2.push_back(col);
        }
        v1.push_back(v2);
    }
    int recipientSize = v1.size();

    for (int i = 0; i < recipientSize; i++)
    {
        data.recipient[i].username = v1[i][0];
        data.recipient[i].password = v1[i][1];
        data.recipient[i].name = v1[i][2];
        data.recipient[i].address = v1[i][3];
        data.recipient[i].email = v1[i][4];
        data.recipient[i].contactNumber = v1[i][5];
    }
    f.close();
}

void adminData(Data data, string fileName) {
    string record, col;
    vector<vector<string>> v1;
    vector<string> v2;
    ifstream f(fileName);
    if (!f.is_open()) {
        cout << "Could not open file " << fileName << "\n";
    }

    while (getline(f, record, '|')) {
        stringstream s(record);
        while (getline(s, col, ',')) {
            v2.push_back(col);
        }
        v1.push_back(v2);
    }
    
    int adminSize = v1.size();

    for (int i = 0; i < adminSize; i++)
    {
        data.admin[i].username = v1[i][0];
        data.admin[i].password = v1[i][1];
    }
    f.close();
}

struct Data readData(Data data) {
    string donorFile = ("donors.txt");
    string recipientFile = ("recipients.txt");
    string adminFile = ("admins.txt");

    donorData(data, donorFile);
    recipientData(data, recipientFile);
    adminData(data, adminFile);

    for (int i = 0; i < 4; i++)
    {
        cout << data.donor[i].username << " : " << data.donor[i].password;
    }
    return data;
}