#ifndef LISTA_DUPLAMENTE_ENCADEADA_HPP
#define LISTA_DUPLAMENTE_ENCADEADA_HPP

#include <iostream>
using namespace std;

template <typename T>
struct NoDuplo {
    T dado;
    NoDuplo<T>* prox;
    NoDuplo<T>* ant;
};

template <typename T>
struct ListaDuplamenteEncadeada {
    NoDuplo<T>* inicio;
    NoDuplo<T>* fim;
    int tamanho;
};

template <typename T>
int tamanho(ListaDuplamenteEncadeada<T> &lista) {
    int cont = 0;
    NoDuplo<T>* atual = lista.inicio;
    while (atual != nullptr) {
        cont++;
        atual = atual->prox;
    }
    return cont;
}

template <typename T>
void inicializar(ListaDuplamenteEncadeada<T>& lista) {
    lista.inicio = nullptr;
    lista.fim = nullptr;
    lista.tamanho = 0;
}

template <typename T>
bool inserirFinal(ListaDuplamenteEncadeada<T>& lista, T valor) {
    NoDuplo<T>* novo = new NoDuplo<T>{valor, nullptr, lista.fim};
    if (lista.fim != nullptr)
        lista.fim->prox = novo;
    else
        lista.inicio = novo;
    lista.fim = novo;
    lista.tamanho++;
    return true;
}

template <typename T>
bool removerInicio(ListaDuplamenteEncadeada<T>& lista) {
    if (lista.inicio == nullptr) return false;
    NoDuplo<T>* temp = lista.inicio;
    lista.inicio = lista.inicio->prox;
    if (lista.inicio != nullptr)
        lista.inicio->ant = nullptr;
    else
        lista.fim = nullptr;
    delete temp;
    lista.tamanho--;
    return true;
} 

template <typename T>
bool removerFinal(ListaDuplamenteEncadeada<T>& lista) {
    if (lista.fim == nullptr) return false;
    NoDuplo<T>* temp = lista.fim;
    lista.fim = lista.fim->ant;
    if (lista.fim != nullptr)
        lista.fim->prox = nullptr;
    else
        lista.inicio = nullptr;
    delete temp;
    lista.tamanho--;
    return true;
} 

template <typename T>
bool removerNaPosicao(ListaDuplamenteEncadeada<T>& lista, int pos) {
    if (pos < 0 || pos >= lista.tamanho) return false;
    if (pos == 0) return removerInicio(lista);
    if (pos == lista.tamanho - 1) return removerFinal(lista);
    NoDuplo<T>* atual = lista.inicio;
    for (int i = 0; i < pos; i++)
        atual = atual->prox;
    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;
    delete atual;
    lista.tamanho--;
    return true;
}

template <typename T>
bool obterItemNaPosicao(ListaDuplamenteEncadeada<T> lista, int pos, T& valor) {
    if (pos < 0 || pos >= lista.tamanho) return false;
    NoDuplo<T>* atual = lista.inicio;
    for (int i = 0; i < pos; i++)
        atual = atual->prox;
    valor = atual->dado;
    return true;
}

template <typename T>
int descobrirIndice(ListaDuplamenteEncadeada<T> lista, T valor) {
    NoDuplo<T>* atual = lista.inicio;
    int indice = 0;
    while (atual != nullptr) {
        if (atual->dado == valor) return indice;
        atual = atual->prox;
        indice++;
    }
    return -1;
}

template <typename T>
void mostrarLista(ListaDuplamenteEncadeada<T> lista) {
    NoDuplo<T>* atual = lista.inicio;
    while (atual != nullptr) {
        cout << atual->dado << " ";
        atual = atual->prox;
    }
    cout << endl;
}

template <typename T>
bool vazia(ListaDuplamenteEncadeada<T> lista) {
    return lista.inicio == nullptr;
}

#endif