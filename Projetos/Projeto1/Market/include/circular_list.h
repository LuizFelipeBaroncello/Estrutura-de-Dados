#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <cstdint>
#include <stdexcept>

#include "market_box.h"

using namespace std;

//! Classe CircularList para uma Lista.
/*!
*   Na classe CircularList, e implementado o funcionamento de uma lista
*   atraves de Nodes que referenciam o proximo valor na lista e o dado na mesma.
*/
class CircularList
{
 public:
        /*!
        *   Construtor.
        */
        CircularList();

        /*!
        *   Destrutor.
        *   \sa clear()
        */
        ~CircularList();

        /*!
        *   Limpa a lista.
        *   \sa empty(), pop_front()
        */
        void clear();

        /*!
        *   Adiciona fila no final.
        *   \param data dado a ser adicionado.
        *   \sa insert()
        */
        void push_back(MarketBox* data);

        /*!
        *  Adiciona fila no começo.
        *   \param data dado a ser adicionado.
        *   \sa empty()
        */
        void push_front(MarketBox* data);

        /*!
        *   Insere dado em uma posicao n.
        *   \param data dado a ser adicionado.
        *   \param index posicao q sera adicionado.
        *   \sa push_front
        */
        void insert(MarketBox* data, std::size_t index);

        /*!
        *   Insere dado de forma ordenada.
        *   \param data dado a ser adicionado
        *   \sa insert(), push_front()
        */
        void insert_sorted(MarketBox* data);

        /*!
        *   Retorna dado.
        *   \param index posicao do dado a ser retornado.
        *   \return dado.
        */
        MarketBox* at(std::size_t index) const;

        /*!
        *   Retira e retorna dado.
        *   \param posicao do dado a ser retirado.
        *   \return dado retirado.
        *   \sa pop_front()
        */
        MarketBox* pop(std::size_t index);

        /*!
        *   Retira e retorna dado do final.
        *   \return dado retirado.
        *   \sa pop()
        */
        MarketBox* pop_back();

        /*!
        *   Retira e retorna dado do inicio.
        *   \return dado retirado.
        */
        MarketBox* pop_front();

        /*!
        *   Retorna true se a lista estiver vazia.
        *   \return uma variavel booleana.
        */
        bool empty() const;

        /*!
        *   Retorna a quantidade de elementos na lista.
        */
        std::size_t size() const;

    private:
//! Classe Node para referenciar dado e proximo elemento na fila.
/*!
*   Na classe Node sao implementados os metodos basicos para a referencia de um dado T e ao proximo Node.
*/
class Node {
 public:
//! Construtor.
/*!
*   Construtor que referencia o dado a ser guardado atraves de parametro.
*   \param data dado que sera armazenado.
*/
        explicit Node(MarketBox* data):
            data_{data}
        {}

//! Construtor.
        Node()
        {}

//! Construtor.
/*!
*   Construtor que referencia o dado a ser guardado e o proximo Node.
*   \param data dado que sera armazenado.
*   \param next ponteiro para o proximo Node.
*/
        Node(MarketBox* data, Node* next):
            data_{data},
            next_{next}
        {}

/*!
*   Retorna o dado que esta salvo.
*   \return um T.
*/
        MarketBox* data() {
            return data_;
        }

/*!
*   Retorna o dado que esta salvo.
*   \return um T.
*/
        MarketBox* data() const {
            return data_;
        }


/*!
*   Retorna o proximo elemento.
*   \return um Node.
*/
        Node* next() {
            return next_;
        }

/*!
*   Retorna o proximo elemento.
*   \return um Node.
*/
        const Node* next() const {
            return next_;
        }

/*!
*   Recebe um ponteiro indicando qual sera o proximo Node.
*   \param node.
*/
        void next(Node* node) {
            next_ = node;
        }

 private:
        MarketBox* data_;        /*!< Dado contido. */
        Node* next_{nullptr};   /*!< Proximo Node. */
};

        Node* head;             /*!< Usado como sentinela. */
        std::size_t size_;      /*!< Tamanho da lista. */
};

#endif // CIRCULAR_LIST_H
