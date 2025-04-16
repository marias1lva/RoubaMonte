#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <string>
#include "ListaEncadeada.hpp"
#include "Carta.hpp"

struct Jogador {
    string nome; // nome do jogador
    ListaEncadeada<Carta> monte; // representa as cartas que o jogador capturou ao longo do jogo
    ListaEncadeada<Carta> mao; // representa as cartas que o jogador tem na mão, ou seja, que ele pode jogar
};

void inicializar(Jogador& jogador, string nome) { // recebe uma referência para o jogador e o nome 
    jogador.nome = nome; // define o nome do jogador
    // inicializa as listas encadeadas para o monte e a mão
    inicializar(jogador.monte);
    inicializar(jogador.mao);
}

#endif