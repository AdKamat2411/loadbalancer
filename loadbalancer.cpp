//loadbalancer.cpp

#ifndef LOADBALANCER_H
#include "loadbalancer.h"
#endif

int loadbalancer::getTime()
{
    return systemTime;
}

void loadbalancer::incTime()
{
    systemTime ++;
}

void loadbalancer::addRequest(request r)
{
    requestQueue.push(r);
    incTime();
}

request loadbalancer::getRequest()
{
    incTime();
    if (!requestQueue.empty())
    {
        request r = requestQueue.front();
        requestQueue.pop();
        return r;
    } else {
        throw std::out_of_range("Attempt to dequeue from empty queue");
    }
}

bool loadbalancer::isRequestQueueEmpty()
{
    return requestQueue.empty();
}