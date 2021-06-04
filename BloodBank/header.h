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
};

struct Data {
	donorList donor[20];
	recipientList recipient[10];
	adminList admin[5];
};

int main();
void line(int, char);
struct Data readData(Data);
void donorData(Data, string);
void recipientData(Data, string);
void adminData(Data, string);
void donorScreen(Data, int);
void recipientScreen(Data, int);
void adminScreen(Data, int);
void Login(Data, string);
void Register(string);