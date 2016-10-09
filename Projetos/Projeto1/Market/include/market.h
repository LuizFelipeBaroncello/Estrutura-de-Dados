#ifndef MARKET_H
#define MARKET_H
#include <string>

#include "performance.h"
#include "clock.h"
#include "circular_list.h"
#include "market_box.h"
#include "client.h"
#include "linked_queue.h"

//! Classe Market para simulacao do projeto.
class Market
{
    public:
        /*!
        *   Construtor.
        *   \param nome do mercado.
        *   \param tempo de simulacao em horas.
        *   \param tempo medio para chegada de um novo cliente.
        */
        Market(std::string market_name,unsigned int time_of_simulation, unsigned int average_time_of_arrival_of_clients);

        /*!
        *   Destrutor.
        */
        virtual ~Market();

        /*!
        *   Metodo Usado para se adicionar novos caixas ao supermercado.
        */
        void add_box(std::string nome, unsigned int performance, double salary);

        /*!
        *   Com os dados recebidos realiza a simulacao de funcionamento.
        */
        void start_simulation();

        double get_total_billing();

        double get_average_billing();

        //double

        //botar geters de informacoes aqui

    protected:

    private:
        CircularList* box_list;
        Clock* clock;
        unsigned int clients_dropped_out;
        std::string market_name_;
        Time* time_of_simulation_;
        Time* average_time_of_arrival_of_clients_;

        Performance* bad_box_perform = new Performance(60u, 4);
        Performance* medium_box_perform = new Performance(25u, 2);
        Performance* good_box_perform = new Performance(10u, 1);

};

#endif // MARKET_H
