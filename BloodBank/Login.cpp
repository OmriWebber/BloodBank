#include "header.h"

void Login(string cat) {
    cout << "\n";
    char inName[30], inPassword[30];
    int currentUser;
    cin.ignore();
    cat[0] = toupper(cat[0]);
    cout << "\n\t\t\t\t" << cat << " Login";
    line(100, '-');
    int maxAttempts = 0;
    
    do
    {
        cout << "\n" << "Enter Username: ";
        cin.getline(inName, 30);
        cout << "Enter Password: ";
        cin.getline(inPassword, 30);

        if (cat == "Donor") {
            donorList* donor = donorData("donors.dat");
            for (int i = 0; i < donorLimit; i++){
                if (strcmp(inName, donor[i].username) == 0 && strcmp(inPassword, donor[i].password) == 0)
                {
                    currentUser = i;
                    cout << "\n\nLogin Successful\n" << "Welcome, " << donor[i].fname;
                    goto success;
                }
            }
        }
        else if (cat == "Recipient") {
            recipientList* recipient = recipientData("recipients.dat");
            
            for (int i = 0; i < recipientLimit; i++) {
                if (strcmp(inName, recipient[i].username) == 0 && strcmp(inPassword, recipient[i].password) == 0)
                {
                    cout << "Username " << i << ": " << recipient[i].username << endl;
                    currentUser = i;
                    cout << "\n\nLogin Successful\n" << "Welcome, " << recipient[i].username;
                    goto success;
                }
            }
        }
        else if (cat == "Admin") {
            adminList* admin = adminData("admins.txt");
            for (int i = 0; i < adminLimit; i++) {
                if (strcmp(inName, admin[i].username) == 0 && strcmp(inPassword, admin[i].password) == 0)
                {
                    currentUser = i;
                    cout << "\n\nLogin Successful\n" << "Welcome, " << admin[i].username;
                    goto success;
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
    if (cat == "Donor") {
        donorScreen(currentUser);
    } else if (cat == "Recipient") {
        recipientScreen(currentUser);
    } else if (cat == "Admin") {
        adminScreen(currentUser);
    }
}