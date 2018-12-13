/**
	Laptop program to emulate insulin pump
	\author Graeme Brabers
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>

int main(int argc, char const *argv[]) 
{ 
    struct sockaddr_in serverAddress;
    int sock, messageBytes; 
    socklen_t clientSize;
    char buffer[549] = {0};
    std::stringstream input, output;
    std::string medication, amount;

    //establish socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    }

    serverAddress.sin_family = AF_INET; 
    serverAddress.sin_addr.s_addr = INADDR_ANY; 
    serverAddress.sin_port = htons(3307);

    //bind to socket
    if (bind(sock, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    //Listen for messages
    while(!std::cin.eof())
    {
        messageBytes = recv(sock, buffer, 549, 0);
        input.str(std::string(buffer));
        getline(input, medication, ',');
        getline(input, amount, '\n');
        output << "Received instruction to administer " << amount << " units of " << medication;
        std::cout << output.str() << std::endl;
        output.str(std::string());
        memset(buffer, 0, sizeof(buffer));
        input.clear();
        medication.clear();
        amount.clear();
    }
    return 0;
}
