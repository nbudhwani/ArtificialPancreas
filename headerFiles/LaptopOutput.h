/**
 * \brief connection implementation
 * \author Graeme Brabers
 * 
 * This class defines laptop insulin pump program
 *
 */

#ifndef LAPTOP_OUTPUT_H
#define LAPTOP_OUTPUT_H

#include <string>
#include <iostream>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "HormoneDose.h"
#include "InsulinPump.h"

class LaptopOutput : public InsulinPump
{

public:
	  /**
       * \brief Constructor
       * \param hostname a string
       * \param port a port number
       * 
       * Force connection
       */
	LaptopOutput(const std::string, const int);

	  /**
       * \brief Destructor
       *
       */
	~LaptopOutput();

	  /**
       * \brief Transmit message
       * \param hormoneDose a dose of hormone
       * 
       * Implements virtual method to transmit message
       */
	void sendInstruction(const HormoneDose *) const;

private:
	int sock;
	struct sockaddr_in server;

      /**
       * \brief Transmit message
       * \param hostname a string
       * \param port a port number
       * \return true if connection established
       * 
       * Establishes socket and  clears memory for connection
       */
	bool connectToPump(const std::string, const int);
	mutable std::string type, amount, strMessage;
	mutable std::stringstream message;
	mutable const char* charArrayMessage;
	LaptopOutput();
};

#endif