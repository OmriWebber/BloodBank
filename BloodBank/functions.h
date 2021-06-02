#include <string>
using namespace std;

void line(int, char);
void donorScreen();
void Login(string);
void Register(string);

struct currentDonor {
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
