#include "time_p.h"

Time::Time()
{
    time_in_seconds = 0u;
}

Time::Time(unsigned int time)
{
    time_in_seconds = time;
}

void Time::add_seconds(const unsigned int& seconds)
{
    time_in_seconds += seconds;
}

const unsigned int Time::get_time_in_seconds() const
{
    return time_in_seconds;
}

const unsigned int Time::get_time_in_minutes() const
{
    return (get_time_in_seconds()/60);
}

const unsigned int Time::get_time_in_hours() const
{
    return get_time_in_minutes()/60;
}
