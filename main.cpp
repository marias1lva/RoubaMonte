#include <cstdlib>
#include <ctime>
#include "ListaEstatica.hpp"
#include "ListaEncadeada.hpp"
#include "ListaDuplamenteEncadeada.hpp"
#include "Carta.hpp"
#include "Baralho.hpp"
#include "Jogador.hpp"
#include "Mesa.hpp"
#include <iostream>
using namespace std;

// distribuir Cartas
void distribuirCartas(Baralho &baralho, Jogador &j1, Jogador &j2, Mesa &mesa){
    Carta c;
    // 3 cartas pra mão de cada jogador
    for(int i = 0; i < 3; i++){
        removerCarta(baralho.cartas, c); // remove do baralho
        inserirFinal(j1.mao, c); // adiciona na mão do jogador 1
        removerCarta(baralho.cartas, c); // remove do baralho
        inserirFinal(j2.mao, c); // adiciona na mão do jogador 2
    }
    // 4 cartas na mesa
    for(int i = 0; i < 4; i++){
        removerCarta(baralho.cartas, c); // remove do baralho
        inserirFinal(mesa.cartas, c); // adiciona na mesa
    }
}

// verificar se pode roubar do monte
// verifica se a carta jogada tem o mesmo valor da carta do topo do monte do oponente
bool podeRoubarMonte(Carta jogada, Jogador &oponente){
    if(oponente.monte.tamanho == 0)
        return false;
    Carta topo;
    obterItemNaPosicao(oponente.monte, oponente.monte.tamanho - 1, topo);
    return jogada.valor == topo.valor; // se o valor da carta jogada for igual ao valor da carta do topo do monte do oponente, retorna true
}

// roubar monte
void roubarMonte(Jogador &jogador, Jogador &oponente){
    while(oponente.monte.tamanho > 0){ // enquanto o monte do oponente não estiver vazio
        Carta c; // carta a ser roubada
        obterItemNaPosicao(oponente.monte, 0, c); // pega a carta do topo do monte do oponente
        removerNaPosicao(oponente.monte, 0); // remove a carta do monte do oponente
        inserirFinal(jogador.monte, c); // adiciona a carta ao monte do jogador
    }
}

// jogar carta na mesa
void jogarCartaNaMesa(Jogador &jogador, Mesa &mesa, int indiceCarta){
    Carta c; // carta a ser jogada
    if(obterItemNaPosicao(jogador.mao, indiceCarta, c)){ // se a carta existe na mão do jogador
        removerNaPosicao(jogador.mao, indiceCarta); // remove a carta da mão do jogador
        inserirFinal(mesa.cartas, c); // adiciona a carta na mesa
    }
}

// tentar capturar carta da mesa
bool capturarDaMesa(Jogador &jogador, Mesa &mesa, Carta jogada){
    for(int i = 0; i < mesa.cartas.tamanho; i++){ // percorre as cartas da mesa
        Carta mesaCarta; // carta da mesa
        obterItemNaPosicao(mesa.cartas, i, mesaCarta); // pega a carta da mesa
        if(mesaCarta.valor == jogada.valor){ // se o valor da carta jogada for igual ao valor da carta da mesa
            removerNaPosicao(jogador.mao, descobrirIndice(jogador.mao, jogada)); // remove a carta jogada da mão do jogador
            inserirFinal(jogador.monte, jogada); // adiciona a carta jogada ao monte do jogador
            inserirFinal(jogador.monte, mesaCarta); // adiciona a carta da mesa ao monte do jogador
            removerNaPosicao(mesa.cartas, i); // remove a carta da mesa
            return true;
        }
    }
    return false;
}

// verificar fim de jogo
bool fimDoJogo(Baralho &baralho, Jogador &j1, Jogador &j2){
    return(baralho.cartas.ultimo == 0 && j1.mao.tamanho == 0 && j2.mao.tamanho == 0);
    // verifica se o baralho está vazio e se as mãos dos jogadores estão vazias, se sim, o jogo acabou
}

// determinar vencedor
string determinarVencedor(Jogador &j1, Jogador &j2){
    if(j1.monte.tamanho > j2.monte.tamanho){
        return j1.nome;
    }else if(j2.monte.tamanho > j1.monte.tamanho){
        return j2.nome;
    }else{
        return "Empate";
    }
}

int main(){
    srand(time(0)); // inicializa a semente aleatória para gerar jogadas do CPU diferentes a cada execução
    Baralho baralho;
    Jogador jogador1, jogador2;
    Mesa mesa;
    inicializarBaralho(baralho); // inicializa o baralho com 40 cartas
    embaralhar(baralho); // embaralha o baralho
    jogador1.nome = "Jogador 1";
    jogador2.nome = "CPU"; // jogador automático

    // inicializa as listas das mãos e montes dos jogadores e as cartas da mesa
    inicializar(jogador1.mao);
    inicializar(jogador1.monte);
    inicializar(jogador2.mao);
    inicializar(jogador2.monte);
    inicializar(mesa.cartas);

    // distribui as cartas iniciais para os jogadores e para a mesa
    distribuirCartas(baralho, jogador1, jogador2, mesa);

    // loop principal do jogo: roda até o baralho e as mãos dos jogadores ficarem vazios
    while (!fimDoJogo(baralho, jogador1, jogador2)) {
        // mostra as cartas na mesa
        cout << "\n=== Cartas na MESA ===\n";
        for (int i = 0; i < tamanho(mesa.cartas); i++) {
            Carta c;
            obterItemNaPosicao(mesa.cartas, i, c);
            cout << "- " << c.nome << " de " << c.naipe << endl;
        }

        // mostra topo do monte do adversário
        if (!vazia(jogador2.monte)) {
            Carta topoAdversario;
            obterItemNaPosicao(jogador2.monte, jogador2.monte.tamanho - 1, topoAdversario);
            cout << "\n Topo do monte do adversario (" << jogador2.nome << "): ";
            cout << topoAdversario.nome << " de " << topoAdversario.naipe << endl;
        } else {
            cout << "\n O monte do adversario (" << jogador2.nome << ") esta vazio." << endl;
        }

        // mostra topo do monte do jogador 1
        if (!vazia(jogador1.monte)) {
            Carta topoMeuMonte;
            obterItemNaPosicao(jogador1.monte, jogador1.monte.tamanho - 1, topoMeuMonte);
            cout << "\n Seu topo do monte: " << topoMeuMonte.nome << " de " << topoMeuMonte.naipe << endl;
        } else {
            cout << "\n Seu monte esta vazio." << endl;
        }
        cout << "\n=== Mao do "<< jogador1.nome << " ===" << endl;
        for (int i = 0; i < tamanho(jogador1.mao); i++) {
            Carta c;
            obterItemNaPosicao(jogador1.mao, i, c);
            cout << "[" << i << "] " << c.nome << " de " << c.naipe << endl;
        }
        cout << "\nEscolha uma carta para jogar (indice): ";
        int indice;
        cin >> indice;
        Carta escolhida;
        obterItemNaPosicao(jogador1.mao, indice, escolhida); // pega a carta escolhida da mão

        // verifica se é possível roubar o monte do oponente
        if(podeRoubarMonte(escolhida, jogador2)){
            cout << jogador1.nome << " roubou o monte!\n";
            roubarMonte(jogador1, jogador2);
        }else if (!capturarDaMesa(jogador1, mesa, escolhida)){ // se não puder roubar o monte, tenta capturar carta da mesa com o mesmo valor
            // se não capturar nada, joga a carta na mesa
            jogarCartaNaMesa(jogador1, mesa, indice);
        }

        // mostra as cartas atualizadas na mesa
        cout << "\n=== Cartas na MESA ===\n";
        for (int i = 0; i < tamanho(mesa.cartas); i++) {
            Carta c;
            obterItemNaPosicao(mesa.cartas, i, c);
            cout << "- " << c.nome << " de " << c.naipe << endl;
        }

        // turno do jogador2 (CPU)
        if(jogador2.mao.tamanho > 0){
            cout << "\n=== Turno do " << jogador2.nome << " ===" << endl;
            Carta escolhida;
            int indiceCPU = rand() % jogador2.mao.tamanho; // escolhe um índice aleatório por padrão

            // tenta encontrar uma carta que possa roubar o monte do jogador1
            for(int i = 0; i < jogador2.mao.tamanho; i++){
                Carta temp;
                obterItemNaPosicao(jogador2.mao, i, temp);
                if(podeRoubarMonte(temp, jogador1)){
                    indiceCPU = i; // se encontrar, atualiza o índice da jogada
                    break;
                }
            }
            obterItemNaPosicao(jogador2.mao, indiceCPU, escolhida); // pega a carta escolhida do CPU

            // CPU tenta roubar o monte
            if(podeRoubarMonte(escolhida, jogador1)){
                cout << jogador2.nome << " roubou o monte!" << endl;
                roubarMonte(jogador2, jogador1);
                removerNaPosicao(jogador2.mao, indiceCPU); // remove carta usada da mão
            }else if (!capturarDaMesa(jogador2, mesa, escolhida)){ // se não, tenta capturar carta da mesa
                jogarCartaNaMesa(jogador2, mesa, indiceCPU); // se não conseguir, joga na mesa
                cout << jogador2.nome << " jogou uma carta na mesa." << endl;
            }else{
                cout << jogador2.nome << " capturou uma carta da mesa!" << endl;
            }
        }

        // se a mão do jogador 1 estiver vazia e ainda houver cartas no baralho, distribui novas cartas
        if(jogador1.mao.tamanho == 0 && baralho.cartas.ultimo > 0){
            distribuirCartas(baralho, jogador1, jogador2, mesa);
        }
    }
    // FIM DE JOGO
    cout << "\n=== Fim do jogo ===\n";
    cout << "Monte de " << jogador1.nome << ": ";
    mostrarLista(jogador1.monte); // mostra as cartas do monte do jogador1
    cout << "Monte de " << jogador2.nome << ": ";
    mostrarLista(jogador2.monte); // mostra as cartas do monte da CPU
    // exibe o vencedor com base na quantidade de cartas capturadas
    cout << "\nVencedor: " << determinarVencedor(jogador1, jogador2) << endl;
    return 0;
}