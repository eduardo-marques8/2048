#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <conio.h>
#include "novo_jogo.h"
#include "gera2ou4.h"
#include "imprime_tabuleiro.h"
#include "salvar_ou_carregar.h"
#include "main.h"

// Jogo 2048 implementado na linguagem C por Eduardo Lu�s Marques,
// n�mero de matr�cula: 00323594, e Nathan Rodrigues de Brito, n�mero
// de matr�cula: 00330319, turma C.

// fun��o main do jogo
int main()
{

    peca tabuleiro[4][4]; // cria a matriz do tabuleiro do jogo, de ordem 4 com elementos de estrutura do tipo pe�a

    long int score = 0, movimentos = 0; // vari�vel score para representar a pontua��o do jogo e movimentos para representar
                                        // os movimentos dados (ambas do tipo long int, devido a seu grande tamanho)

    int valor = 0; // vari�vel para indicar se foi poss�vel ou n�o carregar um jogo salvo

    char opcao; // op��o selecionada pelo usu�rio quanto ao jogo

    int continuar = 1; // vari�vel para definir se continuamos executando ou n�o

    system ("mode con: lines=55 cols=100"); // define a janela do sistema com 55 de altura e 100 de largura, para se adequar
                                            // melhor ao jogo

    SET_COLORS(RED,YELLOW); // pinta de vermelho o fundo do que est� escrito na tela e pinta de amarelo o texto escrito na tela

    // desenha um menu na tela com um 2048 estilizado e as op��es descritas para o usu�rio
    printf("/-------------------------------------------------------------------------------------------------\\\n");
    printf("|  ___   ___  _  _   ___                                                                          |\n");
    printf("| |__ \\ / _ \\| || | / _ \\                             Pressione:                                  |\n");
    printf("|    ) | | | | || || (_) |                              'n'   para Novo Jogo;                     |\n");
    printf("|   / /| | | |__   _> _ <                               'c'   para carregar um jogo salvo;        |\n");
    printf("|  / /_| |_| |  | || (_) |                              'ESC' para sair.                          |\n");
    printf("| |____|\\___/   |_| \\___/                                                                         |\n");
    printf("|                                                                                                 |\n");
    printf("\\-------------------------------------------------------------------------------------------------/\n");

    do { // fa�a
        opcao = getch(); // op��o ser� um caractere fornecido pelo usu�rio e lido pela fun��o getch()

        switch(opcao) { // analisa os casos de op��o
        case CHAR_N: // se op��o = n
            novo_jogo(tabuleiro, 1, score, movimentos); // come�a um novo jogo (vai para a fun��o novo_jogo), mandando o
                                                        // tabuleiro, o valor 1 (que representa se o jogo � novo ou n�o.
                                                        // 1 para sim e 0 para n�o), e os valores iniciais de score e
                                                        // movimentos.
            continuar = 0; // seta a flag de continua��o para 0
            break; // para

        case CHAR_C: // se op��o = c
            // manda para a fun��o salvar_ou_carregar:
            // o valor 0, que representa a op��o de carregar
            // o valor 1, que representa que estamos indo da fun��o principal
            // o tabuleiro do jogo
            // o endere�o do score
            // o endere�o dos movimentos
            valor = salvar_ou_carregar(0, 1, tabuleiro, &score, &movimentos); // define valor como o retorno da fun��o,
                                                                              // sendo 1 para se foi poss�vel carregar
                                                                              // o jogo e 0 se n�o foi
            if(valor == 1) novo_jogo(tabuleiro, 0, score, movimentos); // se valor igual a 1, inicia um jogo com os valores
                                                                       // carregados do arquivo
            else main(); // se n�o, volta para o menu inicial
            continuar = 0; // seta a flag de continua��o para 0
            break; // para

        case ESC: // se op��o = ESC (em ASCII)
            printf("Obrigado por jogar 2048.\n"); // printa uma mensagem de encerramento
            continuar = 0; // seta a flag de continua��o para 0
            break; // para
        }
    } while(continuar == 1); // enquanto a op��o for diferente dos caracteres n, c ou ESC (em ASCII)

    return 0; // encerra o programa
}
