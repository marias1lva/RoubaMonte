# Rouba Monte - Jogo de Cartas em C++

## Sobre o Projeto
Este repositório contém a implementação do jogo de cartas Rouba Monte em C++, utilizando TADs (Tipos Abstratos de Dados) com templates. O objetivo principal deste projeto é aplicar conceitos de estruturas de dados como listas estáticas, listas encadeadas e listas duplamente encadeadas para gerenciar o jogo e suas regras. Além disso, o projeto permite a demonstração de habilidades de programação em C++ e manipulação eficiente de dados.

O jogo segue as regras clássicas do Rouba Monte, em que dois jogadores competem para roubar cartas do monte e ganhar pontos com base nas cartas capturadas.

## Objetivo do Projeto
Este projeto tem como objetivo explorar a implementação de jogos utilizando técnicas de programação orientada a objetos e conceitos de estruturas de dados. As principais características do jogo são:
- Distribuição de cartas
- Roubo de monte
- Captura da mesa
- Verificação de fim de jogo

O projeto foi desenvolvido com ênfase na aplicação prática de TADs, templates e estruturas de dados para criar um jogo funcional e eficiente.

## Regras do Jogo
O Rouba Monte é um jogo de cartas simples, no qual os jogadores seguem estas regras principais:
- Distribuição de Cartas: O jogo começa com um baralho de 52 cartas distribuídas entre dois jogadores.
- Roubo de Monte: Os jogadores podem "roubar" uma carta do monte se ela for a maior carta disponível na mesa ou se estiverem em uma posição estratégica.
- Captura da Mesa: O jogador pode capturar as cartas dispostas na mesa se tiver a carta correspondente no monte.
- Fim de Jogo: O jogo termina quando o baralho se esgota ou quando todas as cartas da mesa são capturadas.

## Estruturas de Dados Implementadas:
### Lista Estática: 
- Função: Armazena as cartas de maneira sequencial em um array fixo, utilizado quando o número de elementos é conhecido de antemão.
### Lista Encadeada Simples:
- Função: Permite a inserção e remoção dinâmica de cartas, com nós que apontam para o próximo, facilitando a manipulação eficiente do baralho e das cartas no jogo.
### Lista Duplamente Encadeada:
- Função: Semelhante à lista encadeada, mas com nós que apontam para o próximo e para o anterior, permitindo uma navegação mais eficiente em ambas as direções.

## Implementação do CPU
O adversário do jogo é controlado por uma inteligência artificial simples (CPU), que toma decisões baseadas nas cartas disponíveis em sua mão e nas regras do jogo Rouba Monte. A lógica da CPU foi implementada para proporcionar um desafio básico, mas funcional, ao jogador humano.
### Como o CPU Faz Suas Jogadas?
A CPU faz suas jogadas de maneira automatizada, seguindo uma abordagem simples de escolha de cartas, levando em consideração as cartas disponíveis em sua mão e as regras do jogo. A lógica básica inclui:
1. Verificação de Cartas na Mesa: A CPU verifica as cartas na mesa e tenta encontrar a melhor carta para "roubar" do monte do jogador, se possível. Caso o monte esteja vazio, ela tenta capturar uma carta da mesa.
2. Escolha de Cartas para Jogar: A CPU escolhe uma carta aleatória de sua mão, mas sempre prioriza as cartas que têm maior chance de sucesso na captura das cartas da mesa. Caso não haja nenhuma jogada viável, a CPU opta por uma jogada menos eficiente.
3. Monte Vazio: Quando o monte da CPU está vazio, ela busca capturar cartas da mesa utilizando a carta que mais favorece a situação do jogo, buscando uma maneira estratégica de diminuir a vantagem do jogador humano.
### Estratégia Simplificada: 
A implementação da CPU no momento não é baseada em inteligência artificial avançada, mas sim em uma lógica de escolha aleatória ou com prioridade para cartas mais altas, visando tornar o jogo mais dinâmico e interessante, ainda que com um nível de dificuldade moderado.

## Exemplo de Execução
Abaixo, um exemplo de execução do jogo no terminal:

```bash
Copiar
Editar
=== Cartas na MESA ===
- 6 de Espadas
- 3 de Ouros
- Q de Ouros
- 7 de Ouros

O monte do adversário (CPU) está vazio.

Seu monte está vazio.

=== Mão do Jogador 1 ===
[0] K de Copas
[1] 7 de Espadas
[2] 2 de Copas

Escolha uma carta para jogar (índice):
```
No exemplo acima, o jogador 1 tem as seguintes cartas em sua mão:
- K de Copas
- 7 de Espadas
- 2 de Copas
O jogador deve escolher um índice (0, 1 ou 2) para jogar uma das cartas de sua mão. A partir da escolha do jogador, o jogo verifica as regras e a interação com as cartas na mesa.
Após a escolha do jogador, o jogo pode continuar com a atualização da mesa, do monte e das cartas na mão do jogador, até que o jogo termine, com base nas regras do Rouba Monte.

## Como jogar
1. Para jogar, clone o repositório em seu computador com o comando abaixo:
```bash
git clone https://github.com/marias1lva/RoubaMonte.git
cd RoubaMonte
```
2. Compile o código usando um compilador de C++, como o g++:
```bash
g++ -o RoubaMonte main.cpp
```
3. Execute o jogo:
```bash
./RoubaMonte
```
O jogo será iniciado no terminal, e você será solicitado a tomar decisões para distribuir cartas, roubar o monte e capturar a mesa.
