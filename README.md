# Glucose Guardian: The Artificial Pancreas

This is a software application which emulates the function of a human pancreas.  
The Glucose Guardian takes in insulin readings from an external device and sends an insulin dosage  
as a result. It can also store patient information to create reports and respond to emergency situations.  

NOTE: For testing purposes please use the provided test gmail account  
Email Address: noah123body@gmail.com  
Email Password: pass123word

### Authors

Claire Dong  
Graeme Brabers  
Naeem Budhwani  
Thomas Vandeveen  
Veronica Witzig  

# How to build Glucose Guardian

You will need 3 terminals for the full functionality of Glucose Guardian.  
- 1 terminal will be used for the monitor
  - Monitor is the glucose monitor that provides blood glucose readings to the pi
- 1 terminal will be used for running main 
  - Main is the UI for user interaction with the artifical pancreas
- 1 terminal will be used for the listener
  - Listener is the insulin pump that waits for information from the pi and dispenses insulin  

First you need to build the project, to do this run this command in the terminal:

```c++
make all  
```

Once the project has been built, you can run the program by executing the runGlucoseGuardian file:  

```c++
./runGlucoseGuardian.sh
```

**Please ensure a user is set up with accurate weight and personal information before inputting glucose readings.**  
**Before reporting medical records you will need to wait for 2 min and have entered glucose readings through the monitor**

# How to run acceptance tests

For ease of testing, we have included individual testing classes for certain features of the project: 

### Account Security
We have included a layer of security to protect the patient and their medical information. To see a
demonstration of an account being created during initialization, please run:

```c++
make AccountTest.run
```

If you run the test again you can see how an account is logged into after the account has been made.

### Email Notifications
During certain actions an email notification may be sent to the user. These instances include:  
- A warning email when a hypoglycemic event is imminent
- A security warning when a failed attempt to login to the artificial pancreas has been made
- An emergency email to the patient's emergency contact when the patient has entered into a hypoglycemic state
- A notification email when an authorized guest account has requested access to the patient's
medical records
To see a demonstration of this use:

```c++
make EmailNotificationTest.run
```

**Note: We have provided a test email you may use**  
Email Address: noah123body@gmail.com  
Email Password: pass123word  

### UI Menu
Depending on whether the patient or an authorized guest has logged into Glucose Guardian, this will  
determine which menu items are available for the user to select from.

If a patient is logged in, they are able to do:  
- Manual Insulin Administration
- Manual Glucose Entries
- Make a report of their medical records
- Update their carbohydrate intake, expected hours of sleep, and exercise levels

If a guest is logged in, they are able to:  
- Make a report of the patient's medical records

To run this test:

```c++
make MenuTest.run
```

### Report Maker
The user is able to make a graphical report of medical records. This medical record includes glucose readings  
and insulin administered measured over time. To see a demonstration of this run:

```c++
make ReportMakerTest.run
```

### Insulin Calculator
Glucose Guardian is able to automatically determine the correct insulin or glucagon to administer  
based on age, weight, height, carb intake, exercise level, diurnal pattern, and time of sleep.  
The test will prompt you for these while running:

```c++
make MedicationCalculatorTest.run
```
