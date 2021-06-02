#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Register(string cat) {
    string registerName, registerPassword;
    string fileName = cat + "s.txt";
    cin.ignore();
    fstream g;

    g.open(fileName, ios::in | ios::app);
            
    if (!g.is_open())
    
    {
        cout << "Error! Could not open file\n";
    }
    if (cat == "donor")
    {
        string fname, lname, dob, nationality, ethnicity, gender, existingConditions, bloodType, contactNumber, email, address, lastDonation = " ";
        cout << "\n\t\t\t\tDonor Registration";
        line(100, '-');
        cout << "\n" << "First Name: ";
        getline(cin, fname);
        cout << "Last Name: ";
        getline(cin, lname);
        cout << "Date of Birth (dd/mm/yyyy): ";
        getline(cin, dob);
        cout << "Nationality: ";
        getline(cin, nationality);
        cout << "Ethnicity: ";
        getline(cin, ethnicity);
        cout << "Gender: ";
        getline(cin, gender);
        cout << "Pre-Existing Conditions: ";
        getline(cin, existingConditions);
        cout << "Blood Type: ";
        getline(cin, bloodType);
        cout << "Contact Number: ";
        getline(cin, contactNumber);
        cout << "Email Address: ";
        getline(cin, email);
        cout << "Physical Address: ";
        getline(cin, address);
        cout << "Date of last donation (dd/mm/yyyy)(optional): ";
        getline(cin, lastDonation);
        cout << "\n" << "Username: ";
        getline(cin, registerName);
        cout << "Password: ";
        getline(cin, registerPassword);

        g << registerName << " . " << registerPassword << " . " << fname << " . " << lname << " . " << dob << " . " << nationality << " . " << ethnicity << " . " << gender << " . " << existingConditions << " . " << bloodType << " . " << contactNumber << " . " << email << " . " << address << " . " << lastDonation << " \n";

    } else if (cat == "recipient") {
        string recipientName, address, email, contactNumber;
        cout << "\n\t\t\t\tRecipient Registration";
        line(100, '-');
        cout << "\n" << "Recipient Name: ";
        getline(cin, recipientName);
        cout << "Physical Address: ";
        getline(cin, address);
        cout << "Email: ";
        getline(cin, email);
        cout << "Contact Number: ";
        getline(cin, contactNumber);
        cout << "\n" << "Username: ";
        getline(cin, registerName);
        cout << "Password: ";
        getline(cin, registerPassword);

        g << registerName << " . " << registerPassword << " . " << recipientName << " . " << address << " . " << email << " . " << contactNumber << " \n";

    }

    g.close();
}