#include "user_interaction.h"
#include <iostream>
#include <sstream>
#include <iomanip> // Manipulação de entrada e saída

using namespace std;

namespace read {

    auto count = 0u;
    string buffer[4];

    void UserInteraction::read_market(std::istream &in)
    {
        string name;
        unsigned int performance;
        double salary;

        // Lê linha por linha até o final do arquivo.
        // Enquanto não encontrar a marca de fim de arquivo:

        for (auto i = 0u; count < 4; ++i) {
            if (!read_comment(in)) {
                buffer[count] = linha;
                count++;
            }
        }

        while (!in.eof()) {
            in >> name >> performance >> salary;
            if (name[0] != '#' && name[0] != '\n' && !in.eof()) {

                market.add_box(name, performance, salary);
            }
        }
        insert(buffer);
     }

    bool UserInteraction::read_comment(std::istream &in)
    {
        string test;

        auto counter = 0u;
        getline(in, test);

        if (test[0] == '\n')
            return true;

        while (test[counter] == ' ') {
            counter++;
        }

        if (test[counter] == '#') {
            linha = "";
            return true;
        } else {
            linha = test;
            return false;
        }
    }

    // std::stoi -> converte string para inteiro

    void UserInteraction::insert(string buffer[])
    {
        market_name = buffer[0];
        time_of_simulation_in_hours = std::stoi(buffer[1]);
        average_arrival_time_of_customers_in_seconds = std::stoi(buffer[2]);
        number_of_market_box = std::stoi(buffer[3]);

        market = new Market(get_market_name(), get_time_of_simulation_in_hours(), get_average_arrival_time_of_customers_in_seconds());
    }

  std::string UserInteraction::get_market_name()
  {
      return market_name;
  }

  unsigned int UserInteraction::get_time_of_simulation_in_hours()
  {
      return time_of_simulation_in_hours;
  }

  unsigned int UserInteraction::get_average_arrival_time_of_customers_in_seconds()
  {
      return average_arrival_time_of_customers_in_seconds;
  }

  unsigned int UserInteraction::get_number_of_market_box()
  {
      return number_of_market_box;
  }

}
