/**
    Output interface for connection subclasses
    \author Graeme Brabers
*/
#ifndef INSULINPUMP_H
#define INSULINPUMP_H

#include "HormoneDose.h"

class InsulinPump
{
    public:
      /**
       * \brief pure virtual method to send instructions
       * \param hormone does a hormone dose
       * 
       */

        virtual void sendInstruction(const HormoneDose *) const = 0;
};

#endif