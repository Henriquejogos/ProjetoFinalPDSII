# Projeto Final - Jogos de Tabuleiro
## Descrição Geral. 
Esse programa foi desenvolvido para ser o trabalho final da discplina de Programação e Desenvolvimento de Software II(PDSII). Ele foi feito pelos seguintes integrantes do grupo: Bianca Fonseca, Guilherme Gaspar, Henrique Mateus e Vitor Nunes.  O projeto tem como objetivo ser uma central de jogos de tabuleiro, permitindo aos usuários criar jogadores e jogar Ligue 4, Reversi e Jogo da Velha. O sistema é implementado em C++ e se caracteriza por seu desolvolvimento usando POO e práticas de programação defensiva. A arquitetura do sistema é composta por várias classes, sendo que o arquivo principal (main.cpp) interage com a classe Sistemas.cpp, no qual gerencia a conexão entre as classes de Jogadores e Jogos.

## Estrutura do Sistema
O sistema é composto pelos seguintes arquivos principais:

+ main.cpp: Arquivo responsável pela execução do programa e pela entrada dos comandos de partida.

+ Sistema.cpp: Responsável pela lógica central do sistema. Ela faz a ligação entre os jogadores e os jogos, gerenciando as interações entre as partes.
  
+ Jogador.cpp: Contém a definição dos jogadores, incluindo informações como nome, identificador e status

+ CadastroJogador.cpp: Responsável pela criação de novos jogadores;

+ Jogos.hpp: Interface abstrata usada como base para a criação dos jogos.

+ JogoDaVelha.cpp: Implementação do jogo da velha.

+ Lig4.cpp: Implementação do ligue 4.

+ Reversi.cpp: Implementação do Reversi.


## Funcionamento do Sistema
O sistema permite que dois jogadores interajam simultaneamente em uma partida. Todos os jogos são jogados por entradas na linha de comando e possuem uma interface gráfica feita em ASCII, que é atualizada a cada rodada computada corretamente. Além disso, é possível criar novos jogadores, informando seus nomes e respectivos apelidos, deletar jogadores, também informando seus apelidos; listar os jogadores, mostrando seus nomes e estatisticas de partidas jogadas;  e por fim, finalizar o programa com um comando.

## Fluxo do Sistema
+ Início no Main: Quando o programa é iniciado, o main exibe um menu  que permite ao usuário escolher o que deseja fazer. As opções incluem terminar o programa, criar novos jogadores, deletar jogadores, listar jogadores ou até criar uma partida com dois jogadores.

+ Gerenciamento de jogadores: O usuário pode decidir criar novos jogadores, fornecendo um nome e um apelido para cada um. Esses dados são armazenados, e a quantidade de vitórias e derrotas do jogador começa zerada. É possível também:
Deletar Jogadores: Se o usuário quiser remover um jogador, ele pode selecionar um da lista e o sistema apaga suas informações.
Listar Jogadores: O usuário também pode visualizar todos os jogadores registrados junto com suas estatísticas de vitórias e derrotas.

+ Criação de uma Partida: Quando o usuário escolhe criar uma partida, o main pede que ele selecione dois jogadores para participar. O sistema então cria uma partida entre eles, mas antes de rodar o jogo, ele escolhe o tipo de jogo (Jogo da Velha, Ligue 4 ou Reversi).
+ Sistema: A classe de sistema cuida de organizar tudo e chama as classes específicas para controlar cada tipo de jogo, como  Jogo da Velha, Ligue 4 ou Reversi. Essas classes gerenciam a lógica de como o jogo é jogado, como a troca de turnos e as regras do jogo. Elas também geram a interface visual do tabuleiro, de forma que o usuário possa ver e interagir com ele.

+ Execução da Partida: Durante a partida, as classes de jogo controlam as jogadas e verificam se são válidas. Por exemplo, no Jogo da Velha, elas garantem que o jogador só possa colocar sua peça em um espaço vazio. No final do jogo, a classe de jogo determina quem venceu, quem perdeu ou se houve um empate, e passa essa informação de volta ao sistema.
+ Resultado da Partida: Com o resultado da partida em mãos, o sistema atualiza as estatísticas dos jogadores, incrementando as vitórias e derrotas de acordo com o resultado da partida. O ciclo pode continuar com o usuário criando novos jogadores, jogando mais partidas ou visualizando as informações dos jogadores. O programa fica sempre pronto para gerenciar novos jogos e interações conforme necessário.
