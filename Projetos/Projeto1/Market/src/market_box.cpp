#include <iostream>

#include "market_box.h"

MarketBox::MarketBox()
{

}

MarketBox::MarketBox(std::string identifier, Performance* performance, double salary)
{
    client_queue = new LinkedQueue();
    identifier_ = identifier;
    performance_ = performance;
    salary_ = salary;
    clients_served = 0;
    total_hold_time = new Time(0u);
    total_billing = 0;
}

MarketBox::~MarketBox()
{
    delete performance_;
}

unsigned int MarketBox::get_num_of_clients_in_queue()
{
    return client_queue->num_people();
}

unsigned int MarketBox::get_num_of_products_in_queue()
{
    return client_queue->num_products();
}

unsigned int MarketBox::get_num_of_clients_served()
{
    return clients_served;
}

const Time MarketBox::get_average_service_time()
{
    if (clients_served+client_queue->num_people() != 0) {
        return * new Time(total_hold_time->get_time_in_seconds()/(clients_served+client_queue->num_people()));
    } else {
        return * new Time(0);
    }
}

long int MarketBox::get_total_billing()
{
    return total_billing;
}

long int MarketBox::get_average_billing()
{
    if (clients_served+client_queue->num_people() != 0) {
        return total_billing/(clients_served+client_queue->num_people());
    } else {
        return 0;
    }
}

long int MarketBox::get_profit()
{
    return total_billing - salary_;
}

void MarketBox::add_client(Client& client)
{
    client.set_exit_time(output_time(client));
    total_billing += client.get_total_value();
    total_hold_time->add_seconds(client.get_average_time().get_time_in_seconds());
    client_queue->enqueue(client);
}

Time& MarketBox::output_time(Client& client)
{
        int exit_time = performance_->get_time_to_spend_item() * client.get_total_purchases();

        if (client.get_pay_type() == 0)
            exit_time += performance_->get_time_to_spend_card();
        if (client_queue->empty()) {
            exit_time += client.get_arrival_time().get_time_in_seconds();
        } else {
            exit_time += client_queue->back().get_exit_time().get_time_in_seconds();
        }


    return * new Time(exit_time);
}

void MarketBox::remove_client()
{
    clients_served++;
    client_queue->dequeue();
}

const Time MarketBox::get_exit_time_of_first_client()
{
    try {
        return client_queue->front().get_exit_time();
    } catch (std::out_of_range e) {
        return * new Time(-1);
    }

}

std::string MarketBox::get_identifier()
{
    return identifier_;
}
