#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <stdio.h>
#include <stdlib.h>
#include <regex>
#include <iomanip>
#include <ctime>

using namespace std;

const int donorLimit = 5;
const int recipientLimit = 5;
const int adminLimit = 5;

struct donorList {
	int currentUser;
	char username[30];
	char password[30];
	char fname[30];
	char lname[30];
	char dob[30];
	char nationality[30];
	char ethnicity[30];
	char gender[30];
	char existingConditions[30];
	char bloodType[30];
	char contactNumber[30];
	char email[30];
	char address[30];
	char city[30];
	char lastDonation[30];
	bool approved = false;
};

struct recipientList {
	int currentUser;
	char username[30];
	char password[30];
	char name[30];
	char address[30];
	char email[30];
	char contactNumber[30];
	bool approved = false;

};

struct adminList {
	int currentUser;
	char username[30];
	char password[30];
};


int main();
void line(int, char);
struct donorList* donorData(string);
struct recipientList* recipientData(string);
struct adminList* adminData(string);
void donorScreen(int);
void updateDonorContact(int);
void updateDonorAddress(int);
void updateDonorHealth(int);
void recipientScreen(int);
void adminScreen(int);
void Login(string);
void Register(string);

bool validate(char[30], string);
