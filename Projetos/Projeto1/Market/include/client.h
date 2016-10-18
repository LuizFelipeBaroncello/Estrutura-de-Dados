/*!
 *  \author Luiz Felipe Ribeiro Baroncello
 *  \author Lukas Derner Grüdtner
 *  \version 1.0
 *  \copyright General Public License version 2
 *
 */

#ifndef CLIENT_H
#define CLIENT_H

#include "time_p.h"

//! Classe Client para clientes.
class Client
{
    public:

        /*!
        *   Construtor.
        */
        Client();

        /*!
        *   Construtor.
        *   \param tempo de chegada.
        *   \param tempo de saida.
        */
        Client(Time& arrival_time, int total_purchases, int total_purchases_value, int pay_type, int queue_type);

        /*!
        *   Destrutor.
        */
        virtual ~Client();

        /*!
        *   Define o tempo que o usuario deixara o mercado.
        */
        void set_exit_time(Time& arrival_time);

        /*!
        *   \return tempo de chegada na fila.
        */
        const Time get_arrival_time();

        /*!
        *   \return tempo de saida na fila.
        */
        const Time get_exit_time();

        /*!
        *   \return tempo que o cliente passou/vai passar na fila.
        */
        const Time get_average_time();

        /*!
        *   \return tipo de pagamento.
        */
        int get_pay_type();

        /*!
        *   \return tipo de fila.
        */
        int get_queue_type();

        /*!
        *   \return total de compras.
        */
        unsigned int get_total_purchases();

        /*!
        *   \return valor total.
        */
        long int get_total_value();

    private:

        int pay_type_;              /*!< Tipo de pagamento do cliente. 0 = Cartao*/
        int queue_type_;          /*!< Tipo de fila que o cliente tem preferencia. 0 = Menos pessoas */
        int total_purchases_;  /*!< Numero de produtos. */
        int total_purchases_value_;  /*!< Valor de todos os produtos. */
        Time arrival_time_;            /*!< Tempo no qual o cliente entrou na fila. */
        Time exit_time_;               /*!< Tempo no qual o cliente saira da fila. */

};

#endif // CLIENT_H
