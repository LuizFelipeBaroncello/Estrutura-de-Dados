#include "clock.h"

Clock::Clock()
{
    time = new Time();
}

Clock::~Clock()
{
    delete time;
}

void Clock::add_seconds(const unsigned int& seconds)
{
    time->add_seconds(seconds);
}

void Clock::set_one_more_second()
{
    time->add_seconds(1);
}

Time* Clock::get_time() const
{
    return time;
}
