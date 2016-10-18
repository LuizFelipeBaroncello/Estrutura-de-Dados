/*!
 *  \author Luiz Felipe Ribeiro Baroncello
 *  \author Lukas Derner Gr�dtner
 *  \version 1.0
 *  \copyright General Public License version 2
 *
 */

#ifndef CONTROL_H
#define CONTROL_H

#include <string>
#include <fstream>
#include <sstream>

#include "market.h"

using namespace std;

namespace control {

//! Classe Control
/*!
 *  Na classe Controle e implementado os metodos para abrir, ler e fechar o
 *  arquivo. Assim como motodos para inicializacao do Mercado com seus atributos
 *  e a inicializacao dos Caixas.
 */

class Control
{
    public:
        /*!
         *  Construtor.
         */
        Control();

        /*!
        *   Destrutor.
        */
        ~Control();

        /*!
         * Imprime os dados da simulacao.
         */
        void print_data();



    private:
        /*!
         * Define o tipo de entrada dos parametros para simulação: manual ou por
         * meio de um arquivo.dat.
         */
        void type_of_entry();

        /*!
         *  Abre arquivo
         *  \param ifstream& file.dat para ser aberto.
         */
        void open_file(std::ifstream &);

        /*!
         *  Le arquivo.
         *  \param ifstream& file.dat para ser lido e carregado.
         */
        void read_file(std::ifstream &);

        /*!
         *  Fecha arquivo.
         *  \param ifstrem& file.dat para ser fechado.
         */
        void close_file(std::ifstream &);

        /*!
         *  Verifica se a linha e comentario.
         * \param ifstream& file.dat para verificar se a linha e um comentario.
         */
        bool read_comment(std::ifstream &);

        /*!
         *  Insere os valores do vetor para os atributos do Mercado.
         *  \param buffer[] vetor do tipo string.
         */
        void insert(std::string buffer[]);

        /*!
         * Retorna uma string com o nome do mercado.
         */
        std::string get_market_name();

        /*!
         * Retorna um inteiro com o tempo da simulacao em horas.
         */
        unsigned int get_time_of_simulation_in_hours();

        /*!
         * Retorna um inteiro com o tempo medio da chegada dos clientes.
         */
        unsigned int get_average_arrival_time_of_customers_in_seconds();

        /*!
         * Retorna um inteiro com o numero de caixas.
         */
        unsigned int get_number_of_market_box();

        ifstream file;  /*!< Arquivo. */
        std::string line;   /*!< Linha, uma vari�vel do tipo string. */
        std::string market_name;    /*!< Nome do mercado, do tipo string. */
        unsigned int time_of_simulation;   /*!< Tempo de simula��o. */
        unsigned int average_arrival_time_of_customers;  /*!< Tempo m�dio de chegada de clientes. */
        unsigned int number_of_market_box;  /*!< N�mero de caixas do mercado. */
        Market* market; /*!< Ponteiro para a inst�ncia do Mercado. */
};

}

#endif
