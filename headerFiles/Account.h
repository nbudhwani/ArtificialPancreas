/**
*	\author Veronica Witzig
*	Header file for the Account class
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

class Account
{	
public:
	// Types of accounts the user can have

	/// represents account type of Patient
	const static std::string PATIENT_ACCOUNT;

	/// represents account type of Guest
	const static std::string GUEST_ACCOUNT;

	/// represents account type of Unknown
	const static std::string UNKNOWN_ACCOUNT;

	/// constructor
	Account();

	/// constructor, expects a given account type, used for testing
	Account(std::string type);
	
	/// destructor
	~Account();
	
	/// returns the type of the account, either "Patient", "Guest", or "Unknown"
	std::string getAccountType();
	
private:
	/// path to directory for storing accountInfo.txt
	const std::string ACCOUNT_INFO_PATH = "/accountInfo/accountInfo.txt";

	/// file name for storing account information
	const std::string ACCOUNT_INFO = "accountInfo.txt";							

	/// the type of the account
	std::string accountType;

	/// confirms if the password matches the locally stored hashed password
	void verifyPassword(std::ifstream& hashStream, std::string password);

	/// returns the hash of a password
	std::size_t hashPassword(std::string password);
	
	/// prompts the user to set a password and guest password
	void initializeAccount(std::string password);
};

#endif
