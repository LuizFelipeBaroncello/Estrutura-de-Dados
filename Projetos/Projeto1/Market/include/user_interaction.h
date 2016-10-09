#ifndef READ_USER_INTERACTION_H
#define READ_USER_INTERACTION_H

#include <string>
#include <fstream>
#include <sstream>
#include "market.h"

namespace read {

class UserInteraction
{
    public:
        void read_market(std::istream &);
        bool read_comment(std::istream &);
        void insert(std::string buffer[]);
        std::string get_market_name();
        unsigned int get_time_of_simulation_in_hours();
        unsigned int get_average_arrival_time_of_customers_in_seconds();
        unsigned int get_number_of_market_box();

    private:
        std::string linha;
        std::string market_name;
        unsigned int time_of_simulation_in_hours;
        unsigned int average_arrival_time_of_customers_in_seconds;
        unsigned int number_of_market_box;
        // Criação do mercado com os atributos de simulação recolhidos do input.dat
        *Market market;
};

}

#endif
