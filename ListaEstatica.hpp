// evita que o conteúdo do arquivo seja incluído mais de uma vez no mesmo programa
#ifndef LISTA_ESTATICA_HPP
#define LISTA_ESTATICA_HPP
#include <iostream>
using namespace std;

// define o tamanho máximo da lista
#ifndef MAX
#define MAX 100
#endif

// define a estrutura da Lista Estática
template <typename T>
struct Lista {
    T vetor[MAX];      // vetor que armazena os elementos da lista
    int ultimo;        // índice do último elemento + 1 (controla o tamanho atual da lista)
    int posicao;       // posição atual para navegação (pode ser útil para iteração)
};

template <typename T>
int tamanho(Lista<T> &lista) {
    return lista.ultimo;
}

// inicializa a lista, zerando o número de elementos e a posição
template <typename T>
void inicializar(Lista<T> &lista) {
    lista.ultimo = 0;
    lista.posicao = -1;
}

// insere um elemento no final da lista
template <typename T>
bool inserirFinal(Lista<T> &lista, T valor) {
    if (lista.ultimo == MAX) return false; // lista cheia
    lista.vetor[lista.ultimo++] = valor; // insere no final e incrementa o contador
    return true;
}

// remove o primeiro elemento da lista
template <typename T>
bool removerInicio(Lista<T> &lista) {
    if (lista.ultimo == 0) return false; // lista vazia
    // desloca os elementos para a esquerda, sobrescrevendo o primeiro
    for (int i = 0; i < lista.ultimo - 1; i++)
        lista.vetor[i] = lista.vetor[i+1];
    lista.ultimo--; // diminui o tamanho da lista
    return true;
}

// remove um elemento de uma posição específica da lista
template <typename T>
bool removerNaPosicao(Lista<T> &lista, int pos) {
    if (lista.ultimo == 0 || pos < 0 || pos >= lista.ultimo) return false; // verificações
    // desloca os elementos seguintes para a esquerda
    for (int i = pos; i < lista.ultimo - 1; i++)
        lista.vetor[i] = lista.vetor[i+1];
    lista.ultimo--; // atualiza tamanho da lista
    return true;
}

// obtém o valor da lista em uma posição específica e armazena na variável 'valor'
template <typename T>
bool obterItemNaPosicao(Lista<T> lista, int pos, T &valor) {
    if (pos < 0 || pos >= lista.ultimo) return false; // posição inválida
    valor = lista.vetor[pos];
    return true;
}

template <typename T>
bool alterarNaPosicao(Lista<T> &lista, int pos, T novoValor) {
    if (pos < 0 || pos >= lista.ultimo) return false; // verificação de limites
    lista.vetor[pos] = novoValor;
    return true;
}

// retorna a posição de um valor na lista, ou -1 se não existir
template <typename T>
int descobrirIndice(Lista<T> lista, T valor) {
    for (int i = 0; i < lista.ultimo; i++) {
        if (lista.vetor[i] == valor) return i;
    }
    return -1;
}

template <typename T>
bool removerCarta(Lista<T> &lista, T &valor) {
    if (lista.ultimo == 0) return false; // lista vazia
    valor = lista.vetor[0];              // pega a carta no topo (ou início)
    return removerInicio(lista);         // remove a primeira carta
}

// exibe todos os elementos da lista no console
template <typename T>
void mostrarLista(Lista<T> lista) {
    for (int i = 0; i < lista.ultimo; i++) {
        cout << lista.vetor[i] << " ";
    }
    cout << endl;
}

template <typename T>
bool vazia(Lista<T> lista) {
    return lista.ultimo == 0;
} 

#endif