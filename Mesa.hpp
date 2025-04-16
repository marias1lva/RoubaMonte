#ifndef MESA_HPP
#define MESA_HPP
#include "ListaDuplamenteEncadeada.hpp"
#include "Carta.hpp"

struct Mesa {
    ListaDuplamenteEncadeada<Carta> cartas;
};

void inicializar(Mesa& mesa) { // inicializa a lista de cartas da mesa
    inicializar(mesa.cartas);
}

#endif