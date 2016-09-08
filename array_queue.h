#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ Exceptions

namespace structures {

template<typename T>

//! Classe ArrayQueue para uma Lista.
/*! 
*   Na classe ArrayQueue, � implementado o funcionamento de uma fila
*   atrav�s de um vetor.
*/

class ArrayQueue {
public:

//! Construtor sem parametros.
/*!
*   Construtor que inicializa a fila com um valor pr�-definido.
*/
    ArrayQueue(){
        max_size_ = DEFAULT_SIZE;
        size_ = -1;
        contents = new T[DEFAULT_SIZE];
    }

//! Construtor com parametros.
/*!
*   Construtor que recebe o tamanho m�ximo da fila.
*   \param max uma vari�vel que determina o tamanho da fila.
*/
    ArrayQueue(std::size_t max){
        max_size_ = max;
        size_ = -1;
        contents = new T[max];
    }

//! Destrutor.
/*!
*   Deleta o vetor que cont�m a lista.
*/
    ~ArrayQueue(){
        delete[] contents;
    }

//! Fun��o repons�vel por enfileirar.
/*!
*   Enfileira um dado.
*   \param data refer�ncia de uma constante do dado que ser� adicionado � fila.
*   \sa full()
*/
    void enqueue(const T& data){
        if(full())
            throw std::out_of_range("listaCheia");
        else{
            size_++;
            contents[size_] = data;
        }
    }

//! Fun��o repons�vel por desenfileirar.
/*!
*   Desenfileira um dado.
*   \sa empty()
*   \return um dado.
*/
    T dequeue(){
        if(empty())
            throw std::out_of_range("listaVazia");
        else{
            size_--;
            T firstElement = contents[0];
            for(int i = 0; i < size_+1; i++){
                contents[i] = contents[i+1];
            }
            return firstElement;
        }
    }
    
//! Fun��o repons�vel por devolver o final da fila.
/*!
*   Devolve o final da fila.
*   \return um dado.
*   \sa empty()
*/
    T& back(){
        if(empty())
            throw std::out_of_range("listaVazia");
        else
            return contents[size_];
    }

//! Fun��o repons�vel por limpar a fila.
/*!
*   Faz com que a fila seja limpa.
*/
    void clear(){
        size_ = -1;
    }

//! Fun��o repons�vel por retornar a quantidade de dados.
/*!
*   Retorna a quantidade de dados que se encontram na fila.
*   \return um valor.
*/
    std::size_t size(){
        return size_+1;
    }

//! Fun��o repons�vel por retornar o tamanho m�ximo da fila.
/*!
*   Retorna o tamanho m�ximo da fila.
*   \return um valor.
*/
    std::size_t max_size(){
        return max_size_;
    }

//! Fun��o respons�vel por verificar se a fila est� vazia.
/*!
*   Retorna true se a fila estiver vazia.
*   \return uma vari�vel booleana.
*/
    bool empty(){
        return size_ == -1;
    } 

//! Fun��o respons�vel por verificar se a fila est� cheia.
/*!
*   Retorna true se a fila estiver cheia.
*   \return uma vari�vel booleana.
*/
    bool full(){
        return size_ == (max_size_ - 1);
    } 

private:
    
    T* contents;            /*!< Vetor no qual a fila � implementada. */
    std::size_t size_;      /*!< Valor que indica o final da fila. */
    std::size_t max_size_;  /*!< � o m�ximo de elementos que se pode enfileirar. */       

    const static auto DEFAULT_SIZE = 10u;
};

}

#endif
