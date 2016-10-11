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
    while(time_of_simulation_->get_time_in_hours() > clock->get_time()->get_time_in_hours()) {
        simulate_box();

        if (clock->get_time()->get_time_in_seconds() == time_of_next_client->get_time_in_seconds()) {
            Client* client = new Client(clock->get_time());

            if (!full_market()) {
                if (client->get_queue_type() == QueueType::less_Products) {
                    add_client_less_products_queue(client);
                } else {
                    add_client_less_size_queue(client);
                }
            } else {
                billing_lost += client->get_total_value();
                delete client;
                if (reserve_box) {
                    add_box("Caixa Reserva", 1, 1600);
                    reserve_box = false;
                }
            }
        }
        clock->add_seconds(1u);
    }

    while (clock->get_time()->get_time_in_seconds() < getMaxSizeQueue e pegar tempo de saida do ultimo) {
        simulate_box();
        clock->add_seconds(1u);
    }
}

bool Market::full_market()
{
    bool available_market = false;

    box_list->passes_forward();
    while (box_list->get_data_pointer_element() != nullptr) {
        if (box_list->get_data_pointer_element()->get_num_of_clients_in_queue() == max_clients_in_queue_){
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
    int less_size_queue = 50;

    box_list->passes_forward();
    while (box_list->get_data_pointer_element() != nullptr) {
        if (box_list->get_data_pointer_element()->get_num_of_clients_in_queue() < less_size_queue) {
            less_size_queue = box_list->get_data_pointer_element()->get_num_of_clients_in_queue();
            aux_less_size = box_list->get_data_pointer_element();
        }
        box_list->passes_forward();
    }

    if (aux_less_size->get_num_of_clients_in_queue() == max_clients_in_queue_) {
        billing_lost += client->get_total_value();
        delete client;
    } else {
        aux_less_size->add_client(client);
    }

}

void Market::add_client_less_products_queue(Client* client)
{
    MarketBox* aux_less_products;
    int less_products_queue = 10000000000000;

     box_list->passes_forward();
     while (box_list->get_data_pointer_element() != nullptr) {
        if (box_list->get_data_pointer_element()->get_num_of_products_in_queue() < less_products_queue) {
            less_products_queue = box_list->get_data_pointer_element()->get_num_of_products_in_queue();
            aux_less_products = box_list->get_data_pointer_element();
        }
        box_list->passes_forward();
    }
    if (aux_less_products->get_num_of_clients_in_queue() == max_clients_in_queue_) {
        billing_lost += client->get_total_value();
        delete client;
    } else {
        aux_less_products->add_client(client);
    }
}

void Market::simulate_box()
{
    box_list->passes_forward();
    while (box_list->get_data_pointer_element() != nullptr) {
        if (box_list->get_data_pointer_element()->get_exit_time_of_first_client()->get_time_in_seconds() == clock->get_time()->get_time_in_seconds()) {
            box_list->get_data_pointer_element()->remove_client();
        }
        box_list->passes_forward();
    }
}
