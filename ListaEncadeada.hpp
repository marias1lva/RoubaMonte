#ifndef LISTA_ENCADEADA_HPP
#define LISTA_ENCADEADA_HPP

#include <iostream>
using namespace std;

// estrutura do nó
template <typename T>
struct No {
    T dado;
    No<T>* prox;
};

// estrutura da lista encadeada
template <typename T>
struct ListaEncadeada {
    No<T>* inicio;
    int tamanho;
};

template <typename T>
int tamanho(ListaEncadeada<T> &lista) {
    int cont = 0;
    No<T>* atual = lista.inicio;
    while (atual != nullptr) {
        cont++;
        atual = atual->prox;
    }
    return cont;
}

// inicializa a lista
template <typename T>
void inicializar(ListaEncadeada<T>& lista) {
    lista.inicio = nullptr;
    lista.tamanho = 0;
}

// insere no início
template <typename T>
bool inserirInicio(ListaEncadeada<T>& lista, T valor) {
    No<T>* novo = new No<T>{valor, lista.inicio};
    lista.inicio = novo;
    lista.tamanho++;
    return true;
}

// insere na posição desejada
template <typename T>
bool inserirNaPosicao(ListaEncadeada<T>& lista, T valor, int pos) {
    if (pos < 0 || pos > lista.tamanho) return false;
    if (pos == 0) return inserirInicio(lista, valor);
    No<T>* atual = lista.inicio;
    for (int i = 0; i < pos - 1; i++) {
        atual = atual->prox;
    }
    No<T>* novo = new No<T>{valor, atual->prox};
    atual->prox = novo;
    lista.tamanho++;
    return true;
}

// insere no final
template <typename T>
bool inserirFinal(ListaEncadeada<T>& lista, T valor) {
    return inserirNaPosicao(lista, valor, lista.tamanho);
}

// remove do início
template <typename T>
bool removerInicio(ListaEncadeada<T>& lista) {
    if (lista.inicio == nullptr) return false;
    No<T>* temp = lista.inicio;
    lista.inicio = lista.inicio->prox;
    delete temp;
    lista.tamanho--;
    return true;
}

// remove de uma posição específica
template <typename T>
bool removerNaPosicao(ListaEncadeada<T>& lista, int pos) {
    if (pos < 0 || pos >= lista.tamanho) return false;
    if (pos == 0) return removerInicio(lista);
    No<T>* atual = lista.inicio;
    for (int i = 0; i < pos - 1; i++) {
        atual = atual->prox;
    }
    No<T>* temp = atual->prox;
    atual->prox = temp->prox;
    delete temp;
    lista.tamanho--;
    return true;
}

// obtém item de uma posição
template <typename T>
bool obterItemNaPosicao(ListaEncadeada<T> lista, int pos, T& valor) {
    if (pos < 0 || pos >= lista.tamanho) return false;
    No<T>* atual = lista.inicio;
    for (int i = 0; i < pos; i++) {
        atual = atual->prox;
    }
    valor = atual->dado;
    return true;
}

// descobre o índice de um item
template <typename T>
int descobrirIndice(ListaEncadeada<T> lista, T valor) {
    No<T>* atual = lista.inicio;
    int indice = 0;
    while (atual != nullptr) {
        if (atual->dado == valor) return indice;
        atual = atual->prox;
        indice++;
    }
    return -1;
}

// mostra todos os elementos da lista
template <typename T>
void mostrarLista(ListaEncadeada<T> lista) {
    No<T>* atual = lista.inicio;
    while (atual != nullptr) {
        cout << atual->dado << " ";
        atual = atual->prox;
    }
    cout << endl;
}

template <typename T>
bool vazia(ListaEncadeada<T> lista) {
    return lista.inicio == nullptr;
}

#endif