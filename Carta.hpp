#ifndef CARTA_HPP
#define CARTA_HPP

#include <iostream>
#include <string>
using namespace std;

struct Carta {
    string nome; // nome da carta (A, 2, 3, ..., J, Q, K)
    string naipe; // naipe da carta (copas, paus, espadas, ouros)
    int valor; // valor da carta (1 a 10)
    bool operator==(const Carta& outra) const { // operador de comparação para verificar se duas cartas são iguais (carta1 == carta2)
        return valor == outra.valor; // comparação baseada apenas no valor - isso faz sentido pro "Rouba Monte", onde o valor da carta determina a captura, independentemente do naipe
    }
};

ostream& operator<<(ostream& os, const Carta& carta) { // permite que use cout << carta; diretamente
    os << carta.nome << " de " << carta.naipe;
    return os;
}

#endif