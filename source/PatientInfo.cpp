/**
*	\author Naeem Budwhani
*	\brief Contains statistics about the patient and his/her emergency contact information
*/

#include "PatientInfo.h"

/// implicit constructor
PatientInfo::PatientInfo()
{
	monitorRecords = new vector<MonitorRecord>;
	medicationRecords = new vector<MedicationRecord>;

	SetupPatientInfo();

	sleep = -1;
	exercise = "None";
	carbs = 0;
}

PatientInfo::PatientInfo(string name, double height, double weight, int age, string sex, string email, string emailPassword,
				Contact *emerg, vector<MonitorRecord> *monitor, vector<MedicationRecord> *medication)
{
	this->name = name;
	this->height = height;
	this->weight = weight;
	this->age = age;
	this->sex = sex;
	this->email = email;
	this->emailPassword = emailPassword;
	emergencyContact = emerg;
	monitorRecords = monitor;
	medicationRecords = medication;
}

/// constructor, expects patient info data
PatientInfo::PatientInfo(
	string name,
	int age,
	string sex,
	double weight,
	double height,
	string email
	):
	name(name),
	age(age),
	sex(sex),
	weight(weight),
	height(height),
	email(email)
{
	this->monitorRecords = new vector<MonitorRecord>;
	this->medicationRecords = new vector<MedicationRecord>;
}

/// destructor
PatientInfo::~PatientInfo()
{
}

/// gets the patient info weight
double PatientInfo::getWeight()
{
	return weight;
}

/// sets the patient info weight
void PatientInfo::setWeight(double Weight)
{
	this->weight = weight;
}

/// gets the patient info height
double PatientInfo::getHeight()
{
	return height;
}

/// sets the patient info height
void PatientInfo::setHeight(double height)
{
	this->height = height;
}

/// gets the patient info age
int PatientInfo::getAge()
{
	return age;
}

/// sets the patient info age
void PatientInfo::setAge(int age)
{
	this->age = age;
}

/// gets the patient info sex
string PatientInfo::getSex()
{
	return sex;
}

/// sets the patient info sex
void PatientInfo::setSex(string sex)
{
	this->sex = sex;
}

/// gets the patient info carb intake
double PatientInfo::getCarbs()
{
	return carbs;
}

/// sets the patient info carb intake
void PatientInfo::setCarbs(double carbs)
{
	this->carbs = carbs;
}

/// gets the patient info exercise
string PatientInfo::getExercise()
{
	return exercise;
}

/// sets the patient info exercise
void PatientInfo::setExercise(string exercise)
{
	this->exercise = exercise;
}

/// gets the patient info sleep
int PatientInfo::getSleep()
{
	return sleep;
}

/// sets the patient info sleep
void PatientInfo::setSleep(int sleep)
{
	this->sleep = sleep;
}

/// gets the emergency contact of the patient
Contact* PatientInfo::getEmergencyContact()
{
	return emergencyContact;
}

/// sets the emergency contact of the patient
void PatientInfo::setEmergencyContact(Contact* contact)
{
	this->emergencyContact = contact;
}

/// gets the patient info name
std::string PatientInfo::getName()
{
	return this->name;
}

/// gets the patient info email
string PatientInfo::getEmail() {
	return this->email;
}

/// sets the patient info email
void PatientInfo::setEmail(std::string email)
{
	this->email = email;
}

/// gets the patient info email password
string PatientInfo::getEmailPassword() {
	return this->emailPassword;
}

/// sets the patient info email password
void PatientInfo::setEmailPassword(std::string emailPassword)
{
	this->emailPassword = emailPassword;
}

/// gets the monitor records
vector<MonitorRecord> * PatientInfo::getMonitorRecords()
{
	return monitorRecords;
}

/// gets the medication records
vector<MedicationRecord> * PatientInfo::getMedicationRecords()
{
	return medicationRecords;
}

void PatientInfo::setName(std::string newName)
{
	name = newName;
}

/// fetches th patient info stored in patient.txt
void PatientInfo::SetupPatientInfo()
{
	cout << "What is your name? ";
	cin >> name;

	cout << "What is your weight? ";
	cin >> weight;

	cout << "What is your height? ";
	cin >> height;

	cout << "What is your age? ";
	cin >> age;

	cout << "What is your sex? ";
	cin >> sex;

	cout << "What is your email? ";
	cin >> email;

	cout << "What is your email password? ";
	cin >> emailPassword;

	// Set up emergency contact
	cout << "What is the name of your emergency contact? ";
	string emergContactName;
	string emergContactEmail;
	cin >> emergContactName;
	 
	cout << "What is the email of your emergency contact? ";
	cin >> emergContactEmail;

	emergencyContact = new Contact(emergContactName, emergContactEmail);

}
