// BloodBank.cpp

#include "header.h"

int main() {
	char option;

	cout << "\n\t\t\t\tOneBlood - Donor Bank Service";
	line(100, '-');

	cout << "\nInformation about OneBlood\n";
	cout << "\nContact Details\n";

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
			default:
				cout << "Please enter a valid value";
				goto retry2;
				break;
		}
		break;
	case '2':
		line(100, '-');
		cout << "\n 1. Register as a Donor";
		cout << "\n 2. Register as a Recipient";
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