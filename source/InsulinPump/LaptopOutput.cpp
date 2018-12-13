/**
	Laptop connection implementation
	author: Graeme Brabers
*/

#include "LaptopOutput.h"


bool LaptopOutput::connectToPump(const std::string address, const int port)
{
	//establish socket
	if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
	{
		std::cout << "Socket creation error" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Socket created" << std::endl;
	}

	//clear memory for connection
	memset(&server, '0', sizeof(server));
	
	//server settings
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr(address.c_str());

	// return true once we obtain connection
	return true;
}

//default constructor - not used
LaptopOutput::LaptopOutput()
{
}

//overloaded constructor - force connection
LaptopOutput::LaptopOutput(const std::string hostname, const int port)
{
	LaptopOutput::connectToPump(hostname, port);
}

//destructor
LaptopOutput::~LaptopOutput()
{
	close(sock);
}

//transmit message
void LaptopOutput::sendInstruction(const HormoneDose * hormone) const
{
	if (sock == -1)
	{
		std::cout << "Error: socket not established" << std::endl;
	}
	else
	{
		switch (hormone->getHormoneType())
		{
		case BASAL_INSULIN:
			type = "BASAL_INSULIN";
			break;
		case BOLUS_INSULIN:
			type = "BOLUS_INSULIN";
			break;
		case GLUCAGON:
			type = "GLUCAGON";
			break;
		}

		amount = std::to_string(hormone->getHormoneAmount());
		message.str(std::string());
		message << type << "," << amount;
		strMessage = message.str();
		charArrayMessage = strMessage.c_str();
		sendto(sock, charArrayMessage, strlen(charArrayMessage),
			MSG_CONFIRM, (const struct sockaddr *) &server, sizeof(server));
	}
}
