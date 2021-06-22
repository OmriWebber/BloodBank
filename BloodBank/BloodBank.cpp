// BloodBank.cpp

#include "header.h"

int main() {
	char option;

	cout << "\n\t\t\t\tOneBlood - Donor Bank Service";
	line(100, '-');

	cout << "\nBlood is made up of four main components: red blood cells, white blood cells, platelets and, the protein-rich liquid that suspends them all, plasma.\n\nIt's rare for a patient to require all of the blood components at one time, so a blood donation is usually separated into three parts for transfusion – red blood cells, platelets and plasma. This means patients can be transfused with only what they need, and your single blood donation can help save more than one patient.\n\nBecause there's no substitute for these lifesaving components, patients around the country rely on blood donors to help save their lives.\n";
	cout << "\nContact Details\nPhone: 0800 448 325\n";
retry0:;
	line(100, '-');
	cout << "\n 1. Login";
	cout << "\n 2. Register";
	cout << "\n";

	line(100, '-');

retry1:;
	cout << "\nEnter your option: ";
	cin >> option;
	switch (option)
	{
	case '1':
		line(100, '-');
		cout << "\n 1. Donor Login";
		cout << "\n 2. Recipient Login";
		cout << "\n 3. Admin Login";
		cout << "\n 4. <- Go Back";
		cout << "\n";
		line(100, '-');
		
	retry2:
		cout << "\nEnter your option: ";
		cin >> option;
		switch (option)
		{
			case '1':
				Login("donor");
				break;
			case '2':
				Login("recipient");
				break;
			case '3':
				Login("admin");
				break;
			case '4':
				goto retry0;
				break;
			default:
				cout << "\nPlease enter a valid value";
				goto retry2;
				break;
		}
		break;
	case '2':
		line(100, '-');
		cout << "\n 1. Register as a Donor";
		cout << "\n 2. Register as a Recipient";
		cout << "\n 3. <- Go Back";
		cout << "\n";
		line(100, '-');

	retry3:;
		cout << "\nEnter your option: ";
		cin >> option;
		switch (option)
		{
			case '1':
				Register("donor");
				break;
			case '2':
				Register("recipient");
				break;
			case '3':
				goto retry0;
				break;
			default:
				cout << "Please enter a valid value";
				goto retry3;
				break;
		}
		break;
	default:
		cout << "Please enter a valid value";
		goto retry1;
		break;
		break;
	}


}