#ifndef BARALHO_HPP
#define BARALHO_HPP
#include "Carta.hpp"
#include "ListaEstatica.hpp" 

struct Baralho {
    Lista<Carta> cartas;
};
void inicializarBaralho(Baralho &baralho) {
    inicializar(baralho.cartas); // zera a lista
    string naipes[] = {"Copas", "Espadas", "Ouros", "Paus"};
    string nomes[] = {"A", "2", "3", "4", "5", "6", "7", "J", "Q", "K"};
    int valores[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // valores usados para comparações no jogo
    for (int n = 0; n < 4; n++) { // para cada naipe
        for (int i = 0; i < 10; i++) { // para cada valor
            Carta c;
            c.nome = nomes[i];
            c.naipe = naipes[n];
            c.valor = valores[i];
            inserirFinal(baralho.cartas, c); // insere no baralho
        }
    }
}

void embaralhar(Baralho &baralho) {
    for (int i = 0; i < baralho.cartas.ultimo; i++) {
        int j = rand() % baralho.cartas.ultimo;
        // troca as cartas i e j
        Carta temp1, temp2;
        obterItemNaPosicao(baralho.cartas, i, temp1);
        obterItemNaPosicao(baralho.cartas, j, temp2);
        alterarNaPosicao(baralho.cartas, i, temp2);
        alterarNaPosicao(baralho.cartas, j, temp1);
    }
}

#endif
