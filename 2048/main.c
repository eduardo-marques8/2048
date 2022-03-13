#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <conio.h>
#include "novo_jogo.h"
#include "gera2ou4.h"
#include "imprime_tabuleiro.h"
#include "salvar_ou_carregar.h"
#include "main.h"

// Jogo 2048 implementado na linguagem C por Eduardo Luís Marques,
// número de matrícula: 00323594, e Nathan Rodrigues de Brito, número
// de matrícula: 00330319, turma C.

// função main do jogo
int main()
{

    peca tabuleiro[4][4]; // cria a matriz do tabuleiro do jogo, de ordem 4 com elementos de estrutura do tipo peça

    long int score = 0, movimentos = 0; // variável score para representar a pontuação do jogo e movimentos para representar
                                        // os movimentos dados (ambas do tipo long int, devido a seu grande tamanho)

    int valor = 0; // variável para indicar se foi possível ou não carregar um jogo salvo

    char opcao; // opção selecionada pelo usuário quanto ao jogo

    int continuar = 1; // variável para definir se continuamos executando ou não

    system ("mode con: lines=55 cols=100"); // define a janela do sistema com 55 de altura e 100 de largura, para se adequar
                                            // melhor ao jogo

    SET_COLORS(RED,YELLOW); // pinta de vermelho o fundo do que está escrito na tela e pinta de amarelo o texto escrito na tela

    // desenha um menu na tela com um 2048 estilizado e as opções descritas para o usuário
    printf("/-------------------------------------------------------------------------------------------------\\\n");
    printf("|  ___   ___  _  _   ___                                                                          |\n");
    printf("| |__ \\ / _ \\| || | / _ \\                             Pressione:                                  |\n");
    printf("|    ) | | | | || || (_) |                              'n'   para Novo Jogo;                     |\n");
    printf("|   / /| | | |__   _> _ <                               'c'   para carregar um jogo salvo;        |\n");
    printf("|  / /_| |_| |  | || (_) |                              'ESC' para sair.                          |\n");
    printf("| |____|\\___/   |_| \\___/                                                                         |\n");
    printf("|                                                                                                 |\n");
    printf("\\-------------------------------------------------------------------------------------------------/\n");

    do { // faça
        opcao = getch(); // opção será um caractere fornecido pelo usuário e lido pela função getch()

        switch(opcao) { // analisa os casos de opção
        case CHAR_N: // se opção = n
            novo_jogo(tabuleiro, 1, score, movimentos); // começa um novo jogo (vai para a função novo_jogo), mandando o
                                                        // tabuleiro, o valor 1 (que representa se o jogo é novo ou não.
                                                        // 1 para sim e 0 para não), e os valores iniciais de score e
                                                        // movimentos.
            continuar = 0; // seta a flag de continuação para 0
            break; // para

        case CHAR_C: // se opção = c
            // manda para a função salvar_ou_carregar:
            // o valor 0, que representa a opção de carregar
            // o valor 1, que representa que estamos indo da função principal
            // o tabuleiro do jogo
            // o endereço do score
            // o endereço dos movimentos
            valor = salvar_ou_carregar(0, 1, tabuleiro, &score, &movimentos); // define valor como o retorno da função,
                                                                              // sendo 1 para se foi possível carregar
                                                                              // o jogo e 0 se não foi
            if(valor == 1) novo_jogo(tabuleiro, 0, score, movimentos); // se valor igual a 1, inicia um jogo com os valores
                                                                       // carregados do arquivo
            else main(); // se não, volta para o menu inicial
            continuar = 0; // seta a flag de continuação para 0
            break; // para

        case ESC: // se opção = ESC (em ASCII)
            printf("Obrigado por jogar 2048.\n"); // printa uma mensagem de encerramento
            continuar = 0; // seta a flag de continuação para 0
            break; // para
        }
    } while(continuar == 1); // enquanto a opção for diferente dos caracteres n, c ou ESC (em ASCII)

    return 0; // encerra o programa
}
