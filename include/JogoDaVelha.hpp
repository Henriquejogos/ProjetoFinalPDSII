#ifndef JOGODAVELHA_HPP
#define JOGODAVELHA_HPP

#include <vector>
#include <iostream>
#include "Jogo.hpp"

class JogoDaVelha : public Jogo {
public:
    JogoDaVelha();
    void iniciar() override;
    int getAltura() const override;
    int getLargura() const override;
    void imprimirTabuleiro() override;
    bool validarJogada(int linha, int coluna) override;
    bool verificarVitoria() override;
    void realizarJogada(int linha, int coluna) override;
    bool empatePartida() override;

private:
    void alternarJogador();
    bool verificarLinhas();
    bool verificarColunas();
    bool verificarDiagonais();

    std::vector<std::vector<char>> tabuleiro;
    char jogadorAtual;
};

#endif