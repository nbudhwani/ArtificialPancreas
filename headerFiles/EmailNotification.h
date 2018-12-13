/**
*	\author Veronica Witzig
*	Header file for the EmailNotification class
*/

#ifndef EMAIL_NOTIFICATION_HEADER
#define EMAIL_NOTIFICATION_HEADER

#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

#include "EmailNotification.h"
#include "PatientInfo.h"

class EmailNotification
{
public:
	/// constructor, expects a pointer to PatientInfo
	EmailNotification(PatientInfo *patientInfo);
	
	/// constructor, expects strings, only to be used for testing
	EmailNotification(std::string email, std::string password, std::string emergEmail);

	/// destructor
	~EmailNotification();
	
	/// notifies the patient when unauthorized user attempts to login
	void sendUnauthorizedAccessEmail();
	
	/// notifies the patient when a hypoglycemic event is imminent
	void sendHypoglycemicEventEmail();
	
	/// notifies the emergency contact that a hypoglycemic event has occured
	void sendEmergencyContactEmail();
	
	/// sends patient medical records
	void sendMedicalRequestEmail();

private:
	/// root directory for the email 
	const std::string TEMPLATE_PATH_ROOT = "base/email/";
	
	/// email template used for unauthorized access attempt
	const std::string UNAUTHORIZED_ACCESS_EMAIL_TEMPLATE = "unauthorized_email.txt";
	
	/// email template used for a hypoglycemic event
	const std::string HYPOGLYCEMIC_EVENT_EMAIL_TEMPLATE = "hypoglycemic_email.txt";
	
	/// email template used for notifying the emergency contact
	const std::string EMERGENCY_CONTACT_EMAIL_TEMPLATE = "emergency_email.txt";
	
	/// email template used for sending medical records
	const std::string REQUEST_MEDICAL_RECORDS_EMAIL_TEMPLATE = "request_records_email.txt";
	
	/// current working directory, needed for sending emails
	std::string currentWorkingDirectory;

	/// contains the email of the sender (the patient's email)
	std::string senderEmail;
	
	/// contains the password of the sender's email
	std::string emailPassword;
	
	/// contains the email of the recipient (the emergency contact's email)
	std::string recipientEmail;
	
	/// sends an email using the specified email template
	void sendEmail(std::string senderEmail, std::string recipientEmail, std::string emailPassword, std::string emailTemplate);
};

#endif
