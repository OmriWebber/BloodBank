#include "header.h"



void donorScreen(int currentUser) {
	donorList* donor = donorData("donors.dat");

	cout << "\n\t\t\t\t\tDonor Screen";
	line(100, '-');

	cout << "Current user: " << donor[currentUser].username << endl;
}