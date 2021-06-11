#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <stdio.h>
using namespace std;

struct donorList {
	int currentUser;
	string username;
	string password;
	string fname;
	string lname;
	string dob;
	string nationality;
	string ethnicity;
	string gender;
	string existingConditions;
	string bloodType;
	string contactNumber;
	string email;
	string address;
	string city;
	string lastDonation;
	bool approved = false;
};

struct recipientList {
	int currentUser;
	char username[40];
	char password[40];
	char name[40]; 
	char address[40];
	char email[40]; 
	char contactNumber[15];
	bool approved = false;

};

struct adminList {
	int currentUser;
	string username;
	string password;
};

struct Data {
	donorList donor[20];
	recipientList recipient[10];
	adminList admin[5];
};

struct TempDonor {
	int currentUser;
	char username[40];
	char password[40];
	char fname[40];
	char lname[40];
	char dob[40];
	char nationality[40];
	char ethnicity[40];
	char gender[40];
	char existingConditions[40];
	char bloodType[40];
	char contactNumber[40];
	char email[40];
	char address[40];
	char city[40];
	char lastDonation[40];
	bool approved = false;
};

int main();
void line(int, char);
void readData(Data);
void donorData(string, Data);
void recipientData(string);
void adminData(string);
void donorScreen(Data, int);
void recipientScreen(Data, int);
void adminScreen(Data, int);
void Login(Data, string);
void Register(string);