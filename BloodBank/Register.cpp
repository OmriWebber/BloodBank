#include "header.h"


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
 
        cout << "\n\t\t\t\tDonor Registration";
        line(100, '-');
        cout << "\n" << "First Name: ";
        getline(cin, data.donor->fname);
        cout << "Last Name: ";
        cin.getline(data.donor->lname, 40);
        cout << "Date of Birth (dd/mm/yyyy): ";
        cin.getline(data.donor->dob, 40);
        cout << "Nationality: ";
        cin.getline(data.donor->nationality, 40);
        cout << "Ethnicity: ";
        cin.getline(data.donor->ethnicity, 40);
        cout << "Gender: ";
        cin.getline(data.donor->gender, 40);
        cout << "Pre-Existing Conditions: ";
        cin.getline(data.donor->existingConditions, 40);
        cout << "Blood Type: ";
        cin.getline(data.donor->bloodType, 40);
        cout << "Contact Number: ";
        cin.getline(data.donor->contactNumber, 40);
        cout << "Email Address: ";
        cin.getline(data.donor->email, 40);
        cout << "Physical Address: ";
        cin.getline(data.donor->address, 40);
        cout << "City: ";
        cin.getline(data.donor->city, 40);
        cout << "Date of last donation (dd/mm/yyyy)(optional): ";
        cin.getline(data.donor->lastDonation, 15);
        cout << "\n" << "Username: ";
        cin.getline(data.donor->username, 50);
        cout << "Password: ";
        cin.getline(data.donor->password, 40);


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