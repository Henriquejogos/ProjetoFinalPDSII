#ifndef LIG4_HPP
#define LIG4_HPP

#include "Jogo.hpp"
#include <vector>
#include <limits>
#include <sstream> 

class Lig4 : public Jogo {
public:
    void iniciar() override;
    void imprimirTabuleiro() override;
    bool validarJogada(int linha, int coluna) override;
    bool verificarVitoria() override;
    void realizarJogada(int linha, int coluna) override;
    int getAltura() const override;
    int getLargura() const override;
    bool empatePartida() override;
    void alternarJogador();
    void realizarJogadaNaColuna(int coluna);

private:
    std::vector<std::vector<char>> tabuleiro;
    int numLinhas = 0;
    int numColunas = 0;
    int numJogadas;
    void criarTabuleiro();
    char jogadorAtual;
    bool jogadaValida(int coluna);
    bool verificarDirecao(int linha, int coluna, int dLinha, int dColuna);
    bool verificarVitoriaNaDirecao(int linha, int coluna, int dLinha, int dColuna);
};

#endif