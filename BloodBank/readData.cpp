#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <stdio.h>

using namespace std;

struct Data readData() {
    string donorFile = ("donors.txt");
    string recipientFile = ("recipients.txt");
    string adminFile = ("admins.txt");

    donorData(donorFile);
    recipientData(recipientFile);
    adminData(adminFile);
}

void donorData(string fileName) {
    Data data;
    ifstream f;
    int count = 0;
    f.open(fileName, ios::in | ios::binary);

    if (!f.is_open()) {
        cout << "Could not open file " << fileName << "\n";

        if (f.is_open())
        {
            while (f.read(reinterpret_cast<char*>(&data.donor), sizeof(data.donor)))
            {
                cout << count << "\n";
                cout << "\nFirst Name: " << data.donor->fname;
                cout << "\nLast Name: " << data.donor->lname;
                cout << "\nDOB: " << data.donor->dob;
                cout << "\nNationality: " << data.donor->nationality;
                cout << "\nEthnicity: " << data.donor->ethnicity;
                cout << "\nGender: " << data.donor->gender;
                cout << "\nExisting Conditions: " << data.donor->existingConditions;
                cout << "\nBlood Type: " << data.donor->bloodType;
                cout << "\nContact Number: " << data.donor->contactNumber;
                cout << "\nEmail: " << data.donor->email;
                cout << "\nAddress: " << data.donor->address;
                cout << "\nCity: " << data.donor->city;
                cout << "\nLast Donation: " << data.donor->lastDonation;
                cout << "\nUsername: " << data.donor->password;
                cout << "\nPassword: " << data.donor->username;
                cout << "\nStatus: " << data.donor->approved;

                count++;
            }
        }
        else {
            cout << "\nFile unable to access ....";
        }
    }
    f.close();
}

void recipientData(string fileName) {
    Data data;
    ifstream f;
    int count = 0;
    f.open(fileName, ios::in | ios::binary);

    

    if (f.is_open())
    {
        cout << "test123";
        while (f.read(reinterpret_cast<char*>(&data.recipient), sizeof(data.recipient)))
        {
            cout << count << "\n";
            cout << "\nFirst Name: " << data.recipient->name;
            cout << "\nLast Name: " << data.recipient->address;
            cout << "\nDOB: " << data.recipient->email;
            cout << "\nNationality: " << data.recipient->contactNumber;
            cout << "\nUsername: " << data.recipient->username;
            cout << "\nPassword: " << data.recipient->password;
            cout << "\nStatus: " << data.recipient->approved;
            count++;
        }
    }
    else {
        cout << "\nFile unable to access ....";
    }
    f.close();
}

void adminData(string fileName) {

}
