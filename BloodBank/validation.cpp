#include "header.h"

bool validate(char input[30], string type) {
	if (type == "fname"){
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			cout << "First name value invalid, please try again...\n";
			return false;
		}
		else {
			return true;
		}
	} else if (type == "lname"){
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			cout << "Last name value invalid, please try again...\n";
			return false;
		}
		else {
			return true;
		}
	} else if (type == "dob"){
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			cout << "Date of Birth invalid, please try again...\n";
			return false;
		}
		else {
			istringstream stm(input);
			string day, month, year;
			char delim = '/';
			getline(stm, day, delim);
			getline(stm, month, delim);
			getline(stm, year, delim);
			int d = stoi(day);
			int m = stoi(month);
			int y = stoi(year);

			if (!(1582 <= y)) {
				cout << "Date of Birth invalid, please try again...\n";
				return false;
			}
			
			if (!(1 <= m && m <= 12)) {
				cout << "Date of Birth invalid, please try again...\n";
				return false;
			}
				
			if (!(1 <= d && d <= 31)) {
				cout << "Date of Birth invalid, please try again...\n";
				return false;
			}
			if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11)) {
				cout << "Date of Birth invalid, please try again...\n";
				return false;
			}
			if ((d == 30) && (m == 2)) {
				cout << "Date of Birth invalid, please try again...\n";
				return false;
			}
			if ((m == 2) && (d == 29) && (y % 4 != 0)) {
				cout << "Date of Birth invalid, please try again...\n";
				return false;
			}
			if ((m == 2) && (d == 29) && (y % 400 == 0))
				return true;
			if ((m == 2) && (d == 29) && (y % 100 == 0)) {
				cout << "Date of Birth invalid, please try again...\n";
				return false;
			}
			if ((m == 2) && (d == 29) && (y % 4 == 0))
				return true;

			return true;
		}
	} else if (type == "nationality"){
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "ethnicity"){
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "gender") {
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "existingConditions") {
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "bloodType") {
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "gender") {
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "contactNumber") {
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "email") {
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "address") {
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "city") {
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "lastDonation") {
		if (strlen(input) > 30)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "username") {
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "password") {
		if (strlen(input) <= 0 || strlen(input) > 30)
		{
			return false;
		}
		else {
			return true;
		}
	}
	return false;
}