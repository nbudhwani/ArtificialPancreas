/**
 * \brief Calculates hormone dosages based on user information.
 * \author Claire Dong
 * 
 * This class calculates basal insulin, bolus insulin and glucagon dosages in international units. 
 * Glucagon is administered when glucose levels are low.
 * Basal insulin dosages are given based on sleep time, exercise level, circadian rythm, age, and weight.
 * Bolus insulin dosages are given based on current glucose reading and carbohydrate intake. 
 *
 */

#ifndef MEDICATIONCALCULATOR_H
#define MEDICATIONCALCULATOR_H
#include <iostream>
#include <sys/types.h>
#include <sstream>
#include <string.h>
#include <math.h>
#include <ctime>
#include <iomanip>
#include "HormoneDose.h"
#include "PatientInfo.h"
#include "EmailNotification.h"

class MedicationCalculator
{
    public:
        
      /**
       * \brief Constructor
       * \param givenGlu a double glucose reading
       * \param patient a patientInfo with weight, age, sleep time, exercise, carbohydrate intake data
       * \param basalOrBolus a string specifying basal or bolus insulin
       *
       * Initializes values needed to calculate hormone dosages.
       */
        MedicationCalculator(double glu, PatientInfo *patient, std::string insType);
        
		  // Retrieves glucose reading
		  double GetGlucoseReading();

      /**
       * \brief Destructor
       *
       * Destructor of medication calculator
       */
        ~MedicationCalculator();

      /**
       * \brief Computes dosage required
       * \return HormoneDose with HormoneType and dosage in international units
       *
       * Computes dosages of glucagon, basal, or bolus insulin. 
       * Checks if patient is hypoglycemic and gives glucagon before checking insulin needs.
       * Basal is given once per hour.
       * Bolus is given when patient specifies their carbohydrate intake and when blood glucose correction is needed (every 25 mins).
       * Reference: https://www.vitamonk.com/blogs/health/guide-to-blood-sugar-levels
       */
		  HormoneDose * computeDosage();

    private:
        
        // Values needed to calculate dosage
        double gluRead;
        double weight;		
        double carbGrams;
		    PatientInfo *patientInfo;
        double TDD; // Total Daily Dose of insulin
        int age;
        int sleepHour;
        std::string exLevel;
        std::string insType;

        /** 
         * \brief Validate glucose readings
         *
         * Checks if glucose readings are within a valid range of 1.7 to 40 mmol/L.
         * Reference: https://www.vitamonk.com/blogs/health/guide-to-blood-sugar-levels
         */
        int validateReading();

        /** 
         * \brief Calculates glucagon dosage 
         * \return glucagon dosage in international units
         *
         * Admininister 1 unit of glucagon if patient is hypoglycemic (lower than 2.8mmol/L).
         * Reference: https://www.vitamonk.com/blogs/health/guide-to-blood-sugar-levels
         */
        double getGlucagon();

        /** 
         * \brief Calculates hourly basal insulin dosage
         * \return basal insulin dosage in international units
         *
         * Calculate hourly basal dose based on time to 2 decimals.
         * Accounts for circadian rythm where glucose levels decrease at night.
         * Accounts for the "Dawn phenomenon" where glucose is normally higher during dawn.
         * Uses Total Daily Dose of insulin, sleep time corrections of basal insulin, and exercise correction of basal insulin. 
         * Reference: http://perinatology.com/calculators/insulinpump.htm
         */
        double getHourBasal();

        /** 
         * \brief Calculates bolus insulin dosage
         * \return bolus insulin dosage in international units
         *
         * Calculate total bolus amount to accound for meal size and blood glucose correction.
         * Reference: http://perinatology.com/calculators/insulinpump.htm
         */
        double getBolus();
        
        /** 
         * \brief Corrects basal insulin dose based on sleep time given
         * \param uncorrected double basal insulin dosage
         * \return basal insulin dosage in international units
         *
         * Adjusts basal insulin based on user provided sleep time only if glucose levels stray away
         * from age-dependent range. 
         * Uses default of 11pm - 7am if sleep time not given.
         * Reference: http://perinatology.com/calculators/insulinpump.htm
         */
        double calcSleep(double basal);

        /** 
         * \brief Corrects basal insulin dose based on exercise level given
         * \param uncorrected double basal insulin dosage
         * \return corrected basal insulin dosage in international units
         *
         * Adjusts basal insulin based on user exercise level. Exercise is identified as low, medium, or high.
         * Reference: https://www.ncbi.nlm.nih.gov/pmc/articles/PMC4930462/
         */
        double calcEx(double basal);

        /** 
         * \brief Corrects bolus insulin dose based on carbohydrate intake in grams
         * \param uncorrected double basal insulin dosage
         * \return corrected bolus insulin dosage in international units
         *
         * Calculates bolus insulin dose based on carbohydrate intake and total daily dose of basal insulin.
         * Reference: http://perinatology.com/calculators/insulinpump.htm
         */        
        double calcMeal();


        /** 
         * \brief Corrects bolus insulin dose based on current glucose reading
         * \return corrected bolus insulin dosage in international units
         *
         * Calculates insulin sensitivity factor and finds correction dose based on appropriate 
         * glucose range for the age provided.
         * Reference: http://perinatology.com/calculators/insulinpump.htm
         */  
        double calcCorrection();

        /** 
         * \brief Finds current time
         * \return integer hour in military time
         *
         * Finds local hour and returns hour as an integer.
         */ 
        int findCurrentHour();

        /** 
         * \brief Calculates total daily dose
         * \return total daily dose in international units
         *
         * Helper function that calculate total daily dose of basal insulin (TDD) using weight.
         * Reference: http://perinatology.com/calculators/insulinpump.htm
         */
        double getTDD();
};

#endif
