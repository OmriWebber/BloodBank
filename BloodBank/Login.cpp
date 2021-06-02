#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Login(string cat) {
    string loginName, loginPassword, inName, inPassword;
    string fileName = cat.append("s.txt");
    cin.ignore();
    fstream g;

    g.open(fileName, ios::out);

    if (!g.is_open()) {
        cout << "could not open file\n";
    }
    
    cat[0] = toupper(cat[0]);
    cout << "\n\t\t\t\t" << cat << " Login";
    line(100, '-');

    getline(g, loginName, '.');
    getline(g, loginPassword, '.');


    while (1)
    {
        cout << "\n" << "Enter Username: ";
        getline(cin, inName);
        cout << "Enter Password: ";
        getline(cin, inPassword);

        if (inName == loginName && inPassword == loginPassword)
        {
            cout << "Login Successful\n" << "Welcome, " << inName;
            break;
        }
        cout << "Incorrect name or password\n";
    }

    if (cat == "donor") {
        
    } else if (cat == "recipient") {
        
    }

    g.close();
}