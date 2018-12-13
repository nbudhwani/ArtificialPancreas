/**
*	\author Veronica Witzig
*	\brief Represents the type of person that is logged in.
*		Depending on the account type, may have restricted 
*		capability.
*/

#include "Account.h"

using namespace std;

const std::string Account::PATIENT_ACCOUNT = "Patient";
const std::string Account::GUEST_ACCOUNT = "Guest";
const std::string Account::UNKNOWN_ACCOUNT = "Unknown";

/**
*	\name Account
*	\brief Constructor
*/
Account::Account()
{
	string password;
	cout << "Please enter a password: ";
	cin.ignore(0, '\n');
	cin >> password;
	
	/// check if accounts.txt file exists locally. If it does not, then the account needs to be initialized, else, continue the verification process.
	ifstream accountStream("accountInfo.txt");
	if (accountStream.is_open())
	{
		Account::verifyPassword(accountStream, password);
	}
	else
	{
		cout << "An account has not been initialized on this machine. Performing setup..." << endl;
		Account::initializeAccount(password);
		cout << "\nThe password you have entered is being set." << endl;

		sleep(3);
		cout << "Now that your account has been initialized, please re-enter your password: ";
		string newPassword;
		getline(cin, newPassword);
		ifstream accountStream("accountInfo.txt");
		Account::verifyPassword(accountStream, newPassword);
	}
};

/**
*	\name Account
*	\brief Constructor, used for testing
*	\param type - the type to assign the account
*/
Account::Account(string type)
{
	accountType = type;
};

/**
*	\name ~Account
*	\brief Destructor
*/
Account::~Account() {};

/**
*	\name getAccountType
*	\brief returns the type of the account
*	\return	the account type as a string
*/
string Account::getAccountType() 
{
	return accountType;
};

/**
*	\name verifyPassword
*	\brief verifies the password to a stored hash, sets the account type as either PATIENT, GUEST, or UNKNOWN
*	\param hashStream 	- stream for getting the hash
*	\param password 	- the password to verify
*/
void Account::verifyPassword(ifstream& hashStream, string password)
{
	size_t hashToCheck = Account::hashPassword(password);

	/// retrieve the locally stored hash value and compare to the new hashed value based on the passed password
	string hashLine;
	size_t patientHash;
	size_t guestHash;

	/// patient hash is on first line. guest/emergency contact hash is on second line
	if (hashStream.is_open())
	{
		hashStream >> patientHash;
		hashStream >> guestHash;
	}

	if (patientHash == hashToCheck)
	{
		cout << "patient signed in" << endl;
		accountType = Account::PATIENT_ACCOUNT;
	}
	else if (guestHash == hashToCheck)
	{
		cout << "guest signed in" << endl;
		accountType = Account::GUEST_ACCOUNT;
	}
	else
	{
		cout << "unknown attempt to sign in" << endl;
		accountType = Account::UNKNOWN_ACCOUNT;
	}
};

/**
*	\name hashPassword
*	\brief hashes the received password from the user
*	\param password - the password to hash
*	\return hash value of the password
*/
size_t Account::hashPassword(string password)
{
	hash<string> hasher;
	size_t hash = hasher(password);
	return hash;
};

/**
*	\name initializeAccount
*	\brief initializes the patient's main account by setting a password for the user.
*	\param string password - the password to verify
*/
void Account::initializeAccount(string password)
{
	cout << "Would you like to use the password you entered for the main account (Y / N): ";
	string yesOrNo = "";
	cin.ignore(1, '\n');
	getline(cin, yesOrNo);

	if (yesOrNo == "N") {
		cout << "Please enter a password: ";
		getline(cin, password);
	}

	size_t hash = Account::hashPassword(password);
	ofstream accountInfo("accountInfo.txt");
	accountInfo << hash << endl;

	cout << "For your own safety, please provide a password for an emergency guest account: ";
	string guestPassword = "";
	getline(cin, guestPassword);
	guestPassword = guestPassword;
	hash = Account::hashPassword(guestPassword);
	accountInfo << hash << endl;

	/// close accountInfo.txt
	accountInfo.close();
};
