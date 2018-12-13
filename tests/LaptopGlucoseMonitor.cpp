/*
	Laptop glucose monitor
	author: Graeme Brabers
*/

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int sock;
	struct sockaddr_in server;
    std::string address = "127.0.0.1", input;


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
	server.sin_port = htons(3306);
	server.sin_addr.s_addr = inet_addr(address.c_str());

    if (sock == -1)
	{
		std::cout << "Error: socket not established" << std::endl;
	}
	else
	{
		while(!std::cin.eof())
        {
            std::cout << "Enter glucose measurement: ";
            std::cin >> input;
            std::cout << std::endl;
            const char *amount = input.c_str();
            sendto(sock, amount, strlen(amount),
			MSG_CONFIRM, (const struct sockaddr *) &server, sizeof(server));
        }
	}
}
