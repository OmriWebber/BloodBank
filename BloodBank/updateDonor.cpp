#include "header.h"

int position = 0;
bool flag = false;

void updateDonorContact(uint32_t currentUser) {
	cin.ignore();
	line(100, '-');
	donorList donor;
	fstream g;
	g.open("donors.dat", ios::in | ios::out | ios::binary);

	if (g.is_open())
	{
		while (!g.eof())
		{
			g.read(reinterpret_cast<char*>(&donor), sizeof(donor));

			position = g.tellg();

			if (currentUser == donor.id) {
				cout << "\n\nOld Contact Number: " << donor.contactNumber;

				g.seekp(position - (sizeof(donor)));
				do
				{
					cout << "\nPlease enter new contact number: ";
					cin.getline(donor.contactNumber, 30);
				} while (!validate(donor.contactNumber, "contactNumber"));

				g.write(reinterpret_cast<char*>(&donor), sizeof(donor));

				flag = false;
				cout << "\n\nContact Number updated successfully.\n";
				break;
			}
			else {
				flag = true;
			}
		}
		
	}
	else {
		cout << "Error! Could not open file\n";
	}

	if (flag)
	{
		cout << "\nRecord not found...";
	}

	

	g.close();

	cout << "\n\nContact Number updated successfully.\n";
	system("PAUSE");
	donorScreen(currentUser);
}

void updateDonorAddress(uint32_t currentUser) {
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

void updateDonorHealth(uint32_t currentUser) {
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