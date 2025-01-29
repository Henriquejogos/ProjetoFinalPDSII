#include "../include/Lig4.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Lig4::iniciar() {
    std::cout <<"\nInforme as dimençoes do tabuleiro: 'numero linhas' 'numero colunas'" << std::endl;
    criarTabuleiro();
    jogadorAtual = 'X';
    std::cout << "\nCOMO JOGAR-> digite 'numero coluna' da jogada" << std::endl;
    std::cout << "SAIR DO JOGO-> digite 'SAIR'\n";
    imprimirTabuleiro();
}

int Lig4::getAltura() const {
    return numLinhas;
}

int Lig4::getLargura() const {
    return numColunas;
}

void Lig4::criarTabuleiro() {
    std::string dimencoes;
    std::cout << "Numero de linhas e colunas: "; 
    std::getline(std::cin, dimencoes);
    std::istringstream iss(dimencoes);

    if (!(iss >> numLinhas >> numColunas) || numLinhas < 4 || numLinhas > 10 || numColunas < 4 || numColunas > 10) {
        std::cout << "\nERRO: Entrada inválida. Por favor, digite dois números válidos.\n"
                  << "OBS-> O menor tamanho é 4x4 e o maior 10x10\n" << std::endl;
        criarTabuleiro(); 
    }
    tabuleiro = std::vector<std::vector<char>>(numLinhas, std::vector<char>(numColunas, ' '));
}

void Lig4::imprimirTabuleiro() {
    std::cout << "\nEstado atual do tabuleiro de Lig4:" << std::endl;
    for (const auto& linha : tabuleiro) {
        for (const auto& celula : linha) {
            std::cout << "|" << celula;
        }
        std::cout << "|" << std::endl;
    }
    for(int i = 0; i < numColunas; i++){
        std::cout << " " << i;
    }
    std::cout << std::endl;
}

bool Lig4::validarJogada(int linha, int coluna) {
    return jogadaValida(coluna);
}

bool Lig4::verificarVitoria() {
    for (int i = 0; i < numLinhas; ++i) {
        for (int j = 0; j < numColunas; ++j) {
            if (tabuleiro[i][j] != ' ' && (
                verificarVitoriaNaDirecao(i, j, 1, 0) || 
                verificarVitoriaNaDirecao(i, j, 0, 1) || 
                verificarVitoriaNaDirecao(i, j, 1, 1) || 
                verificarVitoriaNaDirecao(i, j, 1, -1)   
            )) {
                return true;
            }
        }
    }

    return empatePartida();
}

bool Lig4::empatePartida(){
    if((numJogadas/2) == numColunas*numLinhas){ 
        return true;
    }
    return false;
}

void Lig4::realizarJogada(int linha, int coluna) {
    if (jogadaValida(coluna)) {
        realizarJogadaNaColuna(coluna);
        alternarJogador();
        imprimirTabuleiro();
    } else {
        std::cout << "ERRO: jogada inválida\n" << std::endl;
    }
}

void Lig4::alternarJogador() {
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

bool Lig4::jogadaValida(int coluna) {
    if(tabuleiro[0][coluna] == ' '){
        numJogadas++;
        return true;
    }
    return false;
}

void Lig4::realizarJogadaNaColuna(int coluna) {
    for (int i = (numLinhas-1); i >= 0; --i) {
        if (tabuleiro[i][coluna] == ' ') {
            tabuleiro[i][coluna] = jogadorAtual;
            break;
        }
    }
}

bool Lig4::verificarVitoriaNaDirecao(int linha, int coluna, int dLinha, int dColuna) {
    char jogador = tabuleiro[linha][coluna];
    int contagem = 0;

    for (int i = 0; i < 4; ++i) {
        int novaLinha = linha + i * dLinha;
        int novaColuna = coluna + i * dColuna;

        if (novaLinha >= 0 && novaLinha < numLinhas && novaColuna >= 0 && novaColuna < numColunas && tabuleiro[novaLinha][novaColuna] == jogador) {
            contagem++;
        } else {
            break;
        }
    }

    return contagem == 4;
}