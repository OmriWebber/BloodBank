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
        donorList donorIn;
        cout << "\n\t\t\t\t\tDonor Registration";
        line(100, '-');
        cout << "\n";

        donorIn.id = reinterpret_cast<uint32_t>(&donorIn);

        do {
            cout << "First Name: ";
            cin.getline(donorIn.fname, 30);
        } while (!validate(donorIn.fname, "fname"));
        
        do
        {
            cout << "Last Name: ";
            cin.getline(donorIn.lname, 30);
        } while (!validate(donorIn.lname, "lname"));
        
        do
        {
            cout << "Date of Birth (dd/mm/yyyy): ";
            cin.getline(donorIn.dob, 30);
        } while (!validate(donorIn.dob, "dob"));
        
        do
        {
            cout << "Nationality: ";
            cin.getline(donorIn.nationality, 30);
        } while (!validate(donorIn.nationality, "nationality"));
        
        do
        {
            cout << "Ethnicity: ";
            cin.getline(donorIn.ethnicity, 30);
        } while (!validate(donorIn.ethnicity, "ethnicity"));
        
        do
        {
            cout << "Gender: ";
            cin.getline(donorIn.gender, 30);
        } while (!validate(donorIn.gender, "gender"));

        do
        {
            cout << "Pre-Existing Conditions: ";
            cin.getline(donorIn.existingConditions, 30);
        } while (!validate(donorIn.existingConditions, "existingConditions"));
        
        do
        {
            cout << "Blood Type: ";
            cin.getline(donorIn.bloodType, 30);
        } while (!validate(donorIn.bloodType, "bloodType"));
        

        do
        {
            cout << "Contact Number: ";
            cin.getline(donorIn.contactNumber, 30);
        } while (!validate(donorIn.contactNumber, "contactNumber"));
        

        do
        {
            cout << "Email Address: ";
            
            cin.getline(donorIn.email, 100);
        } while (!validate(donorIn.email, "email"));
        

        do
        {
            cout << "Physical Address: ";
            
            cin.getline(donorIn.address, 100);
        } while (!validate(donorIn.address, "address"));
        

        do
        {
            cout << "City: ";
            cin.getline(donorIn.city, 30);
        } while (!validate(donorIn.city, "city"));
        

        do
        {
            cout << "Date of last donation (dd/mm/yyyy)(optional): ";
            cin.getline(donorIn.lastDonation, 30);
        } while (!validate(donorIn.lastDonation, "lastDonation"));
        

        do
        {
            cout << "\n" << "Username: ";
            cin.getline(donorIn.username, 30);
        } while (!validate(donorIn.username, "username"));
        

        do
        {
            cout << "Password: ";
            cin.getline(donorIn.password, 30);
        } while (!validate(donorIn.password, "password"));
        
        g.write(reinterpret_cast<char*>(&donorIn), sizeof(donorList));

        cout << "ID : " << donorIn.id;
        cout << "\n\nRegistration Successful.\n\n";

    } else if (cat == "recipient") {
        recipientList recipientIn;
        cout << "\n\t\t\t\t\tRecipient Registration";
        line(100, '-');
        recipientIn.id = reinterpret_cast<uint32_t>(&recipientIn);
        cout << "\n" << "Recipient Name: ";
        cin.getline(recipientIn.name, 30);
        cout << "Physical Address: ";
        cin.getline(recipientIn.address, 100);
        cout << "Email: ";
        cin.getline(recipientIn.email, 100);
        cout << "Contact Number: ";
        cin.getline(recipientIn.contactNumber, 30);
        cout << "\n" << "Username: ";
        cin.getline(recipientIn.username, 30);
        cout << "Password: ";
        cin.getline(recipientIn.password, 30);

        g.write(reinterpret_cast<char*>(&recipientIn), sizeof(recipientList));
        
        cout << "\n\nRegistration Successful.\n\n";

    }

    g.close();
    main();
}