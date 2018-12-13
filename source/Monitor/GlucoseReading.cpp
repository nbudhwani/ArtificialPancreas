#include "GlucoseReading.h"

GlucoseReading::GlucoseReading(const double glucoseAmount) 
    :   amount(glucoseAmount)
{}

const double GlucoseReading::getAmount() const
{
    return this->amount;
}