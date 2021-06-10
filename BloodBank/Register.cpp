#include "header.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Register(string cat) {
    Data data;
    string registerName, registerPassword;
    string fileName = cat + "s.dat";
    cin.ignore();
    fstream g;

    g.open(fileName, ios::in | ios::app | ios::binary);
            
    if (!g.is_open())
    
    {
        cout << "Error! Could not open file\n";
    }
    if (cat == "donor")
    {
        // CHANGE TO STRING INPUTS
        cout << "\n\t\t\t\tDonor Registration";
        line(100, '-');
        cout << "\n" << "First Name: ";
        getline(cin, data.donor->fname);
        cout << "Last Name: ";
        getline(cin, data.donor->lname);
        cout << "Date of Birth (dd/mm/yyyy): ";
        getline(cin, data.donor->dob);
        cout << "Nationality: ";
        getline(cin, data.donor->nationality);
        cout << "Ethnicity: ";
        getline(cin, data.donor->ethnicity);
        cout << "Gender: ";
        getline(cin, data.donor->gender);
        cout << "Pre-Existing Conditions: ";
        getline(cin, data.donor->existingConditions);
        cout << "Blood Type: ";
        getline(cin, data.donor->bloodType);
        cout << "Contact Number: ";
        getline(cin, data.donor->contactNumber);
        cout << "Email Address: ";
        getline(cin, data.donor->email);
        cout << "Physical Address: ";
        getline(cin, data.donor->address);
        cout << "City: ";
        getline(cin, data.donor->city);
        cout << "Date of last donation (dd/mm/yyyy)(optional): ";
        getline(cin, data.donor->lastDonation);
        cout << "\n" << "Username: ";
        getline(cin, data.donor->username);
        cout << "Password: ";
        getline(cin, data.donor->password);


        g.write(reinterpret_cast<char*>(&data.donor), sizeof(data.donor));

    } else if (cat == "recipient") {
        string recipientName, address, email, contactNumber;
        cout << "\n\t\t\t\tRecipient Registration";
        line(100, '-');
        cout << "\n" << "Recipient Name: ";
        cin.getline(data.recipient->name, 40);
        cout << "Physical Address: ";
        cin.getline(data.recipient->address, 60);
        cout << "Email: ";
        cin.getline(data.recipient->email, 40);
        cout << "Contact Number: ";
        cin.getline(data.recipient->contactNumber, 40);
        cout << "\n" << "Username: ";
        cin.getline(data.recipient->username, 40);
        cout << "Password: ";
        cin.getline(data.recipient->password, 40);

        g.write(reinterpret_cast<char*>(&data.recipient), sizeof(data.recipient));

    }

    g.close();
    main();
}