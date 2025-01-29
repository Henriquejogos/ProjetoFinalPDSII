#include "../include/Sistema.hpp"
#include "../include/Reversi.hpp"
#include "../include/Lig4.hpp"
#include "../include/JogoDaVelha.hpp"
#include <iostream>
#include <sstream>

void Sistema::executar() {
}

bool Sistema::cadastrarJogador(const std::string& apelido, const std::string& nome) {
    return cadastro.cadastrarJogador(apelido, nome);
}

bool Sistema::removerJogador(const std::string& apelido) {
    return cadastro.removerJogador(apelido);
}

void Sistema::listarJogadores(char criterio) {
    cadastro.listarJogadores(criterio);
}

bool Sistema::executarPartida(const std::string& jogo, const std::string& apelido1, const std::string& apelido2) {
    Jogador* jogador1 = cadastro.buscarJogador(apelido1);
    Jogador* jogador2 = cadastro.buscarJogador(apelido2);

    if (!jogador1 || !jogador2) {
        return false;
    }

    Jogo* partida = criarJogo(jogo);
    if (!partida) {
        return false;
    }

    partida->iniciar();
    std::string jogada;
    bool turnoJogador1 = true; 
    std::string apelidoAtual;
    char simboloAtual;

    while (!partida->verificarVitoria() && jogada != "SAIR") {
        apelidoAtual = turnoJogador1 ? apelido1 : apelido2;
        simboloAtual = (apelidoAtual == apelido1) ? 'X' : 'O';

        std::cout << "Turno de jogador " << apelidoAtual << " (" << simboloAtual << "): ";
        std::getline(std::cin >> std::ws, jogada);

        if (jogada == "SAIR") {
            break;
        }

        std::istringstream iss(jogada);
        int linha = 0, coluna = 0;

        if (jogo == "R") {
            if (!(iss >> linha >> coluna)) {
                std::cout << "ERRO: formato incorreto\n" << std::endl;
                continue;
            }
        } else if (jogo == "L") {
            if (!(iss >> coluna)) {
                std::cout << "ERRO: formato incorreto\n" << std::endl;
                continue;
            }
            linha = 0;
        } else if(jogo == "V"){
            if (!(iss >> linha >> coluna) || linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3) {
                std::cout << "ERRO: formato incorreto ou posição inválida (0-2 para linha e coluna)\n" << std::endl;
                continue;
            }
        }

        if (partida->validarJogada(linha, coluna)) {
            partida->realizarJogada(linha, coluna);
            turnoJogador1 = !turnoJogador1; 
        } else {
            std::cout << "ERRO: jogada inválida\n" << std::endl;
        }
    }

    if (jogada == "SAIR") {
        std::cout << "\n  " << apelidoAtual << " SAIU DO JOGO" << std::endl;
        apelidoAtual = !turnoJogador1 ? apelido1 : apelido2;
        std::cout << "  VITÓRIA " << apelidoAtual << "!\n" << std::endl;
    } else if (!partida->empatePartida()){
        std::cout << "\n VITÓRIA " << apelidoAtual << "!\n" << std::endl;
    }

    if (!partida->empatePartida()){
        cadastro.buscarJogador(apelidoAtual)->adicionarVitoria(jogo);
        apelidoAtual = turnoJogador1 ? apelido1 : apelido2;

        cadastro.buscarJogador(apelidoAtual)->adicionarDerrota(jogo);
    }

    if (partida->empatePartida()){
        std::cout << "\n  EMPATE\n" << std::endl;
    }

    delete partida;
    return true;
}

void Sistema::finalizarSistema() {
    std::cout << "Sistema finalizado. Obrigado por jogar!" << std::endl;
}

Jogo* Sistema::criarJogo(const std::string& jogo) {
    if (jogo == "R") {
        return new Reversi();
    } else if (jogo == "L") {
        return new Lig4();
    } else if(jogo == "V"){
        return new JogoDaVelha();
    }
    return nullptr;
}