#include "header.h"

donorList donor[donorLimit];
recipientList recipient[recipientLimit];
bookingList booking[bookingLimit];


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

struct bookingList* bookingData(string fileName) {
    ifstream b;
    b.open(fileName, ios::in | ios::binary);

    if (b.is_open())
    {
        b.read(reinterpret_cast<char*>(booking), bookingLimit * sizeof(bookingList));
    }
    else {
        cout << "\nFile unable to access ....";
    }
    b.close();
    return booking;
}
