/**
 * \brief Glucose monitor.
 * \author Graeme
 * 
 * This class sets up glucose monitor and listens for values.
 *
 */

#ifndef GLUCOSEMONITOR_H
#define GLUCOSEMONITOR_H

#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <mutex>
#include <netinet/in.h>
#include "ArtificialPancreas.h"

#define PORT 3306

class GlucoseMonitor
{
    public:
	  /**
       * \brief Constructor
       *
       * Sets up monitor
       */
        GlucoseMonitor();

      /**
       * \brief Destructor
       *
       */
		~GlucoseMonitor();

      /**
       * \brief Sets up glucose monitor
       *
       * Sets up and binds to socket
       */
        void setup();


      /**
       * \brief Listens for glucose values
       * \param artificalPancreas the artifical pancreas
       *
       * Tells calculator to make calculation with glucose values and patient info
       */
        void listen(ArtificialPancreas *);
    
    private:
        struct sockaddr_in serverAddress;
        int sock;
        socklen_t clientSize;
        char buffer[549] = {0};
        std::string input;
};

#endif
