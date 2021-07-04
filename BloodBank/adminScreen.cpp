#include "header.h"

void viewAllDonor();
void viewAllRecipient();
void approveRecipient();
void updateDonorInfo();
void donorReport();
void recipientReport();
void approveRecipientData(uint32_t);

void adminScreen() {
	char option;

	line(100, '-');
	cout << "\n\t\t\t\t\tAdmin Menu\n";
	line(100, '-');
	cout << "\n 1. View all donors";
	cout << "\n 2. View all recipients";
	cout << "\n 3. Approve recipients";
	cout << "\n 4. Update donor information";
	cout << "\n 5. Donor report";
	cout << "\n 6. Recipient Report";
	cout << "\n 7. Logout";
	cout << "\n";
	line(100, '-');

reset1:;
	cout << "\nEnter your option: ";
	cin >> option;

	switch (option)
	{
	case '1':
		viewAllDonor();
		break;
	case '2':
		viewAllRecipient();
		break;
	case '3':
		approveRecipient();
		break;
	case '4':
		updateDonorInfo();
		break;
	case '5':
		donorReport();
		break;
	case '6':
		recipientReport();
		break;
	case '7':
		cout << "\nLogging out . . .\n\n";
		system("PAUSE");
		main();
		break;
	default:
		cout << "\nPlease enter a valid value\n";
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
				cout << i+1;
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

void updateDonorInfo() {

}

void donorReport() {
	donorList* donor = donorData("donors.dat");
	line(100, '-');
	cout << "#\tName\t\tAddress\t\t\tEmail\t\t\tContact Number";
	line(100, '-');
	int totalCount = 0;
	for (int i = 0; i < recipientLimit; i++)
	{
		if (donor[i].id != 0)
		{
			totalCount++;
			if (donor[i].city) {

			}
		}

		

	}
}

void recipientReport() {

}