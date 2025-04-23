#pragma once
#include <stdint.h>

#include <stdexcept>

/**
 * @brief Classe template para implementação de uma Pilha (estrutura LIFO).
 *
 * @tparam T Tipo de dado armazenado na pilha.
 */
template <class T>
class Pilha {
 public:
  /**
   * @brief Construtor da pilha com capacidade personalizada.
   *
   * Inicializa a pilha com a capacidade especificada pelo usuário.
   *
   * @param capacidade A capacidade máxima da pilha.
   */
  Pilha(size_t capacidade);

  /**
   * @brief Destrutor da pilha.
   *
   * Libera os recursos alocados dinamicamente.
   */
  ~Pilha();

  /**
   * @brief Insere um novo elemento no topo da pilha.
   *
   * @param valor Valor a ser empilhado.
   * @throws std::runtime_error Se a pilha estiver cheia.
   */
  void empilhar(const T& valor);

  /**
   * @brief Remove e retorna o elemento do topo da pilha.
   *
   * @return Elemento removido do topo.
   * @throws std::runtime_error Se a pilha estiver vazia.
   */
  T desempilhar();

  /**
   * @brief Acessa o elemento do topo da pilha.
   *
   * @return Referência ao elemento no topo.
   * @throws std::runtime_error Se a pilha estiver vazia.
   */
  T& topo();

  /**
   * @brief Acessa o elemento do topo da pilha (versão constante).
   *
   * @return Referência constante ao elemento no topo.
   * @throws std::runtime_error Se a pilha estiver vazia.
   */
  const T& topo() const;

  /**
   * @brief Verifica se a pilha está vazia.
   *
   * @return true Se a pilha estiver vazia.
   * @return false Caso contrário.
   */
  bool esta_vazia() const;

  /**
   * @brief Verifica se a pilha está cheia.
   *
   * @return true Se a pilha estiver cheia.
   * @return false Caso contrário.
   */
  bool esta_cheia() const;

  const size_t capacidade; /**< Capacidade máxima da pilha. */
 private:
  size_t tamanho; /**< Número atual de elementos na pilha. */
  T* dados;       /**< Ponteiro para o array de elementos. */

 public:
  // Necessário apenas para os testes automatizados.
  // ---
  Pilha(const Pilha&) = delete;
  Pilha& operator=(const Pilha&) = delete;
  // ---
};

template <class T>
Pilha<T>::Pilha(size_t capacidade) {

  cout<<"Qual será a capacidade maxima da pilha";
  cin>>capacidade;
  stack<capacidade>pilha;
  stack<char>pilha;//inicializa a pilha 


}

template <class T>
Pilha<T>::~Pilha() {

}

template <class T>
void Pilha<T>::empilhar(const T& valor) {
  pilha.push();
}

template <class T>
T Pilha<T>::desempilhar() {
  cout<<"O elemento do topo da lista é "<<pila.front()<<endl;
  pilha.pop();
}

template <class T>
T& Pilha<T>::topo() {
    pilha.top();
    cout<<" o valor que está na frente é "<<pilha.front()<<endl;
}

template <class T>
const T& Pilha<T>::topo() const {
  if (pilha.empty()){
    return true;
  }else{
    return false;
  }
}

template <class T>
bool Pilha<T>::esta_vazia() const {
 return pila.empty();
}

template <class T>
bool Pilha<T>::esta_cheia() const {
  return pilha.size() >= capacidade;
}