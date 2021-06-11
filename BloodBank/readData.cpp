#include "header.h"


using namespace std;

TempDonor tempDonor;

void readData(Data data) {
   
    string donorFile = ("donors.dat");
    string recipientFile = ("recipients.dat");
    string adminFile = ("admins.txt");

    donorData(donorFile, data);
    recipientData(recipientFile);
    adminData(adminFile);


    for (int i = 0; i < 3; i++)
    {
        cout << data.donor[i].fname << " : " << "\n";
    }
}

void donorData(string fileName, Data data) {
    ifstream f;
    
    int count = 0;
    f.open(fileName, ios::in | ios::binary);

    if (f.is_open())
    {
        
        while (f.read(reinterpret_cast<char*>(&tempDonor), sizeof(TempDonor))) {
            for (int i = 0; i < 40; i++)
            {
                data.donor[count].fname = tempDonor.fname;
                data.donor[count].lname = tempDonor.lname;
                data.donor[count].dob = tempDonor.dob;
                data.donor[count].nationality = tempDonor.nationality;
                data.donor[count].ethnicity = tempDonor.ethnicity;
                data.donor[count].gender = tempDonor.gender;
                data.donor[count].existingConditions = tempDonor.existingConditions;
                data.donor[count].email = tempDonor.email;
                data.donor[count].address = tempDonor.address;
                data.donor[count].city = tempDonor.city;
                data.donor[count].lastDonation = tempDonor.lastDonation;
                data.donor[count].username = tempDonor.username;
                data.donor[count].password = tempDonor.password;
                data.donor[count].approved = tempDonor.approved;
            }
            count++;

            /*
            *data.donor[count].fname = *data.donor->fname;
            *data.donor[count].lname = *data.donor->lname;
            *data.donor[count].dob = *data.donor->dob;
            *data.donor[count].nationality = *data.donor->nationality;
            *data.donor[count].ethnicity = *data.donor->ethnicity;
            *data.donor[count].gender = *data.donor->gender;
            *data.donor[count].existingConditions = *data.donor->existingConditions;
            *data.donor[count].bloodType = *data.donor->bloodType;
            *data.donor[count].contactNumber = *data.donor->contactNumber;
            *data.donor[count].email = *data.donor->email;
            *data.donor[count].address = *data.donor->address;
            *data.donor[count].city = *data.donor->city;
            *data.donor[count].lastDonation = *data.donor->lastDonation;
            *data.donor[count].password = *data.donor->password;
            *data.donor[count].username = *data.donor->username;
            data.donor[count].approved = data.donor->approved;
            */
        }
    }
    else {
        cout << "\nFile unable to access ....";
    }
    f.close();
}

void recipientData(string fileName) {
    Data data;
    ifstream f;
    int count = 0;
    f.open(fileName, ios::in | ios::binary);

    

    if (f.is_open())
    {
        while (f.read(reinterpret_cast<char*>(&data.recipient), sizeof(data.recipient)))
        {
            
        }
    }
    else {
        cout << "\nFile unable to access ....";
    }
    f.close();
}

void adminData(string fileName) {

}
