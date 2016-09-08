#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>
#include <stdexcept> 

namespace structures {

template<typename T>

//! Classe ArrayStack para uma Pilha.
/*! 
*   Na classe ArrayStack, � implementado o funcionamento de uma pilha
*   atrav�s de um vetor.
*/

class ArrayStack {  
public:

//! Construtor sem parametros.
/*!
*   Construtor que inicializa a pilha com um valor pr�-definido.
*/
    ArrayStack(){
        max_size_ = DEFAULT_SIZE;
        contents = new T[DEFAULT_SIZE];
        top_ = -1;
    }

//! Construtor com parametros.
/*!
*   Construtor que recebe o tamanho m�ximo da pilha.
*   \param max uma vari�vel que determina o tamanho da pilha.
*/
    ArrayStack(std::size_t max){
        max_size_ = max;
        contents = new T[max];
        top_ = -1;
    }

//! Destrutor.
/*!
*   Deleta o vetor que cont�m a pilha.
*/
    ~ArrayStack(){
        delete[] contents;
    }

//! Fun��o repons�vel por empilhar.
/*!
*   Empilha um dado.
*   \param data refer�ncia de uma constante do dado que ser� adicionado � pilha.
*   \sa full()
*/
    void push(const T& data){
        if(full())
            throw std::out_of_range("pilhaCheia");
        else{
            top_++;
            contents[top_] = data;
        }
    } 

//! Fun��o repons�vel por desempilhar.
/*!
*   Desempilha um dado.
*   \sa empty()
*   \return um dado.
*/
    T pop(){
        if(empty())
            throw std::out_of_range("pilhaVazia");
        else{
            top_--;
            return contents[top_+1];
        }
    }

//! Fun��o repons�vel por devolver o topo.
/*!
*   Devolve o topo da pilha
*   \return um dado.
*   \sa empty()
*/
    T& top(){
        if(empty())
            throw std::out_of_range("pilhaVazia");
        else
            return contents[top_];
    }

//! Fun��o repons�vel por limpar a pilha.
/*!
*   Faz com que a pilha seja limpa.
*/
    void clear(){
        top_ = -1;
    }

//! Fun��o repons�vel por retornar a quantidade de dados.
/*!
*   Retorna a quantidade de dados que se encontram na pilha.
*   \return um valor.
*/
    std::size_t size(){
        return top_+1;
    }

//! Fun��o repons�vel por retornar o tamanho m�ximo da pilha.
/*!
*   Retorna o tamanho m�ximo da pilha.
*   \return um valor.
*/
    std::size_t max_size(){
        return max_size_;
    }

//! Fun��o respons�vel por verificar se a pilha est� vazia.
/*!
*   Retorna true se a pilha estiver vazia.
*   \return uma vari�vel booleana.
*/
    bool empty(){
        return top_ == -1;
    } 

//! Fun��o respons�vel por verificar se a pilha est� cheia.
/*!
*   Retorna true se a pilha estiver cheia.
*   \return uma vari�vel booleana.
*/
    bool full(){
        return top_ == (max_size_ - 1);
    } 

private:
    T* contents;            /*!< Vetor no qual a pilha � implementada. */
    int top_;               /*!< Inteiro que indica o topo da pilha. */
    std::size_t max_size_;  /*!< � o m�ximo de elementos que se pode empilhar. */

    const static auto DEFAULT_SIZE = 10u;
};

}

#endif
