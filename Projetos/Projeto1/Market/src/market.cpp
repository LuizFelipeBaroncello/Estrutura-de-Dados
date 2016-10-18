#include "market.h"

Market::Market(std::string market_name,unsigned int time_of_simulation, unsigned int average_time_of_arrival_of_clients, unsigned int max_clients_in_queue)
{
    box_list = new CircularList();
    clock = new Clock();
    reserve_box = true;
    clients_dropped_out = 0;
    market_name_ = market_name;
    time_of_simulation_ = new Time(time_of_simulation*3600);
    average_time_of_arrival_of_clients_ = new Time(average_time_of_arrival_of_clients);
    time_of_next_client = new Time(0u);
    max_clients_in_queue_ = max_clients_in_queue;
    billing_lost = 0;
}

Market::~Market()
{
    delete box_list;
    delete clock;
    delete time_of_simulation_;
    delete average_time_of_arrival_of_clients_;
    delete bad_box_perform;
    delete medium_box_perform;
    delete good_box_perform;
    delete time_of_next_client;
}

void Market::add_box(std::string nome, unsigned int performance, double salary)
{
    switch (performance){
        case 1:
               box_list->push_front(new MarketBox(nome, good_box_perform, salary));
            break;
        case 2:
               box_list->push_front(new MarketBox(nome, medium_box_perform, salary));
            break;
        case 3:
               box_list->push_front(new MarketBox(nome, bad_box_perform, salary));
            break;
        default:
            break;
    }
}

void Market::start_simulation()
{
    srand(time(0));
    while(time_of_simulation_->get_time_in_hours() > clock->get_time()->get_time_in_hours()) {
        simulate_box();

        if (clock->get_time()->get_time_in_seconds() == time_of_next_client->get_time_in_seconds()) {
            int total_purchases = get_total_purchases();
            Client* client = new Client(*clock->get_time(), total_purchases, get_total_purchases_value(total_purchases), get_pay_type(), get_queue_type());

            if (!full_market()) {
                add_client(client);
            } else {
                set_dropped_client(client);
            }
            time_of_next_client->add_seconds(average_time_of_arrival_of_clients_->get_time_in_seconds());
        }
        clock->add_seconds(1u);
    }
}

bool Market::full_market()
{
    bool available_market = false;

    box_list->passes_forward();
    while (box_list->get_data_pointer_element()->get_identifier() != "sentinel") {
        if (box_list->get_data_pointer_element()->get_num_of_clients_in_queue() > max_clients_in_queue_){
            available_market = false || available_market;
        } else {
            available_market = true;
        }
        box_list->passes_forward();
    }
    return !available_market;
}

void Market::add_client_less_size_queue(Client* client)
{
    MarketBox* aux_less_size;
    int less_size = 50;
    box_list->passes_forward();
    while (box_list->get_data_pointer_element()->get_identifier() != "sentinel") {
        if (box_list->get_data_pointer_element()->get_num_of_clients_in_queue() < less_size) {
            less_size = box_list->get_data_pointer_element()->get_num_of_clients_in_queue();
            aux_less_size = box_list->get_data_pointer_element();
        }
        box_list->passes_forward();    }

    if (aux_less_size->get_num_of_clients_in_queue() == max_clients_in_queue_) {
        set_dropped_client(client);
    } else {
        aux_less_size->add_client(*client);
    }

}

void Market::add_client_less_products_queue(Client* client)
{
    MarketBox* aux_less_products;
    int less_products = 10000000000;

     box_list->passes_forward();
     while (box_list->get_data_pointer_element()->get_identifier() != "sentinel") {
        if (box_list->get_data_pointer_element()->get_num_of_products_in_queue() < less_products) {
            less_products = box_list->get_data_pointer_element()->get_num_of_products_in_queue();
            aux_less_products = box_list->get_data_pointer_element();
        }
        box_list->passes_forward();
    }
    if (aux_less_products->get_num_of_clients_in_queue() == max_clients_in_queue_) {
        set_dropped_client(client);
    } else {
        aux_less_products->add_client(*client);
    }
}

void Market::simulate_box()
{
    box_list->passes_forward();
    while (box_list->get_data_pointer_element()->get_identifier() != "sentinel") {        if (box_list->get_data_pointer_element()->get_exit_time_of_first_client().get_time_in_seconds() == clock->get_time()->get_time_in_seconds()) {
            box_list->get_data_pointer_element()->remove_client();
        }
        box_list->passes_forward();
    }
}

long int Market::get_total_billing()
{
    long int total_billing = 0;

    box_list->passes_forward();
    while (box_list->get_data_pointer_element()->get_identifier() != "sentinel") {
        total_billing += box_list->get_data_pointer_element()->get_total_billing();
        box_list->passes_forward();
    }

    return total_billing;
}

long int Market::get_average_billing()
{
    long int average_billing = 0;
    for (auto i = 0; i < box_list->size() ; i++) {
        average_billing += box_list->at(i)->get_average_billing();
    }

    return average_billing/box_list->size();
}

long int Market::get_total_profit()
{
    long int total_profit = 0;
    for (auto i = 0; i < box_list->size() ; i++) {
        total_profit += box_list->at(i)->get_profit();
    }

    return total_profit;
}

long int Market::get_average_queue_time_in_seconds()
{
    long int total_time = 0;

    box_list->passes_forward();
    while (box_list->get_data_pointer_element()->get_identifier() != "sentinel") {
        total_time += box_list->get_data_pointer_element()->get_average_service_time().get_time_in_seconds();
        box_list->passes_forward();
    }

    return total_time/box_list->size();
}

void Market::add_client(Client* client)
{
    if (client->get_queue_type() == 0) {
        add_client_less_size_queue(client);
    } else {
        add_client_less_products_queue(client);
    }

}

void Market::set_dropped_client(Client* client)
{
    clients_dropped_out++;
    billing_lost += client->get_total_value();

    if (reserve_box) {
        add_box("Reserva", 1, 1600);
        reserve_box = false;
    }
}

long int Market::get_average_billing_box(unsigned int index) {
    return box_list->at(index)->get_average_billing();
}

long int Market::get_billing(unsigned int index) {
    return box_list->at(index)->get_total_billing();
}

long int Market::get_profit(unsigned int index) {
    return box_list->at(index)->get_profit();
}

int Market::get_dropped_out() {
    return clients_dropped_out;
}

long int Market::get_billing_lost() {
    return billing_lost;
}

std::string Market::get_market_name() {
    return market_name_;
}

std::string Market::get_identifier(unsigned int index) {
    return box_list->at(index)->get_identifier();
}

int Market::get_num_of_boxes() {
    return box_list->size();
}

int Market::get_queue_type()
{
    return rand() %2;
}

int Market::get_pay_type()
{
    int pay_type = 1 + (rand() %100);

    if (pay_type < 80) {
        return 0;
    } else {
        return 1;
    }
}

int Market::get_total_purchases_value(int total_purchases)
{
    int total_purchases_value_ = 0;

    for (auto i = 0; i < total_purchases; i++) {
        total_purchases_value_ += (1 + (rand()%89));
    }
    if (total_purchases_value_ > 10000) {
        return get_total_purchases_value(total_purchases);
    }
    return total_purchases_value_;
}

int Market::get_total_purchases()
{
    return 2+ (rand() %98);
}
