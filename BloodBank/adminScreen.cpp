#include "header.h"

void adminScreen() {

	donorList* donor = donorData("donors.dat");


reset1:;
	int option;
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
			cout << donor[i].fname;
		}
		goto reset1;
		break; 
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	default:
		goto reset1;

	}

















}