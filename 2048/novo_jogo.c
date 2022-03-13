#include "main.h"
#include <conio2.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "imprime_tabuleiro.h"
#include "gera2ou4.h"
#include "movimentos.h"
#include "encerramentos.h"

// fun��o de gerenciamento do jogo. cuida da cria��o de um novo jogo e da capta��o de movimentos do usu�rio.
void novo_jogo (peca *tabuleiro, int novo, long int score, long int movimentos) { // recebe o ponteiro tabuleiro, a vari�vel
                                                                                  // novo( que indica se estamos criando um
                                                                                  // novo jogo ou n�o), o score e o n�mero
                                                                                  // de movimentos
    char opcao; // op��o selecionada pelo usu�rio quanto ao jogo
    peca zero = {0, YELLOW}; // define uma pe�a neutra/inicial. pe�a de valor zero e cor amarela
    int pode, resultado, game_over = 0; // vari�vel pode para indicar se � poss�vel se movimentar, resultado para indicar se
                                        // chegamos no valor 2048 e game_over para indicar se n�o � mais poss�vel se mover

    NORMALIZA; // normaliza as configura��es e limpa a tela

    if (novo == 1) // se estamos criando um novo jogo (caso da vari�vel novo igual a 1)
        {
            int linha, coluna; // vari�veis de controle da matriz, representando as linhas e colunas
            for (linha = 0; linha < 4; linha++) // percorre todas as 4 linhas da matriz
                for (coluna = 0; coluna < 4; coluna++) // percorre todas as 4 colunas da matriz
                *(tabuleiro + linha*4 + coluna) = zero; // a pe�a em tabuleiro[linha][coluna] ser� a zero (faz isso para
                                                        // todo o tabuleiro. zera todas as casas)
                // utiliza-se a equa��o de endere�amento, onde
                // tabuleiro = base, endere�o relativo da matriz na mem�ria
                // linha*4 = seleciona a linha
                // coluna = seleciona a coluna
                // (linha*4 + coluna) = define o deslocamento
                // essa equa��o foi utilizada pelo restante do c�digo

            gera2 (tabuleiro, 4, zero); // gera uma pe�a 2 no tabuleiro com a fun��o gera2, enviando o ponteiro tabuleiro,
                                        // a ordem da matriz que � 4, e a pe�a neutra zero.
            gera2 (tabuleiro, 4, zero); // gera uma outra pe�a 2 no tabuleiro com a fun��o gera2, enviando o ponteiro
                                        // tabuleiro, a ordem da matriz que � 4, e a pe�a neutra zero.
        }

    imprime_tabuleiro(); // imprime o tabuleiro do jogo
    imprime_numeros(tabuleiro); // imprime os n�meros no tabuleiro, logo, na tela. passa o ponteiro tabuleiro para a fun��o
    imprime_score(score); // imprime a pontua��o na tela. passa a long int score para a fun��o
    imprime_movimentos(movimentos); // imprime os movimentos na tela. passa a long int movimentos para a fun��o

    do { // fa�a
        pode = 0; // inicia a vari�vel de movimento pode como 0
        opcao = getch(); // op��o ser� um caractere fornecido pelo usu�rio e lido pela fun��o getch()

        switch(opcao) { // analisa os casos de op��o
        case CHAR_N: // se op��o = n
            confirma_novo(tabuleiro, score, movimentos); // vai para fun��o confirmar_novo
            return; // retorna para a fun��o main ou novo_jogo
            break; // para

        case CHAR_S: // se op��o = s
            // manda para a fun��o salvar_ou_carregar:
            // o valor 1, que representa a op��o de salvar
            // o valor 0, que representa que n�o estamos indo da fun��o principal
            // o tabuleiro do jogo
            // o endere�o do score
            // o endere�o dos movimentos
            salvar_ou_carregar(1, 0, tabuleiro, &score, &movimentos);
            break;

        case CHAR_C: // se op��o = c
            // manda para a fun��o salvar_ou_carregar:
            // o valor 0, que representa a op��o de carregar
            // o valor 0, que representa que n�o estamos indo da fun��o principal
            // o tabuleiro do jogo
            // o endere�o do score
            // o endere�o dos movimentos
            salvar_ou_carregar(0, 0, tabuleiro, &score, &movimentos);
            break; // para

        case ESC: // se op��o = ESC (em ASCII)
            confirma_saida(tabuleiro, score, movimentos); // vai para a fun��o confirmar_saida
            return; // retorna para a fun��o main ou novo_jogo
            break; // para

        case CIMA: // se op��o = seta para cima (em ASCII)
            pode = pode_cima(tabuleiro, 4, &score, &resultado, zero); // verifica se h� possibilidade de movimento a partir
                                                                      // da fun��o pode_cima, enviando o ponteiro
                                                                      // tabuleiro, a ordem 4, o endere�o na mem�ria de score,
                                                                      // o endere�o na mem�ria de resultado e a pe�a zero.
            if(pode == 1){ // se pode for igual a 1, ou seja, � poss�vel se mover para cima
                gera2ou4(tabuleiro, 4); // gera um 2 ou um 4 no tabuleiro
                movimentos++; // incrementa o n�mero de movimentos
            }
            break; // para

        case BAIXO: // se op��o = seta para baixo (em ASCII)
            pode = pode_baixo(tabuleiro, 4, &score, &resultado, zero); // verifica se h� possibilidade de movimento a partir
                                                                       // da fun��o pode_baixo, enviando o ponteiro
                                                                       // tabuleiro, a ordem 4, o endere�o na mem�ria de score,
                                                                       // o endere�o na mem�ria de resultado e a pe�a zero.
            if(pode == 1) { // se pode for igual a 1, ou seja, � poss�vel se mover para baixo
                gera2ou4(tabuleiro, 4); // gera um 2 ou um 4 no tabuleiro
                movimentos++; // incrementa o n�mero de movimentos
            }
            break; // para

        case ESQ: // se op��o = seta para esquerda (em ASCII)
            pode = pode_esquerda(tabuleiro, 4, &score, &resultado, zero); // verifica se h� possibilidade de movimento a partir
                                                                          // da fun��o pode_esquerda, enviando o ponteiro
                                                                          // tabuleiro, a ordem 4, o endere�o na mem�ria de score,
                                                                          // o endere�o na mem�ria de resultado e a pe�a zero.
            if(pode == 1) { // se pode for igual a 1, ou seja, � poss�vel se mover para esquerda
                gera2ou4(tabuleiro, 4); // gera um 2 ou um 4 no tabuleiro
                movimentos++; // incrementa o n�mero de movimentos
            }
            break; // para

        case DIR: // se op��o = seta para direita (em ASCII)
            pode = pode_direita(tabuleiro, 4, &score, &resultado, zero); // verifica se h� possibilidade de movimento a partir
                                                                         // da fun��o pode_direita, enviando o ponteiro
                                                                         // tabuleiro, a ordem 4, o endere�o na mem�ria de score,
                                                                         // o endere�o na mem�ria de resultado e a pe�a zero.
            if(pode == 1) { // se pode for igual a 1, ou seja, � poss�vel se mover para direita
                gera2ou4(tabuleiro, 4); // gera um 2 ou um 4 no tabuleiro
                movimentos++; // incrementa o n�mero de movimentos
            }
            break; // para
        }

        imprime_numeros(tabuleiro); // imprime os n�meros no tabuleiro, logo, na tela. passa o ponteiro tabuleiro para a
                                    // fun��o
        imprime_score(score); // imprime a pontua��o na tela. passa a long int score para a fun��o
        imprime_movimentos(movimentos); // imprime os movimentos na tela. passa a long int movimentos para a fun��o

        game_over = derrota(tabuleiro, 4); // define game_over de acordo com a fun��o derrota, que devolve 1 se n�o
                                           // houver mais movimentos dispon�veis e 0 se houver

        if(game_over == 1){ // se game_over for igual a 1, ou seja, n�o h� movimentos dispon�veis
            fim_de_jogo(0, score); // vai para a fun��o fim_de_jogo com a op��o 0
            return; // retorna para a fun��o main ou novo_jogo
        }

        if(resultado == OBJETIVO) { // se o valor de resultado for igual a 2048
            fim_de_jogo(1, score); // vai para a fun��o fim_de_jogo com a op��o 1
            return; // retorna para a fun��o main ou novo_jogo
        }

    } while(opcao != (CHAR_N || CHAR_C || ESC)); // enquanto a op��o for diferente dos caracteres n, c ou ESC (em ASCII)
}
