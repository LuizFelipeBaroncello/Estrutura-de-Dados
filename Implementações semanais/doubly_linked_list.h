//! Descrição do arquivo
/*!
 *  \author Luiz Baroncello
 *  \since 13/09/2016
 *  \version 1.0
 *  \copyright General Public License version 2
 */
#define STRUCTURES_DOUBLY_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>

//! Classe DoublyLinkedList para uma Lista.
/*! 
*   Na classe DoublyLinkedList, e implementado o funcionamento de uma lista
*   atraves de Nodes que referenciam o proximo valor e o valor anterior na lista e o dado na mesma.
*/
class DoublyLinkedList {
 public:
//! Construtor.
/*!
*   Construtor que inicializa o elemento head que sera usado como cabeça para a lista.
*/
    DoublyLinkedList() {
        head = new Node(0u);
        size_ = 0;
    }

//! Destrutor.
/*!
*   Deleta todos os elementos da lista.
*   \sa clear()
*/    
    ~DoublyLinkedList() {
        clear();
        delete head;
    }

//! Funcao reponsavel por limpar a lista.
/*!
*   Faz com que a lista seja limpa.
*   \sa empty(), pop_front()
*/
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

//! Funcao reponsavel por adicionar um elemento ao final da lista.
/*!
*   Adiciona um elemento ao final da lista.
*   \param data dado a ser adicionado no final da lista. 
*   \sa insert(), size()
*/
    void push_back(const T& data) {
        insert(data, size());
    }

//! Função reponsavel por adicionar um elemento no inicio da lista.
/*!
*   Adiciona um elemento no inicio da lista.
*   \param data dado a ser adicionado no inicio da lista. 
    \sa empty()
*/
    void push_front(const T& data) {
        Node* novo = new Node(data);

        if (novo == NULL) {
            throw std::out_of_range("listaCheia");
        } else {
            if (!empty()) {
                novo->next(head->next());
                novo->next()->prev(novo);
            }
            head->next(novo);
            size_++;
        }
    }

//! Funcao reponsavel por adicionar um elemento em uma posicao da lista.
/*!
*   Adiciona um elemento na posicao solicitada.
*   \param data dado a ser adicionado na lista. 
*   \param index posicao na qual sera adicionado
*   \sa push_front(), size()
*/
    void insert(const T& data, std::size_t index) {
        Node *novo;
        Node *anterior;

        if (index > size() || index < 0) {
            throw std::out_of_range("posicaoInvalida");
        } else {
            if (index == 0) {
                push_front(data);
            } else {
                novo = new Node(data);
                if (novo == NULL) {
                    throw std::out_of_range("listaCheia");
                } else {
                    anterior = head->next();
                    for (int i = 0; i < index -1; i++) {
                        anterior = anterior->next();
                    }
                    if (index != size()) {
                        novo->next(anterior->next());
                        novo->next()->prev(novo);
                    }
                    novo->prev(anterior);
                    anterior->next(novo);
                    size_++;
                }
            }
        }
    }

//! Funcao reponsavel por adicionar um elemento em ordem na lista.
/*!
*   Adiciona um elemento em ordem na lista.
*   \param data dado a ser adicionado na lista. 
*   \sa insert(), push_front(), empty()
*/
    void insert_sorted(const T& data) {
        Node *atual;
        int posicao;

        if (empty()) {
            push_front(data);
        } else {
          atual = head->next();
          posicao = 0;
          while (atual->next() != NULL  && data > atual->data() &&
                posicao < size()-1) {
              atual = atual->next();
              posicao++;
          }
            if (data > atual->data())
                insert(data, posicao+1);
            else
                insert(data, posicao);
        }
    }

//! Funcao reponsavel por retornar e retirar um elemento de uma posicao.
/*!
*   Retira um elemento da posicao que lhe foi solicitada e o retorna.
*   \param index posicao na qual o elemento se encontra.
*   \return o dado retirado.
*   \sa pop_front(), size()
*/
    T pop(std::size_t index) {
        Node* anterior;
        Node* eliminar;
        T volta;

        if (index > size()-1 || index < 0) {
            throw std::out_of_range("posicaoInvalida");
        } else {
            if (index == 0) {
                return pop_front();
            } else {
                anterior = head->next();
                for (int i = 0; i < index -1; i++) {
                    anterior = anterior->next();
                }
                eliminar = anterior->next();
                volta = eliminar->data();
                if (index+1 != size())
                    anterior->next(eliminar->next());
                if (eliminar->next() != NULL) {
                    eliminar->next()->prev(anterior);
                }
                size_--;
                delete(eliminar);
                return volta;
            }
        }
    }

//! Funcao reponsavel por retornar e retirar o ultimo elemento da lista.
/*!
*   Retira o ultimo elemento da lista.
*   \return o dado encontrado na ultima posicao da lista.
*   \sa pop(), size(), empty()
*/
    T pop_back() {
        if (empty())
            throw std::out_of_range("listaVazia");
        else
            return pop(size()-1);
    }

//! Funcao reponsavel por retornar e retirar o primeiro elemento da lista.
/*!
*   Retira o primeiro elemento da lista.
*   \return o dado encontrado na primeira posicao da lista.
*   \sa empty(), size()
*/
    T pop_front() {
        Node *saiu;
        T volta;

        if (empty()) {
            throw std::out_of_range("listaVazia");
        } else {
            saiu = head->next();
            volta = saiu->data();
            if (size() != 1)
                head->next(saiu->next());
            size_--;
            delete saiu;

            return volta;
        }
    }

//! Função reponsável por remover um dado da lista.
/*!
*   Remove um dado da lista.
*   \param data dado a ser removido.
*   \sa empty(), contains(), pop(), find()
*/
    void remove(T data) {
        if (empty()) {
            throw std::out_of_range("listaVazia");
        } else {
            if (contains(data)) {
                pop(find(data));
            } else {
                throw std::out_of_range("dataNotFound");
            }
        }
    }

//! Funcao responsavel por verificar se a lista esta vazia.
/*!
*   Retorna true se a lista estiver vazia.
*   \return uma variavel booleana.
*/
    bool empty() const {
        return size_ == 0;
    }

//! Funcao responsavel por verificar se um elemento existe no vetor.
/*!
*   Retorna true se o elemento realmente se encontra no vetor.
*   \param data elemento a ser procurado na lista.
*   \return uma variavel booleana.
*   \sa size()
*/   
    bool contains(const T& data) const {
        auto *dado = head;

        for (int i = 0; i < size(); i++) {
            dado = dado->next();
            if (data == dado->data()) {
                return true;
            }
        }
        return false;
    }

//! Funcao responsavel por devolver o elemento na posicao index.
/*!
*   Devolve o elemento na posicao solicitada, e caso a mesma nao esteja correta lanca uma excecao. 
*   \param index posicao a qual sera usada para retornar o elemento.
*   \return o elemento correspondente a posicao.
*   \sa empty(), size()
*/
    T& at(std::size_t index) {
        Node *dado = head->next();

        if (empty()) {
            throw std::out_of_range("listaVazia");
        } else {
            if (index > size() || index < 0) {
                throw std::out_of_range("posicaoInvalida");
            } else {
                for (int i = 0; i < index; i++) {
                    dado = dado->next();
                }
                return dado->data();
            }
        }
    }

//! Funcao responsavel por devolver o elemento na posicao index.
/*!
*   Devolve o elemento na posicao solicitada, e caso a mesma nao esteja correta lanca uma excecao. 
*   \param index posicao a qual sera usada para retornar o elemento.
*   \return o elemento correspondente a posicao.
*   \sa empty(), size()
*/    
    const T& at(std::size_t index) const {
        Node *dado = head->next();
        if (empty()) {
            throw std::out_of_range("listaVazia");
        } else {
            if (index > size() || index < 0) {
                throw std::out_of_range("posicaoInvalida");
            } else {
                for (int i = 0; i < index; i++) {
                    dado = dado->next();
                }
                return dado->data();
            }
        }
    }

//! Funcao responsavel por retornar a posicao de um elemento no vetor.
/*!
*   Retorna a posicao atual de um elemento no vetor.
*   \param data elemento o qual se deseja saber a posicao.
*   \return um inteiro.
*   \sa size()
*/    
    std::size_t find(const T& data) const {
        auto *dado = head;

        for (int i = 0; i < size(); i++) {
            dado = dado->next();
            if (data == dado->data())
                return i;
        }
        return size();
    }

//! Funcao responsavel por retornar a posicao de um elemento no vetor.
/*!
*   Retorna a posicao atual de um elemento no vetor.
*   \param data elemento o qual se deseja saber a posicao.
*   \return um inteiro.
*   \sa size()
*/      
    std::size_t size() const {
        return size_;
    }

 private:
//! Classe Node para referenciar dado, proximo e anterior na lista.
/*!
*   Na classe Node sao implementados os metodos basicos para a referencia de um dado T, o próximo Node e o Node anterior.
*/
class Node {
 public:
//! Construtor.
/*!
*   Construtor que referencia o dado a ser guardado atraves de parametro.
*   \param data dado que sera armazenado.
*/
    explicit Node(const T& data):
        data_{data}
    {}

//! Construtor.
/*!
*   Construtor que referencia o dado a ser guardado e o proximo Node.
*   \param data dado que sera armazenado.
*   \param next ponteiro para o proximo Node.
*/
    Node(const T& data, Node* next):
        data_{data},
        next_{next}
    {}

//! Construtor.
/*!
*   Construtor que referencia o dado a ser guardado, o proximo Node e o Node anterior.
*   \param data dado que sera armazenado.
*   \param next ponteiro para o proximo Node.
*   \param prev ponteiro para o Node anterior
*/
    Node(const T& data, Node* prev, Node* next):
        data_{data},
        next_{next},
        prev_{prev}
    {}

/*!
*   Retorna o dado que esta salvo.  
*/
    T& data() {
        return data_;
    }

/*!
*   Retorna o dado que esta salvo.  
*/
    const T& data() const {
        return data_;
    }

/*!
*   Retorna o Node anterior ao atual.  
*/
    Node* prev() {
        return prev_;
    }

/*!
*   Retorna o Node anterior ao atual.  
*/
    const Node* prev() const {
        return prev_;
    }

/*!
*   Recebe um ponteiro indicando qual sera o Node anterior.
*   \param node.
*/
    void prev(Node* node) {
        prev_ = node;
    }

/*!
*   Retorna o proximo Node.  
*/
    Node* next() {
        return next_;
    }

/*!
*   Retorna o proximo Node.  
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
        T data_;         /*!< Dado contido. */
        Node* prev_;     /*!< Node anterior. */
        Node* next_;     /*!< Proximo Node. */
};

    Node* head;         /*!< Referencia para primeiro elemento na lista. */
    std::size_t size_;  /*!< Tamanho da lista. */
};

}  // namespace structures
