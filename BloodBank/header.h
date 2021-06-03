#include <string>
using namespace std;

void line(int, char);
void donorScreen();
void recipientScreen();
void adminScreen();
void Login(string);
void Register(string);

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
};

struct recipientList {
	int currentUser;
	string username;
	string password;
	string name;
	string address;
	string email;
	string contactNumber;
};

struct adminList {
	int currentUser;
	string username;
	string password;
};