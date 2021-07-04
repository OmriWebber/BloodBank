#include "header.h"

void approveRecipient();
void approveRecipientData(uint32_t);

void adminScreen() {

	donorList* donor = donorData("donors.dat");
	recipientList* recipient = recipientData("recipients.dat");
	bookingList* booking = bookingData("bookings.dat");


reset1:;
	int option, i = 0, p = 0;
	char check[30];
	cout << "\n\t\t\t\t\tAdmin Screen - Admin\n";
	line(100, '-');
	cout << "\n 1. View All Donors";
	cout << "\n 2. View All Recipients";
	cout << "\n 3. View All Bookings";
	cout << "\n 4. Search Donors by Blood Group";
	cout << "\n 5. Search Donors by location";
	cout << "\n 6. Approve Recipients";
	cout << "\n 7. Logout";
	cout << "\n";

	line(100, '-');
	cout << "\n\nEnter your Option : ";
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
		int count = 0;
		for (int i = 0; i < sizeof(recipient); i++)
		{
			if (booking[i].id == NULL) {

				break;

			}
			else {
				count++;
				cout << "\nResult #" << count << "\n";
				cout << "\nBooking ID : " << booking[i].id";
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
		approveRecipient();
		break;
	case 7:
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

void approveRecipient() {
	recipientList* recipient = recipientData("recipients.dat");
	string status;
	uint32_t selectedRecipientId;
	bool flag = false;
	do
	{
		line(100, '-');
		cout << "\n\t\t\t\t\tRecipient List\n\n";
		cout << "#\tName\t\tAddress\t\t\tEmail\t\t\tContact Number\tStatus";
		line(100, '-');
		for (int i = 0; i < recipientLimit; i++)
		{
			if (recipient[i].id != 0)
			{
				if (recipient[i].approved)
				{
					status = "Approved";
				}
				else {
					status = "Pending";
				}
				cout << i + 1;
				cout << "\t" << recipient[i].name;
				cout << "\t\t" << recipient[i].address;
				cout << "\t\t" << recipient[i].email;
				cout << "\t" << recipient[i].contactNumber;
				cout << "\t" << status << endl;
			}

		}
		line(100, '-');

		int selectedRecipientNum;
		char answer;
		cout << "\nEnter recipient # to approve : ";
		cin >> selectedRecipientNum;
		selectedRecipientNum--;
		selectedRecipientId = recipient[selectedRecipientNum].id;

		cout << "Confirm approval of " << recipient[selectedRecipientNum].name << " (y/n) : ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			flag = true;
		}
		else if (answer == 'n' || answer == 'N')
		{
			flag = false;
		}
	} while (!flag);
	approveRecipientData(selectedRecipientId);

	line(100, '-');
	cout << "\n";
	system("PAUSE");
	adminScreen();
}

void approveRecipientData(uint32_t selectedRecipient) {
	recipientList recipient;
	fstream g;
	g.open("recipients.dat", ios::in | ios::out | ios::binary);
	if (g.is_open()) {

		while (!g.eof()) {
			g.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
			int position = g.tellg();
			if (recipient.id == selectedRecipient) {
				g.seekp(position - (static_cast<unsigned __int64>(sizeof(recipient))));
				recipient.approved = true;
				g.write(reinterpret_cast<char*>(&recipient), sizeof(recipient));
				cout << "\n\nRecipient successfully approved.\n\n";
				break;
			}
		}
	}
	else {
		cout << "Error! Could not open file\n\n";
	}

	g.close();
}