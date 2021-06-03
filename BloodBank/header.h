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
	string lastDonation = " ";
	bool approved = false;
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

int main();
void line(int, char);
void donorScreen(int);
void recipientScreen(int);
void adminScreen(int);
void Login(struct Data, string);
void Register(string);