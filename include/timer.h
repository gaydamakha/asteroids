#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
    virtual double getDelta() = 0;

    virtual double getTimestamp() const = 0;
};

#endif