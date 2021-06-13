#include "header.h"

struct donorList* donorData(string fileName) {
    donorList donor[donorLimit];
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
    recipientList recipient[recipientLimit];
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
    adminList admin[adminLimit];
    ifstream a;
    a.open(fileName, ios::in | ios::binary);

    if (a.is_open())
    {
        a.read(reinterpret_cast<char*>(admin), adminLimit * sizeof(adminList));
    }
    else {
        cout << "\nFile unable to access ....";
    }
    a.close();
    return admin;
}
