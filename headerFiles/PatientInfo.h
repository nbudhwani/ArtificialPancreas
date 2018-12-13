/**
*	\author Naeem Budhwani
*	\brief Header file for the PatientInfo class
*	Contains statistics about the patient and his/her emergency contact information
*/

#ifndef PATIENTINFO_H
#define PATIENTINFO_H

#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
#include "DeviceRecord.h"
#include "HormoneDose.h"
#include "MedicationRecord.h"
#include "MonitorRecord.h"

using namespace std;

class PatientInfo 
{
public:
	/**
	*	\name PatientInfo
	*	\brief implicit constructor
	*/
	PatientInfo();

	/**
	*	\name PatientInfo
	*	\brief constructor, expects patient info
	*/
	PatientInfo(
		std::string name,
		int age,
		std::string sex,
		double weight,
		double height,
		std::string email
		);

	/**
	 * \name PatientInfo
	 * \brief constructor with full argument list
	 * */
	PatientInfo(string, double, double, int, string, string, string, Contact *,
					vector<MonitorRecord> *, vector<MedicationRecord> *);
	
	/// destructor
	~PatientInfo();
	
	/**
	*	\name getWeight
	*	\brief gets the patient's weight
    	*/
	double getWeight();

	/**
	*	\name setWeight
	*	\brief sets the patient's weight
	*	\param Weight - patient's weight to set
    	*/
	void setWeight(double weight);
	
	/**
	*	\name getHeight
	*	\brief gets the patient's height
    	*/
	double getHeight();

	/**
	*	\name setHeight
	*	\brief sets the patient's height
	*	\param height - patient's height to set
	*/
	void setHeight(double height);
	
	/**
	*	\name getAge
	*	\brief gets the patient's age
    	*/
	int getAge();

	/**
	*	\name setAge
	*	\brief sets the patient's age
	*	\param Weight - patient's age to set
	*/
	void setAge(int age);

	/**
	*	\name getSex
	*	\brief gets the patient's sex as a string
   	*/
	string getSex();

	/**
	*	\name setSex
	*	\brief sets the patient's sex
	*	\param sex - patient's sex to set
	*/
	void setSex(string sex);
	
	/**
	*	\name getCarbs
	*	\brief gets the grams of carbs the patient has eaten in his/her last meal
    	*/
	double getCarbs();

	/**
	*	\name setCarbs
	*	\brief sets the patient's carbs
	*	\param carbs - patient's email to set
	*/
	void setCarbs(double carbs);
	
	/**
	*	\name getExercise
	*	\brief gets the patient's exercise (low, medium, or high)
    	*/
	string getExercise();

	/**
	*	\name setExercise
	*	\brief sets the patient's exercise (low, medium or high)
	*	\param exercise - patient's exercise to set
	*/
	void setExercise(string exercise);
	
	/**
	*	\name getSleep
	*	\brief gets the patient's sleep in hours
    	*/
	int getSleep();

	/**
	*	\name setSleep
	*	\brief sets the patient's sleep in hours
	*	\param sleep - patient's sleep to set
	*/
	void setSleep(int sleep);

	/**
	*	\name getEmergencyContact
	*	\brief gets the patient's emergency contact as a Contact type
    	*/
	Contact* getEmergencyContact();

	/**
	*	\name setEmergencyContact
	*	\brief sets the patient's emergency contact
	*	\param contact - patient's contact set
	*/
	void setEmergencyContact(Contact* contact);

	/**
	*	\name getName
	*	\brief gets the patient's name
    	*/
	std::string getName();
	
	/**
	*	\name getEmail
	*	\brief gets the patient's email
   	*/
	std::string getEmail();

	/**
	*	\name setEmail
	*	\brief sets the patient's email
	*	\param email - patient's email to set
	*/
	void setEmail(std::string email);
	
	/**
	*	\name getEmailPassword
	*	\brief gets the patient's email's password
  	*/
	std::string getEmailPassword();

	/**
	*	\name setEmailPassword
	*	\brief sets the patient's email password for the purpose of 
	*	sending emails.
	*	\param password - patient's email to set
	*/
	void setEmailPassword(std::string password);
	
	/**
	*	\name getMonitorRecords
	*	\brief gets the patient's monitor records
    	*/
	vector<MonitorRecord> * getMonitorRecords();

	/**
	*	\name getMedicationRecords
	*	\brief gets the patient's administered medication records
    	*/
	vector<MedicationRecord> * getMedicationRecords();

	
	/**
	 * 	\name setName
	 * 	\brief sets the patient's name
	 * 	\param string to set to atiennt's name
	 * */
	void setName(std::string name);

	/**
	*	\name SetupPatientInfo
	*	\brief prompts user for all required bio-statistics
    	*/
	void SetupPatientInfo();

	/**
	*	\name readFromFile
	*	\brief deserializes patient.txt data obtained from previous artificial
	*	pancreas sessions and stores it in the current session
    	*/
	void readFromFile();

	/**
	*	\name writeToFile
	*	\brief serializes the monitor and medication records into the patient.txt file
    	*/
	void writeToFile();
	
private:
	/// patient's weight
	double weight;

	/// patient's height
	double height;

	/// patient's carbs
	double carbs;

	/// patient's hormone dose
	double amount;
	
	/// patient's age
	int age;

	/// patient's sleep
	int sleep;
	
	/// patient's sex
	string sex;

	/// patient's email
	string email;

	/// patient's email password
	string emailPassword;

	/// patient's exercise
	string exercise;

	/// patient's name
	string name;

	/// monitor records for the patient
	vector<MonitorRecord> *monitorRecords;

	/// medication records for the patient
	vector<MedicationRecord> *medicationRecords;

	/// patient's emergency contact
	Contact* emergencyContact;


};

#endif
