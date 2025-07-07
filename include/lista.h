#ifndef LISTA_H
#define LISTA_H

#include <vector>
#include <stdexcept>

/**
 * @brief Classe simples de lista para demonstrar testes
 */
template<typename T>
class Lista {
private:
    std::vector<T> dados;

public:
    /**
     * @brief Adiciona um elemento ao final da lista
     */
    void adicionar(const T& elemento);
    
    /**
     * @brief Remove um elemento de uma posição específica
     */
    void remover(size_t posicao);
    
    /**
     * @brief Obtém um elemento em uma posição específica
     */
    T obter(size_t posicao) const;
    
    /**
     * @brief Retorna o tamanho da lista
     */
    size_t tamanho() const;
    
    /**
     * @brief Verifica se a lista está vazia
     */
    bool vazia() const;
    
    /**
     * @brief Limpa todos os elementos da lista
     */
    void limpar();
};

// Implementação dos métodos template
template<typename T>
void Lista<T>::adicionar(const T& elemento) {
    dados.push_back(elemento);
}

template<typename T>
void Lista<T>::remover(size_t posicao) {
    if (posicao >= dados.size()) {
        throw std::out_of_range("Posição inválida");
    }
    dados.erase(dados.begin() + posicao);
}

template<typename T>
T Lista<T>::obter(size_t posicao) const {
    if (posicao >= dados.size()) {
        throw std::out_of_range("Posição inválida");
    }
    return dados[posicao];
}

template<typename T>
size_t Lista<T>::tamanho() const {
    return dados.size();
}

template<typename T>
bool Lista<T>::vazia() const {
    return dados.empty();
}

template<typename T>
void Lista<T>::limpar() {
    dados.clear();
}

#endif // LISTA_H
