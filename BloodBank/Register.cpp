#include "header.h"


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
 
        cout << "\n\t\t\t\tDonor Registration";
        line(100, '-');
        cout << "\n" << "First Name: ";
        cin.getline(data.donor->fname, 30);
        cout << "Last Name: ";
        cin.getline(data.donor->lname, 30);
        cout << "Date of Birth (dd/mm/yyyy): ";
        cin.getline(data.donor->dob, 30);
        cout << "Nationality: ";
        cin.getline(data.donor->nationality, 30);
        cout << "Ethnicity: ";
        cin.getline(data.donor->ethnicity, 30);
        cout << "Gender: ";
        cin.getline(data.donor->gender, 30);
        cout << "Pre-Existing Conditions: ";
        cin.getline(data.donor->existingConditions, 30);
        cout << "Blood Type: ";
        cin.getline(data.donor->bloodType, 30);
        cout << "Contact Number: ";
        cin.getline(data.donor->contactNumber, 30);
        cout << "Email Address: ";
        cin.getline(data.donor->email, 30);
        cout << "Physical Address: ";
        cin.getline(data.donor->address, 30);
        cout << "City: ";
        cin.getline(data.donor->city, 30);
        cout << "Date of last donation (dd/mm/yyyy)(optional): ";
        cin.getline(data.donor->lastDonation, 30);
        cout << "\n" << "Username: ";
        cin.getline(data.donor->username, 30);
        cout << "Password: ";
        cin.getline(data.donor->password, 30);


        g.write(reinterpret_cast<char*>(data.donor), sizeof(donorList));

    } else if (cat == "recipient") {
        string recipientName, address, email, contactNumber;
        cout << "\n\t\t\t\tRecipient Registration";
        line(100, '-');
        cout << "\n" << "Recipient Name: ";
        cin.getline(data.recipient->name, 30);
        cout << "Physical Address: ";
        cin.getline(data.recipient->address, 30);
        cout << "Email: ";
        cin.getline(data.recipient->email, 30);
        cout << "Contact Number: ";
        cin.getline(data.recipient->contactNumber, 30);
        cout << "\n" << "Username: ";
        cin.getline(data.recipient->username, 30);
        cout << "Password: ";
        cin.getline(data.recipient->password, 30);

        g.write(reinterpret_cast<char*>(data.recipient), sizeof(recipientList));

    }

    g.close();
    main();
}