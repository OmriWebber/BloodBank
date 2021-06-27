#include "header.h"

struct donorList* searchByBloodType(char[30]);

void recipientScreen(uint32_t currentUser) {
	recipientList* recipient = recipientData("recipients.dat");
	char option;
	cout << currentUser;
	cout << "\n\t\t\t\tRecipient Screen - " << recipient[currentUser].name;
	line(100, '-');
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
		cout << "Enter blood type: ";
		cin.getline(bloodtype_s, 30);
		searchByBloodType(bloodtype_s);
		break;
	case '2':
		break;
	case '3':
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

struct donorList* searchByBloodType(char s[30]) {
	donorList* donor = donorData("donors.dat");
	for (int i = 0; i < donorLimit; i++){
		cout << donor[i].bloodType;
	}


	return donor;
}