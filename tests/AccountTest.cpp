#include <stdio.h>
#include <string>
#include <sstream>

#include "Account.h"

using namespace std;

int main()
{
	string password;

	Account account = Account();

	return 0;
}

bool PatientTestPass_CorrectPassword()
{
	const string password = "patient password";
	Account account = Account();
	return account.getAccountType() == "Patient";
};

bool PatientTestFail_IncorrectPassword()
{
	const string password = "not the password";
	Account account = Account();
	return account.getAccountType() == "Unknown";
}

bool GuestTestPass_CorrectPassword()
{
	const string password = "guest password";
	Account account = Account();
	return account.getAccountType() == "Guest";
};

bool GuestTestFail_IncorrectPassword()
{
	const string password = "not the guest password";
	Account account = Account();
	return account.getAccountType() == "Unknown";
}
