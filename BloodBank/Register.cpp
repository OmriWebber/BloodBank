#include "header.h"

void Register(string cat) {
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
        donorList donor;
        cout << "\n\t\t\t\tDonor Registration";
        line(100, '-');
        cout << "\n" << "First Name: ";
        cin.getline(donor.fname, 30);
        cout << "Last Name: ";
        cin.getline(donor.lname, 30);
        cout << "Date of Birth (dd/mm/yyyy): ";
        cin.getline(donor.dob, 30);
        cout << "Nationality: ";
        cin.getline(donor.nationality, 30);
        cout << "Ethnicity: ";
        cin.getline(donor.ethnicity, 30);
        cout << "Gender: ";
        cin.getline(donor.gender, 30);
        cout << "Pre-Existing Conditions: ";
        cin.getline(donor.existingConditions, 30);
        cout << "Blood Type: ";
        cin.getline(donor.bloodType, 30);
        cout << "Contact Number: ";
        cin.getline(donor.contactNumber, 30);
        cout << "Email Address: ";
        cin.getline(donor.email, 30);
        cout << "Physical Address: ";
        cin.getline(donor.address, 30);
        cout << "City: ";
        cin.getline(donor.city, 30);
        cout << "Date of last donation (dd/mm/yyyy)(optional): ";
        cin.getline(donor.lastDonation, 30);
        cout << "\n" << "Username: ";
        cin.getline(donor.username, 30);
        cout << "Password: ";
        cin.getline(donor.password, 30);

        g.write(reinterpret_cast<char*>(&donor), sizeof(donorList));

    } else if (cat == "recipient") {
        recipientList recipient;
        cout << "\n\t\t\t\tRecipient Registration";
        line(100, '-');
        cout << "\n" << "Recipient Name: ";
        cin.getline(recipient.name, 30);
        cout << "Physical Address: ";
        cin.getline(recipient.address, 30);
        cout << "Email: ";
        cin.getline(recipient.email, 30);
        cout << "Contact Number: ";
        cin.getline(recipient.contactNumber, 30);
        cout << "\n" << "Username: ";
        cin.getline(recipient.username, 30);
        cout << "Password: ";
        cin.getline(recipient.password, 30);

        g.write(reinterpret_cast<char*>(&recipient), sizeof(recipientList));

    }

    g.close();
    main();
}