#include "../include/JogoDaVelha.hpp"
#include <iostream>

JogoDaVelha::JogoDaVelha() : jogadorAtual('X') {
    tabuleiro = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
}

void JogoDaVelha::iniciar() {
    std::cout << "\nCOMO JOGAR-> digite 'numero linha' 'numero coluna' da jogada" << std::endl;
    std::cout << "SAIR DO JOGO-> digite 'SAIR'\n";
    imprimirTabuleiro();
}

int JogoDaVelha::getAltura() const {
    return 3;
}

int JogoDaVelha::getLargura() const {
    return 3;
}

void JogoDaVelha::imprimirTabuleiro() {
    std::cout << "\nEstado atual do tabuleiro de Jogo da Velha:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "|" << (tabuleiro[i][j] == ' ' ? ' ' : tabuleiro[i][j]);
        }
        std::cout << "|" << std::endl;
    }
}

bool JogoDaVelha::validarJogada(int linha, int coluna) {
    if (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3) {
        return false;
    }
    return tabuleiro[linha][coluna] == ' ';
}

bool JogoDaVelha::verificarVitoria() {
    return verificarLinhas() || verificarColunas() || verificarDiagonais();
}

void JogoDaVelha::realizarJogada(int linha, int coluna) {
    if (validarJogada(linha, coluna)) {
        tabuleiro[linha][coluna] = jogadorAtual;
        alternarJogador();
        imprimirTabuleiro();
    } else {
        std::cout << "ERRO: jogada inválida\n" << std::endl;
    }
}

void JogoDaVelha::alternarJogador() {
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

bool JogoDaVelha::empatePartida() {
    for (const auto& linha : tabuleiro) {
        for (const auto& celula : linha) {
            if (celula == ' ') {
                return false;
            }
        }
    }
    return !verificarVitoria();
}

bool JogoDaVelha::verificarLinhas() {
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return true;
        }
    }
    return false;
}

bool JogoDaVelha::verificarColunas() {
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return true;
        }
    }
    return false;
}

bool JogoDaVelha::verificarDiagonais() {
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return true;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return true;
    }
    return false;
}