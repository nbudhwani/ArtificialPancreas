/**
 * \brief Establishes medication record.
 * \author Group 22
 * 
 * This class takes in time and hormone dose to establish a record.
 *
 */

#ifndef MEDICATIONRECORD_H
#define MEDICATIONRECORD_H

#include "DeviceRecord.h"
#include "HormoneDose.h"

class MedicationRecord : public DeviceRecord
{
    public:
      /**
       * \brief Constructor
       * \param time of dose 
       * \param hormone does with type and amount
       *
       * Sets up record
       */
        MedicationRecord(const std::time_t time, const HormoneDose dose);

      /**
       * \brief Returns hormoneDose
       * \return Hormone dose
       *
       * Returns hormone dosage 
       */
        HormoneDose getHormoneDose() const;
    private:
        const HormoneDose hormoneDose; 
};

#endif
