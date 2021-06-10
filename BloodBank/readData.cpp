#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <stdio.h>

using namespace std;


void readData(Data data) {
    string donorFile = ("donors.dat");
    string recipientFile = ("recipients.dat");
    string adminFile = ("admins.txt");

    
    donorData(donorFile, data);
    recipientData(recipientFile);
    adminData(adminFile);
}

void donorData(string fileName, Data data) {
    ifstream f;
    TempDonor tempDonor[20];
    string record;
    int count = 0;
    f.open(fileName, ios::in | ios::binary);

    if (f.is_open())
    {
        
        while (f.read(reinterpret_cast<char*>(&data.donor), sizeof(data.donor))) {
            tempDonor[count].lname = data.donor->lname;
            tempDonor[count].dob = data.donor->fname;
            tempDonor[count].nationality = data.donor->fname;
            tempDonor[count].ethnicity = data.donor->fname;
            tempDonor[count].gender = data.donor->fname;
            tempDonor[count].existingConditions = data.donor->fname;
            tempDonor[count].bloodType = data.donor->fname;
            tempDonor[count].contactNumber = data.donor->fname;
            tempDonor[count].email = data.donor->fname;
            tempDonor[count].address = data.donor->fname;
            tempDonor[count].city = data.donor->fname;
            tempDonor[count].lastDonation = data.donor->fname;
            tempDonor[count].username = data.donor->username;
            tempDonor[count].password = data.donor->password;
            tempDonor[count].approved = data.donor->approved;

            cout << tempDonor[0].username << " " << tempDonor[0].password << "\n";

            count++;
            
            
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
