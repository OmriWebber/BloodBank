#include "header.h"

donorList donor[donorLimit];
recipientList recipient[recipientLimit];
adminList admin[adminLimit];

struct donorList* donorData(string fileName) {
    ifstream d;
    d.open(fileName, ios::in | ios::binary);

    if (d.is_open())
    {
        d.read(reinterpret_cast<char*>(donor), donorLimit * sizeof(donorList));
    }
    else {
        cout << "\nFile unable to access ....";
    }
    d.close();
    return donor;
}

struct recipientList* recipientData(string fileName) {
    ifstream r;
    r.open(fileName, ios::in | ios::binary);

    if (r.is_open())
    {
        r.read(reinterpret_cast<char*>(recipient), recipientLimit * sizeof(recipientList));
    }
    else {
        cout << "\nFile unable to access ....";
    }
    r.close();
    return recipient;
}

struct adminList* adminData(string fileName) {
    ifstream a;
    string line;
    a.open(fileName, ios::out);

    if (!a)
    {
        int i = 0;
        
        while (!a.eof()){
            if (getline(a, line))
            {
                istringstream ss(line);
                ss >> admin[i].username >> admin[i].password;
            }
            i++;
        }
        cout << i;
    } else {
        cout << "\nFile unable to access ....\n";
    }
    a.close();
    return admin;
}