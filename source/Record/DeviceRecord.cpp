#include "DeviceRecord.h"

DeviceRecord::DeviceRecord(std::time_t time) : recordTime(time) 
{}

std::time_t DeviceRecord::getRecordTime() const
{
    return this->recordTime;
}
