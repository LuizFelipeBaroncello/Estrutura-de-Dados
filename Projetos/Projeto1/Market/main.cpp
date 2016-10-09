#include <iostream>
#include <stdio.h>
#include "performance.h"
#include "lukas.h"
#include "TestLuiz.h"
#include "user_interaction.h"
#include <sstream>
#include <fstream>
#include <string>

#include <iostream>

using namespace std;

int main()
{


       //     TestLuiz* testes = new TestLuiz();
      //      Lukas* lks = new Lukas();

    using namespace read;
    //std::ifstream ss{"input.txt"};
    std::ifstream ss;
    ss.open("input.dat");

    UserInteraction user;
    user.read_market(ss);

    // Fecha o arquivo
    ss.close();

    cout << "Market Name: " << user.get_market_name() << "\n"
         << "Time of Simulation (in hours): " << user.get_time_of_simulation_in_hours() << "\n"
         << "Average Arrival Time of Customers (in seconds): " << user.get_average_arrival_time_of_customers_in_seconds() << "\n"
         << "Number of Market Box: " << user.get_number_of_market_box() << "\n";

}

