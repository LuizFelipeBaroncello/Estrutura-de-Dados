#ifndef TESTLUIZ_H
#define TESTLUIZ_H

#include <iostream>
#include <string>

#include "performance.h"
#include "clock.h"
#include "circular_list.h"
#include "market_box.h"
#include "client.h"
#include "linked_queue.h"

using namespace std;

class TestLuiz
{
    public:
        TestLuiz(){

            cout << "============Test1=============   Teste Performance" << endl;

            Performance* performance = new Performance(60u, 4);

            cout << "Tempo cartao: 60 = " << performance->get_time_to_spend_card() << endl;
            cout << "Tempo item: 4 = " << performance->get_time_to_spend_item() << endl;

            delete performance;

            cout << "\n============Test2=============   Teste Clock/Time" << endl;

            Clock* clock = new Clock();

            cout << "Tempo inicial: 0 = " << clock->get_time()->get_time_in_seconds() << endl;

            clock->set_one_more_second();

            cout << "Tempo dps de um segundo: 1 = " << clock->get_time()->get_time_in_seconds() << endl;

            clock->set_one_more_second();

            cout << "Tempo dps de dois segundos: 2 = " << clock->get_time()->get_time_in_seconds() << endl;

            clock->add_seconds(8u);

            cout << "Tempo dps de 10 segundos: 10 = " << clock->get_time()->get_time_in_seconds() << endl;

            clock->add_seconds(50u);

            cout << "Tempo dps de 1 minuto em minutos: 1 = " << clock->get_time()->get_time_in_minutes() << endl;

            clock->add_seconds(59u*60u);

            cout << "Tempo dps de 1 hora em horas: 1 = " << clock->get_time()->get_time_in_hours() << endl;
            cout << "Tempo dps de 1 hora em minutos: 60 = " << clock->get_time()->get_time_in_minutes() << endl;

            delete clock;

            cout << "\n============Test3=============   Teste Circular List" << endl;

            CircularList* circular = new CircularList();

            cout << "instanciou circular" << endl;

            MarketBox* marketBox = new MarketBox();

            cout << "Tamanho com nenhum elemento: 0 = " << circular->size() << endl;
            cout << "Vazio: true = " << circular->empty() << endl;


            circular->push_front(marketBox);

            cout << "Tamanho com um elemento: 1 = " << circular->size() << endl;
            cout << "Vazio: false = " << circular->empty() << endl;

            circular->pop_front();

            cout << "Tamanho com um elemento: 0 = " << circular->size() << endl;
            cout << "Vazio: true = " << circular->empty() << endl;

            delete circular;
            delete marketBox;

            cout << "\n============Test4=============   Teste Cliente" << endl;

            Time* tempoChegada = new Time(10u);
            Time* tempoSaida = new Time(17u);

            Client* cliente = new Client(tempoChegada);

            cliente->set_exit_time(tempoSaida);
            cout << "instanciou cliente" << endl;

            cout << "Tempo chegada: 10 = " << cliente->get_arrival_time()->get_time_in_seconds() << endl;
            cout << "Tempo saida: 17 = " << cliente->get_exit_time()->get_time_in_seconds() << endl;
            cout << "Tempo que ficou na fila: 7 = " << cliente->get_average_time()->get_time_in_seconds() << endl;

            string tipoPagamento("");

            if (cliente->get_pay_type() == PayType::card) {
                tipoPagamento = "cartão";
            } else {
                tipoPagamento = "Dinheiro";
            }

            cout << "Tipo de pagamento: random = " << tipoPagamento << endl;

            string tipoFila("");

            if (cliente->get_queue_type() == QueueType::less_size) {
                tipoFila = "menorTamanho";
            } else {
                tipoFila = "menosProdutos";
            }

            cout << "Tipo de fila: random = " << tipoFila << endl;

            cout << "Numero de compras: random = " << cliente->get_total_purchases() << endl;

            cout << "Valor total: random = " << cliente->get_total_value() << endl;

            delete tempoSaida;

            cout << "\n============Test5=============   Teste numero Produtos na fila" << endl;

            LinkedQueue* lqueue = new LinkedQueue();
            lqueue->enqueue(cliente);

            cout << "Numero de produtos na fila: " << cliente->get_total_purchases() << " = " << lqueue->num_products() << endl;
            lqueue->enqueue(cliente);

            cout << "Numero de produtos na fila: " << cliente->get_total_purchases()*2 << " = " << lqueue->num_products() << endl;
            lqueue->dequeue();

            cout << "Numero de produtos na fila: " << cliente->get_total_purchases() << " = " << lqueue->num_products() << endl;

            delete lqueue;

            cout << "\n============Test6=============   Teste MarketBox" << endl;

            Performance* ruim = new Performance(60u, 4);
            Performance* medio = new Performance(25u, 2);
            Performance* bom = new Performance(10u, 1);

            MarketBox* caixaRuim = new MarketBox("JoaoR", ruim, 800);
            MarketBox* caixaMedio = new MarketBox("PedroM", medio, 1000);
            MarketBox* caixaBom = new MarketBox("VitorB", bom, 1200);

            cout << "Tres caixas instanciados, sendo eles " << caixaRuim->get_identifier() << ", " << caixaMedio->get_identifier() << " e " << caixaBom->get_identifier() << "." << endl;

            cout << "Um cliente instanciado e colocado em diferentes filas." << endl;

            cout << "Na fila ''ruim'':" << endl;
            caixaRuim->add_client(cliente);
            cout << "Tempo de saida na fila ruim : = " << cliente->get_exit_time()->get_time_in_seconds() << endl;

            cout << "Na fila ''media'':" << endl;
            caixaMedio->add_client(cliente);

            cout << "Tempo de saida na fila media: = " << cliente->get_exit_time()->get_time_in_seconds() << endl;

            cout << "Na fila ''boa'':" << endl;
            caixaBom->add_client(cliente);

            cout << "Tempo de saida na fila boa  : = " << cliente->get_exit_time()->get_time_in_seconds() << endl;

            cout << "Num clientes na fila boa: 1 = " << caixaBom->get_num_of_clients_in_queue() << endl;

            caixaBom->add_client(cliente);

            cout << "Tempo de saida com duas pessoas fila boa : " << cliente->get_exit_time()->get_time_in_seconds() << endl;

            cout << "Tempo de espera desse segundo cliente na fila boa: " << cliente->get_average_time()->get_time_in_seconds() << endl;

            cout << "Num clientes na fila boa: 2 = " << caixaBom->get_num_of_clients_in_queue() << endl;

            caixaBom->remove_client();

            cout << "Num clientes na fila boa: 1 = " << caixaBom->get_num_of_clients_in_queue() << endl;
            cout << "Num clientes atendidos: 1 = " << caixaBom->get_num_of_clients_served() << endl;

            cout << "Tempo total de espera (igual ao tempo de espera do segundo cliente) : " << caixaBom->get_average_service_time()->get_time_in_seconds() << endl;

            cout << "faturamento total : " << caixaBom->get_total_billing() << endl;
            cout << "Lucro total : " << caixaBom->get_profit() << endl;

            cout << "Numero de produtos na fila: " << caixaBom->get_num_of_products_in_queue() << endl;
            cout << "Tempo medio de espera na fila: " << caixaBom->get_average_service_time()->get_time_in_seconds() << endl;
            cout << "Tempo para saida do proximo cliente: " << caixaBom->get_exit_time_of_first_client()->get_time_in_seconds() << endl;

            cout << "OBS: Tudo ok soh cuidar na hora de dar os deletes" << endl;

            delete caixaBom;
            delete ruim;
            delete medio;
            delete bom;
            delete cliente;
            delete caixaMedio;
            delete caixaRuim;
            delete tempoChegada;





        }
    private:
};

#endif // TESTLUIZ_H
