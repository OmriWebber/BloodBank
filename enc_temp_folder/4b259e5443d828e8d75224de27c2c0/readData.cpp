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
    Data data;
    string donorFile = ("donors.dat");
    string recipientFile = ("recipients.dat");
    string adminFile = ("admins.txt");

    donorData(donorFile, data);
    recipientData(recipientFile);
    adminData(adminFile);
    return data;
}

void donorData(string fileName, Data data) {
    ifstream f;
    int count = 0;
    f.open(fileName, ios::in | ios::binary);

    if (f.is_open())
    {
        while (f.read(reinterpret_cast<char*>(&data.donor), sizeof(data.donor)))
        {
            cout << count << "\n";
            
            cout << data.donor[count].fname;

            f.read(reinterpret_cast<char*>(&data.donor), sizeof(data.donor));
            /*
            *data.donor[count].fname = *data.donor->fname;
            *data.donor[count].lname = *data.donor->lname;
            *data.donor[count].dob = *data.donor->dob;
            *data.donor[count].nationality = *data.donor->nationality;
            *data.donor[count].ethnicity = *data.donor->ethnicity;
            *data.donor[count].gender = *data.donor->gender;
            *data.donor[count].existingConditions = *data.donor->existingConditions;
            *data.donor[count].bloodType = *data.donor->bloodType;
            *data.donor[count].contactNumber = *data.donor->contactNumber;
            *data.donor[count].email = *data.donor->email;
            *data.donor[count].address = *data.donor->address;
            *data.donor[count].city = *data.donor->city;
            *data.donor[count].lastDonation = *data.donor->lastDonation;
            *data.donor[count].password = *data.donor->password;
            *data.donor[count].username = *data.donor->username;
            data.donor[count].approved = data.donor->approved;
            */

            

            count++;
        }
    }
    else {
        cout << "\nFile unable to access ....";
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
