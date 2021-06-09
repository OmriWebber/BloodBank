#include <string>
using namespace std;

class donorList {
	public: 
		int currentUser;
		char username[50];
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
		char lastDonation[15];
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

int main();
void line(int, char);
struct Data readData();
void donorData(string);
void recipientData(string);
void adminData(string);
void donorScreen(Data, int);
void recipientScreen(Data, int);
void adminScreen(Data, int);
void Login(Data, string);
void Register(string);