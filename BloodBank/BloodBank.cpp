// BloodBank.cpp

#include "header.h"
#include <iostream>

using namespace std;

void line(int, char);
Data data;

int main(Data data)
{
	char option;
	

	cout << "\n\t\t\t\t\tNZ Blood Bank";
	line(100, '-');

	cout << "\nInformation about blood bank\n";
	cout << "\nContact Details\n";

	line(100, '-');
	cout << "\n 1. Login";
	cout << "\n 2. Register";
	cout << "\n";

	line(100, '-');

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

		cout << "\nEnter your option: ";
		cin >> option;
		switch (option)
		{
		case '1':
			Login(data, "donor");
			break;
		case '2':
			Login(data, "recipient");
			break;
		case '3':
			Login(data, "admin");
			break;
		default:
			break;
		}
		break;
	case '2':
		line(100, '-');
		cout << "\n 1. Register as a Donor";
		cout << "\n 2. Register as a Recipient";
		cout << "\n";
		line(100, '-');

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
			break;
		}
		break;
	default:
		break;
	}


}