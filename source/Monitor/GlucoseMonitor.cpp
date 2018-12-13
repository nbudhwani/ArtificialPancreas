#include "GlucoseMonitor.h"

GlucoseMonitor::GlucoseMonitor()
{
    setup();
}

GlucoseMonitor::~GlucoseMonitor()
{
    
}

void GlucoseMonitor::setup()
{
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    //bind to socket
    if (bind(sock, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

void GlucoseMonitor::listen(ArtificialPancreas * pancreas)
{
    int count = 1;
    while(true)
    {
        recv(sock, buffer, 549, 0);
        input = buffer;
        if(count % 4 == 0)
        {
            pancreas->calculateMedication(stod(input), "Basal");
        }
        else
        {
            pancreas->calculateMedication(stod(input), "Bolus");
        }
        count++;
        memset(buffer, 0, sizeof(buffer));
        input.clear();
    }
}
