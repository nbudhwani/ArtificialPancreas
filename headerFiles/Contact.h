/**
*   \author Naeem Budwhani
*	Header file for the Contact.cpp file
*/

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

using namespace std;

class Contact 
{
public:
	/// name of the contact
	string name;
	
	/// email address of the contact
	string email;

	/// constructor, expects a string for the name and email of the contact
	Contact(string name, string email);
	
	/// destructor
	~Contact();

	/// returns the name of the contact
	string getName();
	
	/// returns the email address of the contact
	string getEmail();
};

#endif
