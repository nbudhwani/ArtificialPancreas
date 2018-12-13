#include "TestResult.h"

TestResult::TestResult(const TestValue value, const std::string message)
    :   value(value), message(message)
{}

TestValue TestResult::getValue() const
{
    return this->value;
}

std::string TestResult::getMessage() const
{
    return this->message;
}

std::string TestResult::toString() const
{
    std::stringstream ss;
    ss  << (this->getValue() == TestValue::Failure ? "Failure" : "Success") 
        << std::endl << this->getMessage();
    return ss.str();
}