/*!
 *  \author Luiz Felipe Ribeiro Baroncello
 *  \author Lukas Derner Grüdtner
 *  \version 1.0
 *  \copyright General Public License version 2
 *
 */

#ifndef MARKET_H
#define MARKET_H

#include <string>
#include <stdlib.h>
#include <time.h>

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
        Market(std::string market_name,unsigned int time_of_simulation, unsigned int average_time_of_arrival_of_clients, unsigned int max_clients_in_queue);

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

        /*!
        *   \return faturamento total.
        */
        long int get_total_billing();

        /*!
        *   \return faturamento medio por caixa  .
        */
        long int get_average_billing();

        /*!
        *   \param posicao de caixa q se deseja saber a informacao.
        *   \return faturamento medio de caixa em especifico.
        */
        long int get_average_billing_box(unsigned int index);

        /*!
        *   \param posicao de caixa q se deseja saber a informacao.
        *   \return faturamento total de caixa em especifico.
        */
        long int get_billing(unsigned int index);

        /*!
        *   \return lucro total.
        */
        long int get_total_profit();

        /*!
        *   \param posicao de caixa q se deseja saber a informacao.
        *   \return lucro provido por determinado caixa.
        */
        long int get_profit(unsigned int index);

        /*!
        *   \return tempo medio que um cliente passa na fila ao chegar nesse mercado.
        */
        long int get_average_queue_time_in_seconds();

        /*!
        *   \return numero de clientes q desistiram.
        */
        int get_dropped_out();

        /*!
        *   \return faturamento que deixou de ser realizado.
        */
        long int get_billing_lost();

        /*!
        *   \return nome do mercado.
        */
        std::string get_market_name();

        /*!
        *   \param posicao de caixa q se deseja saber a informacao.
        *   \return identificador do caixa.
        */
        std::string get_identifier(unsigned int index);

        /*!
        *   \return numero de caixas adicionados ao mercado.
        */
        int get_num_of_boxes();

    private:
        /*!
        *   \return true se todas as filas estiverem cheias.
        */
        bool full_market();

        /*!
        *   Reponsavel por adicionar o cliente na fila de menor tamanho.
        *   \param cliente a ser adicionado em uma das filas.
        */
        void add_client_less_size_queue(Client* client);

        /*!
        *   Reponsavel por adicionar o cliente na fila com menos produtos.
        *   \param cliente a ser adicionado em uma das filas.
        */
        void add_client_less_products_queue(Client* client);

        /*!
        *   Define tempo de chegada do proximo cliente.
        */
        void increase_time_next_client() {
            time_of_next_client->add_seconds(average_time_of_arrival_of_clients_->get_time_in_seconds());
        }

        /*!
        *   Simula a passagem por um caixa, retirando clientes que tenham tempo de saida igual ao atual.
        */
        void simulate_box();

        /*!
        *   Adiciona cliente.
        */
        void add_client(Client* client);

        /*!
        *   Define que cliente na compareceu.
        */
        void set_dropped_client(Client* client);

        /*!
        *   Retorna o tipo de fila que o cliente tem preferencia.
        */
        int get_queue_type();

        /*!
        *   Retorna o metodo de pagamento com 80% de chances de ser cartao.
        */
        int get_pay_type();

        /*!
        *   Retorna o valor total das compras.
        */
        int get_total_purchases_value(int total_purchases);

        /*!
        *   Retorna o numero de produtos comprados.
        */
        int get_total_purchases();

        CircularList* box_list;                                     /*!< Fila com caixas do mercado. */
        Clock* clock;                                               /*!< Relogio do mercado. */
        unsigned int clients_dropped_out;                           /*!< Numero de clientes q deixaram de comprar. */
        unsigned int max_clients_in_queue_;                         /*!< Maximo de clientes nas filas. */
        double billing_lost;                                        /*!< Faturamento perdido. */
        std::string market_name_;                                   /*!< Nome do mercado. */
        Time* time_of_simulation_;                                  /*!< Tempo de simulacao. */
        Time* average_time_of_arrival_of_clients_;                  /*!< Tempo de chegada de um novo cliente. */
        Time* time_of_next_client;                                  /*!< Tempo no qual o proximo cliente chegara. */
        bool reserve_box;                                           /*!< Se caixa reserva esta disponivel. */

        Performance* bad_box_perform = new Performance(60u, 4);     /*!< Performance ruim para caixas. */
        Performance* medium_box_perform = new Performance(25u, 2);  /*!< Performance media para caixas. */
        Performance* good_box_perform = new Performance(10u, 1);    /*!< Performance boa para caixas. */

};

#endif // MARKET_H
