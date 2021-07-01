#include "header.h"

void adminScreen() {

	donorList* donor = donorData("donors.dat");
	recipientList* recipient = recipientData("recipients.dat");
	bookingList* booking = bookingData("bookings.dat");


reset1:;
	int option, i = 0, p = 0;
	char check[30];
	cout << "\n\t\t\t\t\tAdmin Screen - Admin 1";
	line(100, '-');
	cout << "\n 1. View All Donors";
	cout << "\n 2. View All Recipients";
	cout << "\n 3. View All Bookings";
	cout << "\n 4. Search by Blood Group";
	cout << "\n 5. Search by location";
	cout << "\n 6. Logout.";
	cout << "\n";
	line(100, '-');

	line(100, '-');
	cout << "\n\nEnter your Option";
	cin >> option;

	switch (option) {
	case 1:

		for (int i = 0; i < sizeof(donor); i++)
		{
			if (donor[i].id == NULL) {

				break;

			}
			else {
				cout << "\n\t\tID \t\t\t: \t\t" << donor[i].id << endl;
				cout << "\t\tName \t\t\t: \t\t" << donor[i].fname << " " << donor[i].lname << endl;
				cout << "\t\tDate of Birth \t\t: \t\t" << donor[i].dob << endl;
				cout << "\t\tNationality \t\t: \t\t" << donor[i].nationality << endl;
				cout << "\t\tEthnicity \t\t: \t\t" << donor[i].ethnicity << endl;
				cout << "\t\tGender \t\t\t: \t\t" << donor[i].gender << endl;
				cout << "\t\tExisting Conditions \t: \t\t" << donor[i].existingConditions << endl;
				cout << "\t\tBlood Type \t\t: \t\t" << donor[i].bloodType << endl;
				cout << "\t\tContact Number \t\t: \t\t" << donor[i].contactNumber << endl;
				cout << "\t\tEmail \t\t\t: \t\t" << donor[i].email << endl;
				cout << "\t\tAddress \t\t: \t\t" << donor[i].address << "\n\t\t\t\t\t\t\t" << donor[i].city << endl;
				cout << "\t\tLast Donation \t\t: \t\t" << donor[i].lastDonation << endl;
				cout << endl;
				line(100, '-');
				cout << endl;
			}
		}
		goto reset1;
		break;
	case 2:
		
		for (int i = 0; i < sizeof(recipient); i++)
		{
			if (recipient[i].id == NULL) {

				break;

			}
			else {

				cout << "\n\t\tID \t\t\t: \t\t" << recipient[i].id << endl;
				cout << "\t\tName \t\t\t: \t\t" << recipient[i].name << endl;
				cout << "\t\tAddress \t\t: \t\t" << recipient[i].address << endl;
				cout << "\t\tEmail \t\t\t: \t\t" << recipient[i].email << endl;
				cout << "\t\tContact Number \t\t: \t\t" << recipient[i].contactNumber << endl;
				line(100, '-');
				cout << endl; 
			}
		};
			goto reset1;
			break;

	case 3:

		for (int i = 0; i < sizeof(recipient); i++)
		{
			if (booking[i].id == NULL) {

				break;

			}
			else {
				line(100, '-');
				cout << "\n\nConfirm Booking Details\n\n";
				cout << "\nBooking Name : " << booking[i].fname << " " << booking[i].lname;
				cout << "\nDate of Birth : " << booking[i].dob;
				cout << "\nExisting Conditions : " << booking[i].existingConditions;
				cout << "\nDate : " << booking[i].date;
				cout << "\nTime : " << booking[i].time;
				cout << "\n";
				line(100, '-');
			}
		}
		goto reset1; 
		break;
	case 4:

		p = 0; 
		cout << endl;
		line(100, '-'); 
		cout << endl; 
		cout << "Please Enter the Blood Type you want to search for : ";
		cin.ignore(); 
		cin.getline(check, 30);

		for (int i = 0; i < sizeof(donor); i++) {

			if (strcmp(donor[i].bloodType,check) == 0) {

				cout << "\n\t\tID \t\t\t: \t\t" << donor[i].id << endl;
				cout << "\t\tName \t\t\t: \t\t" << donor[i].fname << " " << donor[i].lname << endl;
				cout << "\t\tDate of Birth \t\t: \t\t" << donor[i].dob << endl;
				cout << "\t\tNationality \t\t: \t\t" << donor[i].nationality << endl;
				cout << "\t\tEthnicity \t\t: \t\t" << donor[i].ethnicity << endl;
				cout << "\t\tGender \t\t\t: \t\t" << donor[i].gender << endl;
				cout << "\t\tExisting Conditions \t: \t\t" << donor[i].existingConditions << endl;
				cout << "\t\tBlood Type \t\t: \t\t" << donor[i].bloodType << endl;
				cout << "\t\tContact Number \t\t: \t\t" << donor[i].contactNumber << endl;
				cout << "\t\tEmail \t\t\t: \t\t" << donor[i].email << endl;
				cout << "\t\tAddress \t\t: \t\t" << donor[i].address << "\n\t\t\t\t\t\t\t" << donor[i].city << endl;
				cout << "\t\tLast Donation \t\t: \t\t" << donor[i].lastDonation << endl;
				cout << endl;
				line(100, '-');
				cout << endl;
				p++;
			}

		}

		if (p == 0) {

			cout << endl << "No results were found... please refine your search. (try A+, O+, O- etc.) \n\n";

		}
		
		goto reset1;
		break;
	case 5:
		p = 0; 
		cout << endl;
		line(100, '-');
		cout << endl;
		cout << "Please Enter the City of the person you want to search for : ";
		cin.ignore();
		cin.getline(check, 30);

		for (int i = 0; i < sizeof(donor); i++) {

			if (strcmp(donor[i].city, check) == 0) {

				cout << "\n\t\tID \t\t\t: \t\t" << donor[i].id << endl;
				cout << "\t\tName \t\t\t: \t\t" << donor[i].fname << " " << donor[i].lname << endl;
				cout << "\t\tDate of Birth \t\t: \t\t" << donor[i].dob << endl;
				cout << "\t\tNationality \t\t: \t\t" << donor[i].nationality << endl;
				cout << "\t\tEthnicity \t\t: \t\t" << donor[i].ethnicity << endl;
				cout << "\t\tGender \t\t\t: \t\t" << donor[i].gender << endl;
				cout << "\t\tExisting Conditions \t: \t\t" << donor[i].existingConditions << endl;
				cout << "\t\tBlood Type \t\t: \t\t" << donor[i].bloodType << endl;
				cout << "\t\tContact Number \t\t: \t\t" << donor[i].contactNumber << endl;
				cout << "\t\tEmail \t\t\t: \t\t" << donor[i].email << endl;
				cout << "\t\tAddress \t\t: \t\t" << donor[i].address << "\n\t\t\t\t\t\t\t" << donor[i].city << endl;
				cout << "\t\tLast Donation \t\t: \t\t" << donor[i].lastDonation << endl;
				cout << endl;
				line(100, '-');
				cout << endl;

			}





		}

		if (p == 0) {

			cout << endl << "No results were found... please refine your search.\n\n";

		}


		goto reset1;
		break;
	case 6:
		cout << "\nLogging out . . .\n\n";
		system("PAUSE");
		main();
		break;
	default:
		cout << "\n\nPlease enter a valid option...\n";
		goto reset1;
		break;

		}

















	}
