#include "header.h"

void donorScreen(uint32_t currentUser) {
	donorList* donor = donorData("donors.dat");
	char option;

	cout << "\n\n\t\t\t\t\tYour Profile\n";
	line(100, '-');

	for (int i = 0; i < donorLimit; i++)
	{
		if (currentUser == donor[i].id)
		{
			cout << "\n\t\tID \t\t\t: \t\t" << donor[i].id << endl;
			cout << "\t\tName \t\t\t: \t\t" << donor[i].fname << " " << donor[i].lname << endl;
			cout << "\t\tDate of Birth \t\t: \t\t" << donor[i].dob << endl;
			cout << "\t\tNationality \t\t: \t\t" << donor[i].nationality << endl;
			cout << "\t\tEthnicity \t\t: \t\t" << donor[i].ethnicity << endl;
			cout << "\t\tGender \t\t\t: \t\t" << donor[i].gender << endl;
			cout << "\t\tExisting Conditions \t: \t\t" << donor[i].existingConditions << endl;
			cout << "\t\tBlood Type \t\t: \t\t" << donor[i].bloodType << endl;
			cout << "\t\tContact Number \t\t: \t\t" << donor[i].contactNumber << endl;
			cout << "\t\tEmail \t\t\t: \t\t" << donor[i].email << endl;
			cout << "\t\tAddress \t\t: \t\t" << donor[i].address << "\n\t\t\t\t\t\t\t" << donor[i].city << endl;
			cout << "\t\tLast Donation \t\t: \t\t" << donor[i].lastDonation << endl;
		}
		
	}
	
	line(100, '-');
	cout << "\n\t\t\t\tDonor Menu - " << currentUser;
	cout << "\n 1. Prodedure to donate blood";
	cout << "\n 2. Benefits of blood information";
	cout << "\n 3. Manage your information";
	cout << "\n 4. Book an appointment";
	cout << "\n 5. Logout";
	cout << "\n";
	line(100, '-');

reset1:;
	cout << "\nEnter your option: ";
	cin >> option;

	switch (option)
	{
	case '1':
		cout << "\nWhat to Expect When Donating\n";
		line(100, '-');
		cout << "\n\nWhat to Expect When Donating";
		cout << "\nA little unsure of what to expect during your first donation? Keep reading the information below to learn about what to expect at your appointment.";
		cout << "\n\nWhat to bring to your appointment";
		cout << "\nGiving blood is a great way to give back to your community and to help thousands of New Zealanders in need. However, you might be a little unsure of what to expect during your first donation. Keep reading the information below to learn about what to expect at your appointment.";
		cout << "\n\nThings to bring:";
		cout << "\n - Your ID\n - Something to Pass the time\n - A positive attitude and a smile";
		cout << "\n\n";
		system("PAUSE");
		goto reset1;
		break;
	case '2':
		cout << "\nBenefits of blood information\n\n";
		line(100, '-');
		cout << "\n\nWhy Should You Donate Blood?";
		cout << "\n\nNew Zealand needs over 3,500 donations every week.";
		cout << "\n\nRegular weekly donations ensure blood and plasma are available for those in need.";
		cout << "\n\nThe gift of blood can only be given from one person to another, and there is no substitute. So it's nice to know New Zealand can rely on everyday heroes' generosity to keep the flow of blood and plasma going.";
		cout << "\n\nHowever, the need for blood and plasma is constant, so we're looking for more lifesavers. By putting aside a small part of your day you can make a life-changing difference, you can become a lifesaver too! ";
		cout << "\n\n";
		system("PAUSE");
		goto reset1;
		break;
	case '3':
		cout << "\n\t\t\t\tManage your information";
		line(100, '-');
		cout << "\n 1. Update contact details";
		cout << "\n 2. Update address";
		cout << "\n 3. Update health status";
		cout << "\n 4. Update email address";
		cout << "\n 4. <- Go Back";
		cout << "\n";
		line(100, '-');

	reset2:;
		cout << "\nEnter your option: ";
		cin >> option;
		switch (option)
		{
		case '1':
			updateDonorContact(currentUser);
			break;
		case '2':
			updateDonorAddress(currentUser);
			break;
		case '3':
			updateDonorHealth(currentUser);
			break;
		case '4':
			updateDonorEmail(currentUser);
			break;
		default:
			cout << "\nPlease enter a valid value\n";
			goto reset2;
		}
		break;
	case '4':
		cout << "\nBook an appointment";
		cout << "\n\n";
		system("PAUSE");
		goto reset1;
		break;
	case '5':
		cout << "\nLogging out . . .\n\n";
		system("PAUSE");
		main();
		break;
	default:
		cout << "Please enter a valid value";
		goto reset1;
		break;
	}
}