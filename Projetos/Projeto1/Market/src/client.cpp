#include "client.h"

Client::Client()
{

}

Client::Client(Time& arrival_time, int total_purchases, int total_purchases_value, int pay_type, int queue_type)
{

    total_purchases_= total_purchases;
    total_purchases_value_ = total_purchases_value;
    if (pay_type == 0) {
        pay_type_ = PayType::card;
    } else {
        pay_type_ = PayType::cash;
    }
    if (queue_type == 0 ) {
        queue_type_ = QueueType::less_size;
    } else {
        queue_type_ = QueueType::less_Products;
    }

    arrival_time_ = arrival_time;
}

Client::~Client()
{

}

void Client::set_exit_time(Time& exit_time)
{
    exit_time_ = exit_time;
}

const Time Client::get_arrival_time()
{
    return arrival_time_;
}

const Time Client::get_exit_time()
{
    return exit_time_;
}

const Time Client::get_average_time()
{
    return *new Time(get_exit_time().get_time_in_seconds() - get_arrival_time().get_time_in_seconds());
}

PayType Client::get_pay_type()
{
    return pay_type_;
}

QueueType Client::get_queue_type()
{
    return queue_type_;
}

unsigned int Client::get_total_purchases()
{
    return total_purchases_;
}

long int Client::get_total_value()
{
    return total_purchases_value_;
}
