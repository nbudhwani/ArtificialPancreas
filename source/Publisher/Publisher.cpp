#include "Publisher.h"
#include "Subscriber.h"


template <class PublishType> 
void Publisher<PublishType>::addSubscriber(
    Subscriber<PublishType> subscriber)
{
    this->subscribers.push(subscriber);
}

template <class PublishType> 
void Publisher<PublishType>::publish(
    PublishType itemToPublish)
{
    for (auto &subscriber : this->subscribers)
    {
        subscriber.publishTo(itemToPublish);
    }
}