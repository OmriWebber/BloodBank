#include "header.h"

#pragma warning(suppress : 4996)

bool validate(char input[], string type) {
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
			int d, m, y;
			string s;
			for (int i = 0; i < 30; i++) {
				s = s + input[i];
			}
			
			d = stoi(s.substr(0, 2));
			m = stoi(s.substr(3, 2));
			y = stoi(s.substr(6));


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
		if (strlen(input) <= 0 || strlen(input) > 100)
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
		} else {
			char bloodtype[8][4] = { "A+", "A-", "B+", "B-",  "O+", "O-",  "AB+", "AB-" };
			for (int i = 0; i < 8; i++)
			{
				if (strcmp(input, bloodtype[i]) == 0)
				{
					return true;
				}
			}
			cout << "Blood Type invalid, please try again...\n";
			return false;
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
		if (strlen(input) <= 0 || strlen(input) > 100)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "address") {
		if (strlen(input) <= 0 || strlen(input) > 100)
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
	} else if (type == "name") {
		if (strlen(input) <= 0 || strlen(input) > 60)
		{
			return false;
		}
		else {
			return true;
		}
	} else if (type == "date") {
		if (strlen(input) <= 0 || strlen(input) > 60)
		{
			return false;
		}
		else {
			return true;
		}
	}
	return false;
}

bool validateTime(char time[], string availableTime[], int size) {
	if (strcmp(time, "00:00") == 0){
		cout << "\nInvlid time entered. Try again.";
		return false;
	}
	else {
		for (int i = 0; i < size; i++)
		{
			if (availableTime[i] != "")
			{
				if (strcmp(time, availableTime[i].c_str()) == 0)
				{
					return true;
				}
			}

		}
	}
	
	cout << "\nTime slot already taken!\nPick another timeslot";
	return false;
}