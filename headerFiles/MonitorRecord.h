/**
 * \brief Monitor Record
 * \author Group 22
 * 
 * This class records glucose readings for reports.
 *
 */

#ifndef MONITORRECORD_H
#define MONITORRECORD_H

#include "DeviceRecord.h"
#include "GlucoseReading.h"

class MonitorRecord : public DeviceRecord
{
    public:
      /**
       * \brief Constructor
       * \param time of glucose reading
       * \param values of blood glucose
       *
       * Sets up record
       */
        MonitorRecord(std::time_t time, GlucoseReading reading);

      /**
       * \brief Returns glucose reading
       * \return glucoseReading
       *
       * Returns a glucose value 
       */
        GlucoseReading getReading() const;
    private:
        const GlucoseReading reading;
};

#endif
