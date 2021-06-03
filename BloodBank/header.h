#include <string>
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
	string lastDonation = "N/A";
	bool approved = false;

	donorList() {
		currentUser = 0;
		username = "username";
		password = "password";
		fname = "fname";
		lname = "lname";
		dob = "dob";
		nationality = "nationality";
		ethnicity = "ehtnicity";
		gender = "gender";
		existingConditions = "existingConditions";
		bloodType = "bloodType";
		contactNumber = "contact Number";
		email = "email";
		address = "address";
		city = "city";
		lastDonation = "N/A";
		approved = false;
	}
};

struct recipientList {
	int currentUser;
	string username;
	string password;
	string name;
	string address;
	string email;
	string contactNumber; 
	bool approved = false;

	recipientList() {
		currentUser = 0;
		username = "username";
		password = "password";
		name = "name";
		address = "address";
		email = "email";
		contactNumber = "contactNumber";
		approved = false;
	}
};

struct adminList {
	int currentUser;
	string username;
	string password;

	adminList() {
		currentUser = 0;
		username = "username";
		password = "password";
	}
};

struct Data {
	donorList donor[20];
	recipientList recipient[20];
	adminList admin[5];
};

int main(Data);
void line(int, char);
void donorScreen(Data, int);
void recipientScreen(Data, int);
void adminScreen(Data, int);
void Login(Data, string);
void Register(string);