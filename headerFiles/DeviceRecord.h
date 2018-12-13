/**
 * \brief Gets time of record
 * \author Group 22
 * 
 * This class keeps track of time of records
 *
 */

#ifndef DEVICERECORD_H
#define DEVICERECORD_H

#include <ctime>

class DeviceRecord
{
    public:
      /**
       * \brief Constructor
       * \param time time of device record
       */
        DeviceRecord(std::time_t time);

      /**
       * \brief returns record time 
       * \return time of record
       */
        std::time_t getRecordTime() const;
    private:
        /// the time that the record was created
        const std::time_t recordTime;
};

#endif
