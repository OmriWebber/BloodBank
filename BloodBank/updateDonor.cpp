#include "header.h"

bool flag = false;

void updateDonorContact(uint32_t currentUser) {
	line(100, '-');
	donorList donor;
	fstream g;
	g.open("donors.dat", ios::in | ios::out | ios::binary);
	if (g.is_open()) {
		while (!g.eof()) {
			g.read(reinterpret_cast<char*>(&donor), sizeof(donor));
			int position = g.tellg();
			if (currentUser == donor.id) {
				cout << "\n\nOld Contact Number: " << donor.contactNumber;
				g.seekp(position - (static_cast<unsigned __int64>(sizeof(donor))));
				do
				{
					cout << "\nPlease enter new contact number: ";
					cin.getline(donor.contactNumber, 30);
				} while (!validate(donor.contactNumber, "contactNumber"));
				g.write(reinterpret_cast<char*>(&donor), sizeof(donor));
				flag = false;
				cout << "\n\nContact Number updated successfully.\n\n";
				break;
			}
			else {
				flag = true;
			}
		}
	} else {
		cout << "Error! Could not open file\n\n";
	}

	if (flag) {
		cout << "\nRecord not found...\n\n";
	}

	g.close();

	system("PAUSE");
	donorScreen(currentUser);
}

void updateDonorAddress(uint32_t currentUser) {
	cin.ignore();
	line(100, '-');
	donorList donor;
	fstream g;
	g.open("donors.dat", ios::in | ios::out | ios::binary);
	if (g.is_open()) {
		while (!g.eof()) {
			g.read(reinterpret_cast<char*>(&donor), sizeof(donor));
			int position = g.tellg();
			if (currentUser == donor.id) {
				g.seekp(position - (static_cast<unsigned __int64>(sizeof(donor))));
				cout << "\n\nOld Address: " << donor.address;
				do
				{
					cout << "\nNew address: ";
					cin.getline(donor.address, 30);
				} while (!validate(donor.address, "address"));

				cout << "\n\nOld Address: " << donor.city;
				do
				{
					cout << "\nNew city: ";
					cin.getline(donor.city, 30);
				} while (!validate(donor.city, "city"));
				g.write(reinterpret_cast<char*>(&donor), sizeof(donor));
				flag = false;
				cout << "\n\nAddress updated successfully.\n\n";
				break;
			} else {
				flag = true;
			}
		}
	} else {
		cout << "Error! Could not open file\n\n";
	}

	if (flag) {
		cout << "\nRecord not found...\n\n";
	}

	g.close();

	system("PAUSE");
	donorScreen(currentUser);
}

void updateDonorHealth(uint32_t currentUser) {
	cin.ignore();
	line(100, '-');
	donorList donor;
	fstream g;
	g.open("donors.dat", ios::in | ios::out | ios::binary);
	if (g.is_open()) {
		while (!g.eof()) {
			g.read(reinterpret_cast<char*>(&donor), sizeof(donor));
			int position = g.tellg();
			if (currentUser == donor.id) {
				cout << "\n\nOld Existing Conditions: " << donor.existingConditions;
				g.seekp(position - (static_cast<unsigned __int64>(sizeof(donor))));
				do
				{
					cout << "\nNew Existing Conditions: ";
					cin.getline(donor.existingConditions, 30);
				} while (!validate(donor.existingConditions, "existingConditions"));
				g.write(reinterpret_cast<char*>(&donor), sizeof(donor));
				flag = false;
				cout << "\n\nExisting Conditions updated successfully.\n\n";
				break;
			}
			else {
				flag = true;
			}
		}
	}
	else {
		cout << "Error! Could not open file\n\n";
	}

	if (flag) {
		cout << "\nRecord not found...\n\n";
	}

	g.close();

	system("PAUSE");
	donorScreen(currentUser);
}

void updateDonorEmail(uint32_t currentUser) {
	cin.ignore();
	line(100, '-');
	donorList donor;
	fstream g;
	g.open("donors.dat", ios::in | ios::out | ios::binary);
	if (g.is_open()) {
		while (!g.eof()) {
			g.read(reinterpret_cast<char*>(&donor), sizeof(donor));
			int position = g.tellg();
			if (currentUser == donor.id) {
				cout << "\n\nOld Email: " << donor.email;
				g.seekp(position - (static_cast<unsigned __int64>(sizeof(donor))));
				do
				{
					cout << "\nNew Email: ";
					cin.getline(donor.email, 30);
				} while (!validate(donor.email, "email"));
				g.write(reinterpret_cast<char*>(&donor), sizeof(donor));
				flag = false;
				cout << "\n\nExisting Conditions updated successfully.\n\n";
				break;
			}
			else {
				flag = true;
			}
		}
	}
	else {
		cout << "Error! Could not open file\n\n";
	}

	if (flag) {
		cout << "\nRecord not found...\n\n";
	}

	g.close();

	system("PAUSE");
	donorScreen(currentUser);
}