/**
 * \brief Represents hormone dose to administer
 * \author Graeme Brabers
 * 
 * This class represents a hormone dose of basal insulin, bolus insulin, or glucagon with dosages in international units.
 *
 */
#ifndef HORMONEDOSE_H
#define HORMONEDOSE_H

/**
 * \brief Enum of hormone type.
 *
 * Hormone type is basal insulin, bolus insulin, or glucagon.
*/
enum hormoneType {BASAL_INSULIN, BOLUS_INSULIN, GLUCAGON};

class HormoneDose {
	
public:

      /**
       * \brief Constructor
       *
       * Constructor of hormone type
       */
       HormoneDose();

      /**
       * \brief Constructor
       * \param hormoneType enum of basal, bolus, or glucagon
       * \param units as a double
       *
       * Constructor of hormone type
       */
	   HormoneDose(hormoneType, double);

      /**
       * \brief Destructor
       *
       * Destructor of medication calculator
       */
	   ~HormoneDose();

	  /**
       * \brief Gets type of hormone
       * \return hormoneType enum of basal, bolus, or glucagon
       *
       * Returns type of hormone
       */
	   const enum hormoneType getHormoneType() const;
	

	  /**
       * \brief Gets amount of hormone
       * \return double of hormone dosage in international units
       *
       * Returns dosage in international units
       */
	   const double getHormoneAmount() const;

	  /**
       * \brief Sets amount of hormone
       * \param hormoneType enum of basal, bolus, or glucagon
       *
       * Allows hormone type to be set
       */
	   void setHormoneType(const hormoneType);

	  /**
       * \brief Sets dosage of hormone
       * \param double of dosage in international units
       *
       * Allows hormone dosage to be set
       */
	   void setHormoneAmount(const double);

private:
	double hormoneAmount;
	hormoneType type;

};

#endif
