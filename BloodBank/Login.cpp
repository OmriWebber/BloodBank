#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <stdio.h>

using namespace std;

void Login(Data data, string cat) {
    
    string inName, inPassword;
    int currentUser;
    bool loginStatus = false;
    cin.ignore();

    cat[0] = toupper(cat[0]);
    cout << "\n\t\t\t\t" << cat << " Login";
    line(100, '-');
    int maxAttempts = 0;
    
    do
    {
        cout << "\n" << "Enter Username: ";
        getline(cin, inName);
        cout << "Enter Password: ";
        getline(cin, inPassword);

        if (cat == "Donor") {
            int size = sizeof(data.donor) / sizeof(data.donor[0]);
            if (!loginStatus)
            {
                for (int i = 0; i < size; i++)
                {
                    if (inName == data.donor[i].username && inPassword == data.donor[i].password)
                    {
                        loginStatus = true;
                        currentUser = data.donor->currentUser;
                        cout << "\n\nLogin Successful\n" << "Welcome, " << data.donor[i].username;
                        goto success;
                    }
                }
            }
        }
        else if (cat == "Recipient") {
            int size = sizeof(data.recipient) / sizeof(data.recipient[0]);
            if (!loginStatus)
            {
                for (int i = 0; i < size; i++)
                {
                    if (inName == data.recipient[i].username && inPassword == data.recipient[i].password)
                    {
                        loginStatus = true;
                        currentUser = data.recipient->currentUser;
                        cout << "\n\nLogin Successful\n" << "Welcome, " << data.recipient[i].username;
                        goto success;
                    }
                }
            }
        }
        else if (cat == "Admin") {
            int size = sizeof(data.admin) / sizeof(data.admin[0]);
            if (!loginStatus)
            {
                for (int i = 0; i < size; i++)
                {
                    if (inName == data.admin[i].username && inPassword == data.admin[i].password)
                    {
                        loginStatus = true;
                        currentUser = data.admin->currentUser;
                        cout << "\n\nLogin Successful\n" << "Welcome, " << data.admin[i].username;
                        goto success;
                    }
                }
            }
        }
        
        cout << "Incorrect name or password\n";
        maxAttempts++;
    } while (maxAttempts < 3);

    cout << "\n\nYou have ran out of login attempts.\n\nGoing back to main menu . . .\n\n";
    system("PAUSE");
    main();

success:;
    if (cat == "donor") {
        donorScreen(data, currentUser);
    } else if (cat == "recipient") {
        recipientScreen(data, currentUser);
    } else if (cat == "admin") {
        adminScreen(data, currentUser);
    }
}