#include <iostream>
#include <string>
#include <sstream>
#include "../include/Sistema.hpp"

int main() {
    Sistema sistema;
    std::string linha;

    std::cout << "\n--------- LISTA DE COMANDOS ---------\n"
        << "\n{CJ 'apelido' 'nome'}: Cadastrar jogador\n" 
              << "{RJ 'apelido'}: Remover jogador\n"
              << "{LJ 'criterio'} Listar estatisticas. Criterios: N-> ordem por nome; A-> ordem por apelido\n"
              << "{EP 'jogo' 'apelido1' 'apelido2'} Iniciar jogo {L-> Lig4; R-> Reversi; V-> Jogo da velha}\n"
              << "{FS} Finalizar Sistema\n" 
        << "-----------------------------------" << std::endl;

    while (true) {
        std::cout << "Digite um comando: ";
        std::getline(std::cin, linha);
        std::istringstream iss(linha);
        std::string comando;
        iss >> comando;

        if (comando == "FS") {
            sistema.finalizarSistema();
            break;
        } else if (comando == "CJ") {
            std::string apelido, nome;
            iss >> apelido >> nome;
            if (apelido.empty() || nome.empty()) {
                std::cout << "ERRO: dados incorretos\n" << std::endl;
            } else if (sistema.cadastrarJogador(apelido, nome)) {
                std::cout << "Jogador " << apelido << " cadastrado com sucesso\n" << std::endl;
            } else {
                std::cout << "ERRO: jogador repetido\n" << std::endl;
            }
        } else if (comando == "RJ") {
            std::string apelido;
            iss >> apelido;
            if (apelido.empty()) {
                std::cout << "ERRO: dados incorretos\n" << std::endl;
            } else if (sistema.removerJogador(apelido)) {
                std::cout << "Jogador " << apelido << " removido com sucesso\n" << std::endl;
            } else {
                std::cout << "ERRO: jogador inexistente\n" << std::endl;
            }
        } else if (comando == "LJ") {
            char criterio;
            iss >> criterio;
            if (criterio != 'A' && criterio != 'N') {
                std::cout << "ERRO: dados incorretos\n" << std::endl;
            } else {
                sistema.listarJogadores(criterio);
            }
        } else if (comando == "EP") {
            std::string jogo, apelido1, apelido2;
            iss >> jogo >> apelido1 >> apelido2;

            if (jogo.empty() || apelido1.empty() || (jogo != "R" && jogo != "L" && jogo != "V")) {
                std::cout << "ERRO: dados incorretos\n" << std::endl;
            } else {
                if (apelido2.empty() || apelido1 == apelido2) {
                    std::cout << "ERRO: dados incorretos\n" << std::endl;
                } else if (!sistema.executarPartida(jogo, apelido1, apelido2)) {
                    std::cout << "ERRO: jogador inexistente\n" << std::endl;
                }
            }
        } else {
            std::cout << "Comando não reconhecido. Tente novamente.\n" << std::endl;
        }
    }

    return 0;
}