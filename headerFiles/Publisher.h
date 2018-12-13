/**
 * \brief Glucose monitor.
 * \author Group 22
 * 
 * This class implements publisher and subscriber relationship.
 *
 */

#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Subscriber.h"
#include <vector>

template <class PublishType> class Publisher
{
    public:
      /**
       * \brief adds subscriber
       * \param a subscriber
       *
       * Adds subscriber to a vector
       */
        void addSubscriber(Subscriber<PublishType>);
    protected:
      /**
       * \brief publishes subscribers
       * \param an item to publish
       *
       * Publishes subscriber information
       */
        void publish(PublishType);
    private:
        std::vector<Subscriber<PublishType>> subscribers;
};

#endif
