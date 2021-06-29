#include "header.h"

#pragma warning(disable : 4996)

int getAvailableTimes(char* , int);

string availableTime[8] = { "9:00", "10:00", "11:00", "12:00", "13:00", "14:00", "15:00", "16:00" };

void bookingWrite(uint32_t currentUser) {
	cout << "\n\t\t\t\t\tBooking Screen\n";
	line(100, '-');
    
    fstream g;

    g.open("bookings.dat", ios::in | ios::app | ios::out | ios::binary);

    if (!g.is_open())

    {
        cout << "Error! Could not open file\n";
    }
    else {
        donorList* donor = donorData("donors.dat");
        bookingList bookingIn;
 
        bookingIn.id = reinterpret_cast<uint32_t>(&bookingIn);

        for (int i = 0; i < donorLimit; i++)
        {
            if (currentUser == donor[i].id)
            {
                strcpy(bookingIn.fname, donor[i].fname);
                strcpy(bookingIn.lname, donor[i].lname);
                strcpy(bookingIn.dob, donor[i].dob);
                strcpy(bookingIn.existingConditions, donor[i].existingConditions);
            }
        }

        char contin = 'n';

        do
        {
            cin.ignore();
            bool timeEmpty = false;
            int numTimes = sizeof(availableTime) / sizeof(availableTime[0]);
            do
            {
                availableTime[0] = "9:00";
                availableTime[1] = "10:00";
                availableTime[2] = "11:00";
                availableTime[3] = "12:00";
                availableTime[4] = "13:00";
                availableTime[5] = "14:00";
                availableTime[6] = "15:00";
                availableTime[7] = "16:00";

                do
                {
                    cout << "\nDate of Appointment (dd/mm/yyyy) : ";
                    cin.getline(bookingIn.date, 30);
                } while (!validate(bookingIn.date, "date"));

                
                getAvailableTimes(bookingIn.date, numTimes);
            
                int count = 0;
                for (int i = 0; i < numTimes; i++) {
                    if (strcmp(availableTime[i].c_str(), "00:00") == 0) {
                        count++;
                    }
                }

                if (count == 8) {
                    timeEmpty = true;
                    cout << "\nThere are no available booking times for " << bookingIn.date << "\nPlease select another date...\n" << endl;
                } else {
                    timeEmpty = false;
                }
            } while (timeEmpty);

            do
            {
                string aTime = "";
                for (int i = 0; i < numTimes; i++) {
                    if (availableTime[i] != "00:00") {
                        aTime += (availableTime[i] + ", ");
                    }
                }

                int resize = 2;
                

                if (availableTime[7] != "16:00") {
                    resize = 4;
                }
                else if (availableTime[6] != "15:00" && availableTime[7] != "16:00") {
                    resize = 6;
                }
                else if (availableTime[5] != "14:00" && availableTime[6] != "15:00" && availableTime[7] != "16:00") {
                    resize = 8;
                }
                else if (availableTime[4] != "13:00" && availableTime[5] != "14:00" && availableTime[6] != "15:00" && availableTime[7] != "16:00") {
                    resize = 10;
                }
                else if (availableTime[3] != "12:00" && availableTime[4] != "13:00" && availableTime[5] != "14:00" && availableTime[6] != "15:00" && availableTime[7] != "16:00") {
                    resize = 12;
                }
                else if (availableTime[2] != "11:00" && availableTime[3] != "12:00" && availableTime[4] != "12:00" && availableTime[5] != "14:00" && availableTime[6] != "15:00" && availableTime[7] != "16:00") {
                    resize = 14;
                }
                else if (availableTime[1] != "10:00" && availableTime[2] != "11:00" && availableTime[3] != "12:00" && availableTime[4] != "12:00" && availableTime[5] != "14:00" && availableTime[6] != "15:00" && availableTime[7] != "16:00")
                {
                    resize = 16;
                }

                if (!aTime.empty() && !timeEmpty) {
                    aTime.resize(aTime.size() - resize);
                }
                cout << "\nAvailable Times : " << aTime;
            
                cout << "\nEnter Time (HH:MM 24hr eg. 13:00) : ";
                cin.getline(bookingIn.time, 30);
            } while (!validateTime(bookingIn.time, availableTime, numTimes));

            line(100, '-');
            cout << "\n\nConfirm Booking Details\n\n";
            cout << "\nBooking Name : " << bookingIn.fname << " " << bookingIn.lname;
            cout << "\nDate of Birth : " << bookingIn.dob;
            cout << "\nExisting Conditions : " << bookingIn.existingConditions;
            cout << "\nDate : " << bookingIn.date;
            cout << "\nTime : " << bookingIn.time;

            line(100, '-');

            cout << "\n\nConfirm your booking? (y/n) : ";
            cin >> contin;
        } while (contin == 'n' || contin == 'N');
        
        g.write(reinterpret_cast<char*>(&bookingIn), sizeof(bookingList));

        cout << "\n\nAppointment confirmed.\nBooking Complete\n\nReturning to Donor Screen\n\n";
        system("PAUSE");
    }
	
    g.close();
    donorScreen(currentUser);
}

int getAvailableTimes(char * date, int numTimes) {
    bookingList* booking = bookingData("bookings.dat");
    for (int i = 0; i < bookingLimit; i++)
    {

        for (int j = 0; j < 8; j++)
        {
            bool is_found = false;
            
            if (strcmp(booking[i].time, availableTime[j].c_str()) == 0 && strcmp(booking[i].date, date) == 0)
            {
                availableTime[j] = "00:00";
            }
        }
    }
    return numTimes;
}
