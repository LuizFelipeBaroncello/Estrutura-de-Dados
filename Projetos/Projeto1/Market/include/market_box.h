#ifndef MARKETBOX_H
#define MARKETBOX_H

#include <stdexcept>
#include <string>

#include "linked_queue.h"
#include "performance.h"
#include "time.h"

//! Classe MarketBox para armazenar dados de um caixa de super mercado.
class MarketBox
{
    public:
        /*!
        *   Construtor.
        */
        MarketBox();

        /*!
        *   Construtor.
        *   \param identifier identificador do caixa.
        *   \param performance a performace do caixa.
        *   \param salary salario do caixa
        */
        MarketBox(std::string identifier, Performance* performance, double salary);

        /*!
        *   Destrutor.
        */
        virtual ~MarketBox();

        /*!
        *   \return retorna o numero de clientes na fila.
        */
        unsigned int get_num_of_clients_in_queue();

        /*!
        *   \return retorna o numero de produtos na fila.
        */
        unsigned int get_num_of_products_in_queue();

        /*!
        *   \return retorna o numero de clientes que ja foram atendidos.
        */
        unsigned int get_num_of_clients_served();

        /*!
        *   \return Retorna o tempo medio de espera de um cliente na fila.
        */
        Time* get_average_service_time();

        /*!
        *   \return faturamento total do caixa.
        */
        double get_total_billing();

        /*!
        *   \return faturamento medio do caixa.
        */
        double get_average_billing();

        /*!
        *   \return lucro do caixa.
        */
        double get_profit();

        /*!
        *   Adiciona um cliente ao caixa.
        *   \param cliente a ser adicionado.
        */
        void add_client(Client* client);

        /*!
        *   Retira o primeiro cliente da fila.
        */
        void remove_client();

        /*!
        *   \return o tempo no qual o primeiro cliente vai sair da fila.
        */
        Time* get_exit_time_of_first_client();

        /*!
        *   \return o identificador do caixa.
        */
        std::string get_identifier();


    private:
        /*!
        *   \return o tempo em segundos referente ao tempo de saida.
        */
        Time* output_time(Client* client);

        LinkedQueue* client_queue;       /*!< Fila com clientes no caixa. */
        std::string identifier_;        /*!< Id do funcionario. */
        Performance* performance_;      /*!< Performace do caixa. */
        unsigned int clients_served;    /*!< Numero de clientes que ja foram atendidos. */
        Time* total_hold_time;          /*!< Tempo total de espera. */
        double total_billing;           /*!< Faturamento total. */
        double salary_;                 /*!< Salario do caixa. */
};

#endif // MARKETBOX_H

