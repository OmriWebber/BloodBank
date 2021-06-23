#include "header.h"

void updateDonorContact(int currentUser) {
	donorList* donor = donorData("donors.dat");
	cin.ignore();
	line(100, '-');
	
	fstream g;
	g.open("donors.dat", ios::in | ios::binary);

	if (!g.is_open())
	{
		cout << "Error! Could not open file\n";
	}
	else {
		cout << "\n\nOld Contact Number: " << donor[currentUser].contactNumber;
		do
		{
			cout << "\nPlease enter new contact number: ";
			cin.getline(donor[currentUser].contactNumber, 30);
		} while (!validate(donor[currentUser].contactNumber, "contactNumber"));
	}

	g.write(reinterpret_cast<char*>(donor), sizeof(donorList));

	g.close();

	cout << "\n\nContact Number updated successfully.\n";
	system("PAUSE");
	donorScreen(currentUser);
}

void updateDonorAddress(int currentUser) {
	donorList* donor = donorData("donors.dat");
	cin.ignore();
	line(100, '-');

	fstream g;
	g.open("donors.dat", ios::in | ios::binary);

	if (!g.is_open())

	{
		cout << "Error! Could not open file\n";
	}
	else {
		cout << "\n\nOld Address: " << donor[currentUser].address << ", " << donor[currentUser].city;
		do
		{
			cout << "\nPlease enter new address: ";
			cin.getline(donor[currentUser].address, 30);
		} while (!validate(donor[currentUser].address, "address"));

		do
		{
			cout << "Please enter new city: ";
			cin.getline(donor[currentUser].city, 30);
		} while (!validate(donor[currentUser].city, "city"));
	}

	g.write(reinterpret_cast<char*>(donor), sizeof(donorList));

	g.close();

	cout << "\n\nAddress updated successfully.\n";
	system("PAUSE");
	donorScreen(currentUser);
}

void updateDonorHealth(int currentUser) {
	donorList* donor = donorData("donors.dat");
	cin.ignore();
	line(100, '-');

	fstream g;
	g.open("donors.dat", ios::in | ios::binary);

	if (!g.is_open())

	{
		cout << "Error! Could not open file\n";
	}
	else {
		cout << "\n\nOld Address: " << donor[currentUser].address << ", " << donor[currentUser].city;
		do
		{
			cout << "\nPlease enter new address: ";
			cin.getline(donor[currentUser].address, 30);
		} while (!validate(donor[currentUser].address, "address"));

		do
		{
			cout << "City: ";
			cin.getline(donor[currentUser].city, 30);
		} while (!validate(donor[currentUser].city, "city"));
	}

	g.write(reinterpret_cast<char*>(donor), sizeof(donorList));

	g.close();
	cout << "\n\nHealth Status updated successfully.\n";
	system("PAUSE");
	donorScreen(currentUser);
}