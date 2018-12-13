/**
    Subscriber set up
    \author Group 22
*/

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

template <class SubscriptionType> class Subscriber
{
    public:
      /**
       * \brief pure virtual method for subscribers
       * \param a subscription type
       * 
       */
        virtual void publishTo(SubscriptionType) = 0;
};

#endif