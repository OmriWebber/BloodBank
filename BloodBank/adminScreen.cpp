// Include header file
#include "header.h"

#pragma warning(disable : 4996)

// Declare local functions
void viewAllDonor();
void viewAllRecipient();
void viewAllBooking();
void approveRecipient();
void approveRecipientData(uint32_t);
void updateDonorInfo();
void updateDonorInfoData(uint32_t, char[100]);

void adminScreen() {


	// Admin Menu
	cout << "\n\t\t\t\t\tAdmin Menu\n";
	line(100, '-');
	cout << "\n 1. View All Donors";
	cout << "\n 2. View All Recipients";
	cout << "\n 3. View All Bookings";
	cout << "\n 4. Search Donors by Blood Group";
	cout << "\n 5. Search Donors by location";
	cout << "\n 6. Update Donor Existing Conditions";
	cout << "\n 7. Approve Recipients";
	cout << "\n 8. Logout";
	cout << "\n";
	int option;
reset1:;
	line(100, '-');
	cout << "\n\nEnter your Option : ";
	cin >> option;

	switch (option) {
	case 1:
		// View all Donors
		viewAllDonor();
		break;
	case 2:
		// View all Recipients
		viewAllRecipient();
		break;
	case 3:
		// View all bookings
		viewAllBooking();
		break;
	case 4:
		// Search Donor by blood type
		char bloodtype_s[30];
		cin.ignore();
		do
		{
			cout << "Enter Blood Type: ";
			cin.getline(bloodtype_s, 30);
		} while (!validate(bloodtype_s, "bloodType"));
		searchByBloodType(bloodtype_s);
		goto reset1;
		break;
	case 5:
		// Search Donors by Location
		char city_s[30];
		cin.ignore();
		do
		{
			cout << "Enter Location: ";
			cin.getline(city_s, 30);
		} while (!validate(city_s, "city"));
		searchByLocation(city_s);
		goto reset1;
		break;
	case 6:
		// Call updateDonorInfo function which update donors existing conditions
		updateDonorInfo();
		break;
	case 7:
		// Call approveRecipients Function
		approveRecipient();
		break;
	case 8:
		// Logout, go back to main menu
		cout << "\nLogging out . . .\n\n";
		system("PAUSE");
		main();
		break;
	default:
		// Input validation
		cout << "\n\nPlease enter a valid option...\n";
		goto reset1;
		break;

	}
}

void viewAllDonor() {
	donorList* donor = donorData("donors.dat");
	line(100, '-');

	int count = 0;
	for (int i = 0; i < donorLimit; i++)
	{
		if (donor[i].id != 0) {
			count++;
		}

	}
	cout << "\n\t\t\t\t\tDisplaying All Donors - Results found : " << count << "\n";
	for (int i = 0; i < donorLimit; i++)
	{
		if (donor[i].id != 0)
		{
			cout << "\n\tResult #" << i + 1 << "\n";
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
			cout << "\t\tLast Donation \t\t: \t\t" << donor[i].lastDonation << "\n\n";
		}

	}
	line(100, '-');

	system("PAUSE");
	adminScreen();
}

void viewAllRecipient() {
	recipientList* recipient = recipientData("recipients.dat");
	string status;
	line(100, '-');

	int count = 0;
	for (int i = 0; i < recipientLimit; i++)
	{
		if (recipient[i].id != 0)
		{
			count++;
		}

	}

	cout << "\n\t\t\t\tDisplaying All Recipients - Results found : " << count << "\n\n";
	cout << "ID\t\tName\t\tAddress\t\t\tEmail\t\t\tContact Number\tStatus";

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
			cout << "\n" << recipient[i].id;
			cout << "\t" << recipient[i].name;
			cout << "\t\t" << recipient[i].address;
			cout << "\t\t" << recipient[i].email;
			cout << "\t" << recipient[i].contactNumber;
			cout << "\t" << status << endl;
		}
	}
	line(100, '-');

	system("PAUSE");
	adminScreen();
}

void viewAllBooking() {
	bookingList* booking = bookingData("bookings.dat");
	int count = 0;
	for (int i = 0; i < recipientLimit; i++)
	{
		if (booking[i].id != 0) {
			count++;
		}
	}

	cout << "\n\t\t\t\t\tDisplaying All Bookings - Results found : " << count << "\n";
	for (int i = 0; i < bookingLimit; i++)
	{
		if (booking[i].id != 0)
		{
			cout << "\nResult #" << count << "\n";
			cout << "\nBooking ID : " << booking[i].id;
			cout << "\nBooking Name : " << booking[i].fname << " " << booking[i].lname;
			cout << "\nDate of Birth : " << booking[i].dob;
			cout << "\nExisting Conditions : " << booking[i].existingConditions;
			cout << "\nDate : " << booking[i].date;
			cout << "\nTime : " << booking[i].time;
			cout << "\n";
			line(100, '-');
		}

	}
	line(100, '-');

	system("PAUSE");
	adminScreen();
}

void approveRecipient() {
	// Get recipient data from file
	recipientList* recipient = recipientData("recipients.dat");
	string status;
	uint32_t selectedRecipientId;
	bool flag = false;
	do
	{
		// Display all recipients
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
		}

// Update new approved recipient
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

void updateDonorInfo() {
	// Get Donor data from file
	donorList* donor = donorData("donors.dat");
	string status;
	uint32_t selectedDonorId;
	bool flag = false;
	char answer[100];
	do
	{
		// Display all Donors
		line(100, '-');
		cout << "\n\t\t\t\t\tDonor List\n\n";
		cout << "#\tName\t\t\tBlood Type\t\tEmail\t\t\tExisting Conditions";
		line(100, '-');
		for (int i = 0; i < donorLimit; i++)
		{
			if (donor[i].id != 0)
			{
				cout << i + 1;
				cout << "\t" << donor[i].fname << " " << donor[i].lname;
				cout << "\t\t" << donor[i].bloodType;
				cout << "\t\t" << donor[i].email;
				cout << "\t" << donor[i].existingConditions << endl;
			}

		}
		line(100, '-');

		int selectedDonorNum;
		char confirmAnswer;
		cout << "\nEnter donor # to update : ";
		cin >> selectedDonorNum;
		selectedDonorNum--;
		selectedDonorId = donor[selectedDonorNum].id;
		cin.ignore();

		do
		{
			cout << "Enter updated conditions: ";
			cin.getline(answer, 100);
		} while (!validate(answer, "existingConditions"));

		line(100, '-');

		cout << "\nConfirm update of " << donor[selectedDonorNum].fname << " " << donor[selectedDonorNum].lname << " (y/n) : ";
		cin >> confirmAnswer;

		if (confirmAnswer == 'y' || confirmAnswer == 'Y')
		{
			flag = true;
		}
		else if (confirmAnswer == 'n' || confirmAnswer == 'N')
		{
			flag = false;
		}
	} while (!flag);
	updateDonorInfoData(selectedDonorId, answer);

	line(100, '-');
	cout << "\n";
	system("PAUSE");
	adminScreen();
}

// Update new approved recipient
void updateDonorInfoData(uint32_t selectedDonor, char answer[100]) {
	donorList donor;
	fstream g;
	g.open("donors.dat", ios::in | ios::out | ios::binary);
	if (g.is_open()) {

		while (!g.eof()) {
			g.read(reinterpret_cast<char*>(&donor), sizeof(donor));
			int position = g.tellg();
			if (donor.id == selectedDonor) {
				g.seekp(position - (static_cast<unsigned __int64>(sizeof(donor))));
				strcpy(donor.existingConditions, answer);
				g.write(reinterpret_cast<char*>(&donor), sizeof(donor));
				cout << "\n\nDonor existing conditions updated successfully.\n\n";
				break;
			}
		}
	}
	else {
		cout << "Error! Could not open file\n\n";
	}

	g.close();
}