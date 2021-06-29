#include "header.h"

#pragma warning(disable : 4996)

void recipientScreen(uint32_t currentUser) {
	recipientList* recipient = recipientData("recipients.dat");
	char option;

	cout << "\n\n\t\t\t\t\tYour Profile\n";
	line(100, '-');

	for (int i = 0; i < recipientLimit; i++)
	{
		if (currentUser == recipient[i].id)
		{
			cout << "\n\t\tID \t\t\t: \t\t" << recipient[i].id << endl;
			cout << "\t\tName \t\t\t: \t\t" << recipient[i].name << endl;
			cout << "\t\tAddress \t\t: \t\t" << recipient[i].address << endl;
			cout << "\t\tEmail \t\t\t: \t\t" << recipient[i].email << endl;
			cout << "\t\tContact Number \t\t: \t\t" << recipient[i].contactNumber << endl;
		}

	}
retry0:;
	line(100, '-');
	cout << "\n\t\t\t\tRecipient Menu - User ID: " << currentUser << endl;
	cout << "\n 1. View donor information by blood type";
	cout << "\n 2. View donor information by location";
	cout << "\n 3. Search donor by name";
	cout << "\n 4. Logout";
	cout << "\n";
	line(100, '-');

retry1:;
	cout << "\nEnter your option: ";
	cin >> option;

	switch (option)
	{
	case '1':
		char bloodtype_s[30];
		cin.ignore();
		do
		{
			cout << "Enter Blood Type: ";
			cin.getline(bloodtype_s, 30);
		} while (!validate(bloodtype_s, "bloodType"));
		searchByBloodType(bloodtype_s);
		goto retry0;
		break;
	case '2':
		char city_s[30];
		cin.ignore();
		do
		{
			cout << "Enter Location: ";
			cin.getline(city_s, 30);
		} while (!validate(city_s, "city"));
		searchByLocation(city_s);
		goto retry0;
		break;
	case '3':
		char name_s[60];
		cin.ignore();
		do
		{
			cout << "Enter Name: ";
			cin.getline(name_s, 60);
		} while (!validate(name_s, "name"));
		searchByName(name_s);
		goto retry0;
		break;
	case '4':
		cout << "\nLogging out . . .\n";
		system("PAUSE");
		main();
		break;
	default:
		cout << "Please enter a valid value";
		goto retry1;
		break;
	}
}

void searchByBloodType(char s[30]) {
	donorList* donor = donorData("donors.dat");
	int count = 0;
	cout << "Searching for Donors with blood type " << s << " ...\n\n";
	for (int i = 0; i < donorLimit; i++){
		if (strcmp(s, donor[i].bloodType) == 0) {
			count++;
		}
	}

	cout << "\nResults Found : " << count << endl;

	line(100, '-');
	for (int i = 0; i < donorLimit; i++) {
		if (strcmp(s, donor[i].bloodType) == 0)
		{
			cout << "\n\tID \t\t\t: \t" << donor[i].id << endl;
			cout << "\tName \t\t\t: \t" << donor[i].fname << " " << donor[i].lname << endl;
			cout << "\tDate of Birth \t\t: \t" << donor[i].dob << endl;
			cout << "\tNationality \t\t: \t" << donor[i].nationality << endl;
			cout << "\tEthnicity \t\t: \t" << donor[i].ethnicity << endl;
			cout << "\tGender \t\t\t: \t" << donor[i].gender << endl;
			cout << "\tExisting Conditions \t: \t" << donor[i].existingConditions << endl;
			cout << "\tBlood Type \t\t: \t" << donor[i].bloodType << endl;
			cout << "\tContact Number \t\t: \t" << donor[i].contactNumber << endl;
			cout << "\tEmail \t\t\t: \t" << donor[i].email << endl;
			cout << "\tAddress \t\t: \t" << donor[i].address << ", " << donor[i].city << endl;
			cout << "\tLast Donation \t\t: \t" << donor[i].lastDonation << endl;

			line(100, '-');
		}
	}
	cout << "\nEnd of Results . . .\n\n";
	system("PAUSE");
}

void searchByLocation(char s[30]) {
	donorList* donor = donorData("donors.dat");
	int count = 0;
	cout << "Searching for Donors by location : " << s << " ...\n\n";
	for (int i = 0; i < donorLimit; i++) {
		if (strcmp(s, donor[i].city) == 0) {
			count++;
		}
	}

	cout << "\nResults Found : " << count << endl;
	line(100, '-');
	if (count > 0) {
		for (int i = 0; i < donorLimit; i++) {
			if (strcmp(s, donor[i].city) == 0)
			{
				cout << "\n\tID \t\t\t: \t" << donor[i].id << endl;
				cout << "\tName \t\t\t: \t" << donor[i].fname << " " << donor[i].lname << endl;
				cout << "\tDate of Birth \t\t: \t" << donor[i].dob << endl;
				cout << "\tNationality \t\t: \t" << donor[i].nationality << endl;
				cout << "\tEthnicity \t\t: \t" << donor[i].ethnicity << endl;
				cout << "\tGender \t\t\t: \t" << donor[i].gender << endl;
				cout << "\tExisting Conditions \t: \t" << donor[i].existingConditions << endl;
				cout << "\tBlood Type \t\t: \t" << donor[i].bloodType << endl;
				cout << "\tContact Number \t\t: \t" << donor[i].contactNumber << endl;
				cout << "\tEmail \t\t\t: \t" << donor[i].email << endl;
				cout << "\tAddress \t\t: \t" << donor[i].address << ", " << donor[i].city << endl;
				cout << "\tLast Donation \t\t: \t" << donor[i].lastDonation << endl;

				line(100, '-');
			}
		}
		cout << "\nEnd of Results . . .\n\n";
	}
	
	system("PAUSE");
}

void searchByName(char s[60]) {
	donorList* donor = donorData("donors.dat");
	int count = 0;

	cout << "Searching for Donors by Name : '" << s << "' ...\n";
	for (int i = 0; i < donorLimit; i++) {
		char* newArray = new char[strlen(donor[i].fname) + strlen(donor[i].lname) + 1];
		strcpy(newArray, donor[i].fname);
		strcat(newArray, " ");
		strcat(newArray, donor[i].lname);

		if (strcmp(s, newArray) == 0 || strcmp(s, donor[i].fname) == 0 || strcmp(s, donor[i].lname) == 0) {
			count++;
		}
	}

	cout << "\nResults Found : " << count << endl;
	line(100, '-');
	if (count > 0) {
		for (int i = 0; i < donorLimit; i++) {
			char* newArray = new char[strlen(donor[i].fname) + strlen(donor[i].lname) + 1];
			strcpy(newArray, donor[i].fname);
			strcat(newArray, " ");
			strcat(newArray, donor[i].lname);
			if (strcmp(s, newArray) == 0 || strcmp(s, donor[i].fname) == 0 || strcmp(s, donor[i].lname) == 0) {
				cout << "\n\tID \t\t\t: \t" << donor[i].id << endl;
				cout << "\tName \t\t\t: \t" << donor[i].fname << " " << donor[i].lname << endl;
				cout << "\tDate of Birth \t\t: \t" << donor[i].dob << endl;
				cout << "\tNationality \t\t: \t" << donor[i].nationality << endl;
				cout << "\tEthnicity \t\t: \t" << donor[i].ethnicity << endl;
				cout << "\tGender \t\t\t: \t" << donor[i].gender << endl;
				cout << "\tExisting Conditions \t: \t" << donor[i].existingConditions << endl;
				cout << "\tBlood Type \t\t: \t" << donor[i].bloodType << endl;
				cout << "\tContact Number \t\t: \t" << donor[i].contactNumber << endl;
				cout << "\tEmail \t\t\t: \t" << donor[i].email << endl;
				cout << "\tAddress \t\t: \t" << donor[i].address << ", " << donor[i].city << endl;
				cout << "\tLast Donation \t\t: \t" << donor[i].lastDonation << endl;

				line(100, '-');
			}
		}
		cout << "\nEnd of Results . . .\n\n";
	}

	system("PAUSE");
}