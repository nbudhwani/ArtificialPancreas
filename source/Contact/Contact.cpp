/*!
	@author Naeem Budhwani
	Description: Represents the contact info for a person
*/

#include <iostream>
#include "Contact.h"

using namespace std;

/**
*	\name Contact
*	constructor
*	\param name - the name of the contact
*	\param email - the email address of the contact
*/
Contact::Contact(string name, string email)
{
	this->name = name;
	this->email = email;
}

/**
*	\name ~Contact
*	destructor
*/
Contact::~Contact() {}

/**
*	\name getName
*	returns the contact's name
*	\return the name
*/
string Contact::getName() {
	return this->name;
}

/**
*	\name getEmail
*	\description returns the contact's email
*	\return the email
*/
string Contact::getEmail() {
	return this->email;
}


