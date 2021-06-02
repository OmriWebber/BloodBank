#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void Login(string cat) {
    string loginName, loginPassword, inName, inPassword, row;
    string fileName = cat.append("s.txt");
    cin.ignore();
    ifstream f(fileName);

    if (!f.is_open()) {
        cout << "could not open file\n";
    }
    
    cat[0] = toupper(cat[0]);
    cout << "\n\t\t\t\t" << cat << " Login";
    line(100, '-');

    getline(f, row, '\n');
    stringstream(row);
    getline(row, loginName, '.');
    getline(f, loginPassword, '.');

    cout << loginName << " : " << loginPassword;

    while (3)
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

    cout << "Ran out of attempts.";

    if (cat == "donor") {
        
    } else if (cat == "recipient") {
        
    }

    f.close();
}