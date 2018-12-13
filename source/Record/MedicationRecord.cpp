#include "MedicationRecord.h"

MedicationRecord::MedicationRecord(const std::time_t time, const HormoneDose dose) 
    : DeviceRecord(time), hormoneDose(dose)
{}

HormoneDose MedicationRecord::getHormoneDose() const
{
    return this->hormoneDose;
}