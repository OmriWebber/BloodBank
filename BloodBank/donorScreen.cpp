#include "header.h"



void donorScreen(int currentUser) {
	donorList* donor = donorData("donors.dat");
	char option;

	cout << "\n\t\t\t\t\tDonor Screen - " << donor[currentUser].username;
	line(100, '-');
	cout << "\n 1. Prodedure to donate blood";
	cout << "\n 2. Benefits of blood information";
	cout << "\n 3. Manage your information";
	cout << "\n 4. Book an appointment";
	cout << "\n 5. Logout";
	cout << "\n";
	line(100, '-');

	cout << "\nEnter your option: ";
	cin >> option;
reset1:;
	switch (option)
	{
	case '1':
		cout << "\nProdedure to donate blood";
		system("PAUSE");
		goto reset1;
		break;
	case '2':
		cout << "\nBenefits of blood information";
		system("PAUSE");
		goto reset1;
		break;
	case '3':
		cout << "\n\t\t\t\tManage your information";
		line(100, '-');
		cout << "\n 1. Update contact details";
		cout << "\n 2. Update address";
		cout << "\n 3. Update health status";
		cout << "\n";
		line(100, '-');
	reset2:;
		cout << "\nEnter your option: ";
		cin >> option;
		switch (option)
		{
		case '1':
			
			break;
		case '2':
			
			break;
		case '3':
			
			break;
		default:
			cout << "Please enter a valid value";
			goto reset2;
		}
		break;
	case '4':
		cout << "\nBook an appointment";
		system("PAUSE");
		goto reset1;
		break;
	case '5':
		cout << "\nLogging out . . .\n\n";
		system("PAUSE");
		main();
		break;
	default:
		cout << "Please enter a valid value";
		goto reset1;
		break;
	}
}