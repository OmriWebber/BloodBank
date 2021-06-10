#include <string>
using namespace std;

struct donorList {
		int currentUser;
		string username[50];
		string password[40];
		string fname[40];
		string lname[40];
		string dob[40];
		string nationality[40];
		string ethnicity[40];
		string gender[40];
		string existingConditions[40];
		string bloodType[40];
		string contactNumber[40];
		string email[40];
		string address[40];
		string city[40];
		string lastDonation[15];
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