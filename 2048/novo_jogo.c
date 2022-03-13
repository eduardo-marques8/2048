#include "main.h"
#include <conio2.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "imprime_tabuleiro.h"
#include "gera2ou4.h"
#include "movimentos.h"
#include "encerramentos.h"

// função de gerenciamento do jogo. cuida da criação de um novo jogo e da captação de movimentos do usuário.
void novo_jogo (peca *tabuleiro, int novo, long int score, long int movimentos) { // recebe o ponteiro tabuleiro, a variável
                                                                                  // novo( que indica se estamos criando um
                                                                                  // novo jogo ou não), o score e o número
                                                                                  // de movimentos
    char opcao; // opção selecionada pelo usuário quanto ao jogo
    peca zero = {0, YELLOW}; // define uma peça neutra/inicial. peça de valor zero e cor amarela
    int pode, resultado, game_over = 0; // variável pode para indicar se é possível se movimentar, resultado para indicar se
                                        // chegamos no valor 2048 e game_over para indicar se não é mais possível se mover

    NORMALIZA; // normaliza as configurações e limpa a tela

    if (novo == 1) // se estamos criando um novo jogo (caso da variável novo igual a 1)
        {
            int linha, coluna; // variáveis de controle da matriz, representando as linhas e colunas
            for (linha = 0; linha < 4; linha++) // percorre todas as 4 linhas da matriz
                for (coluna = 0; coluna < 4; coluna++) // percorre todas as 4 colunas da matriz
                *(tabuleiro + linha*4 + coluna) = zero; // a peça em tabuleiro[linha][coluna] será a zero (faz isso para
                                                        // todo o tabuleiro. zera todas as casas)
                // utiliza-se a equação de endereçamento, onde
                // tabuleiro = base, endereço relativo da matriz na memória
                // linha*4 = seleciona a linha
                // coluna = seleciona a coluna
                // (linha*4 + coluna) = define o deslocamento
                // essa equação foi utilizada pelo restante do código

            gera2 (tabuleiro, 4, zero); // gera uma peça 2 no tabuleiro com a função gera2, enviando o ponteiro tabuleiro,
                                        // a ordem da matriz que é 4, e a peça neutra zero.
            gera2 (tabuleiro, 4, zero); // gera uma outra peça 2 no tabuleiro com a função gera2, enviando o ponteiro
                                        // tabuleiro, a ordem da matriz que é 4, e a peça neutra zero.
        }

    imprime_tabuleiro(); // imprime o tabuleiro do jogo
    imprime_numeros(tabuleiro); // imprime os números no tabuleiro, logo, na tela. passa o ponteiro tabuleiro para a função
    imprime_score(score); // imprime a pontuação na tela. passa a long int score para a função
    imprime_movimentos(movimentos); // imprime os movimentos na tela. passa a long int movimentos para a função

    do { // faça
        pode = 0; // inicia a variável de movimento pode como 0
        opcao = getch(); // opção será um caractere fornecido pelo usuário e lido pela função getch()

        switch(opcao) { // analisa os casos de opção
        case CHAR_N: // se opção = n
            confirma_novo(tabuleiro, score, movimentos); // vai para função confirmar_novo
            return; // retorna para a função main ou novo_jogo
            break; // para

        case CHAR_S: // se opção = s
            // manda para a função salvar_ou_carregar:
            // o valor 1, que representa a opção de salvar
            // o valor 0, que representa que não estamos indo da função principal
            // o tabuleiro do jogo
            // o endereço do score
            // o endereço dos movimentos
            salvar_ou_carregar(1, 0, tabuleiro, &score, &movimentos);
            break;

        case CHAR_C: // se opção = c
            // manda para a função salvar_ou_carregar:
            // o valor 0, que representa a opção de carregar
            // o valor 0, que representa que não estamos indo da função principal
            // o tabuleiro do jogo
            // o endereço do score
            // o endereço dos movimentos
            salvar_ou_carregar(0, 0, tabuleiro, &score, &movimentos);
            break; // para

        case ESC: // se opção = ESC (em ASCII)
            confirma_saida(tabuleiro, score, movimentos); // vai para a função confirmar_saida
            return; // retorna para a função main ou novo_jogo
            break; // para

        case CIMA: // se opção = seta para cima (em ASCII)
            pode = pode_cima(tabuleiro, 4, &score, &resultado, zero); // verifica se há possibilidade de movimento a partir
                                                                      // da função pode_cima, enviando o ponteiro
                                                                      // tabuleiro, a ordem 4, o endereço na memória de score,
                                                                      // o endereço na memória de resultado e a peça zero.
            if(pode == 1){ // se pode for igual a 1, ou seja, é possível se mover para cima
                gera2ou4(tabuleiro, 4); // gera um 2 ou um 4 no tabuleiro
                movimentos++; // incrementa o número de movimentos
            }
            break; // para

        case BAIXO: // se opção = seta para baixo (em ASCII)
            pode = pode_baixo(tabuleiro, 4, &score, &resultado, zero); // verifica se há possibilidade de movimento a partir
                                                                       // da função pode_baixo, enviando o ponteiro
                                                                       // tabuleiro, a ordem 4, o endereço na memória de score,
                                                                       // o endereço na memória de resultado e a peça zero.
            if(pode == 1) { // se pode for igual a 1, ou seja, é possível se mover para baixo
                gera2ou4(tabuleiro, 4); // gera um 2 ou um 4 no tabuleiro
                movimentos++; // incrementa o número de movimentos
            }
            break; // para

        case ESQ: // se opção = seta para esquerda (em ASCII)
            pode = pode_esquerda(tabuleiro, 4, &score, &resultado, zero); // verifica se há possibilidade de movimento a partir
                                                                          // da função pode_esquerda, enviando o ponteiro
                                                                          // tabuleiro, a ordem 4, o endereço na memória de score,
                                                                          // o endereço na memória de resultado e a peça zero.
            if(pode == 1) { // se pode for igual a 1, ou seja, é possível se mover para esquerda
                gera2ou4(tabuleiro, 4); // gera um 2 ou um 4 no tabuleiro
                movimentos++; // incrementa o número de movimentos
            }
            break; // para

        case DIR: // se opção = seta para direita (em ASCII)
            pode = pode_direita(tabuleiro, 4, &score, &resultado, zero); // verifica se há possibilidade de movimento a partir
                                                                         // da função pode_direita, enviando o ponteiro
                                                                         // tabuleiro, a ordem 4, o endereço na memória de score,
                                                                         // o endereço na memória de resultado e a peça zero.
            if(pode == 1) { // se pode for igual a 1, ou seja, é possível se mover para direita
                gera2ou4(tabuleiro, 4); // gera um 2 ou um 4 no tabuleiro
                movimentos++; // incrementa o número de movimentos
            }
            break; // para
        }

        imprime_numeros(tabuleiro); // imprime os números no tabuleiro, logo, na tela. passa o ponteiro tabuleiro para a
                                    // função
        imprime_score(score); // imprime a pontuação na tela. passa a long int score para a função
        imprime_movimentos(movimentos); // imprime os movimentos na tela. passa a long int movimentos para a função

        game_over = derrota(tabuleiro, 4); // define game_over de acordo com a função derrota, que devolve 1 se não
                                           // houver mais movimentos disponíveis e 0 se houver

        if(game_over == 1){ // se game_over for igual a 1, ou seja, não há movimentos disponíveis
            fim_de_jogo(0, score); // vai para a função fim_de_jogo com a opção 0
            return; // retorna para a função main ou novo_jogo
        }

        if(resultado == OBJETIVO) { // se o valor de resultado for igual a 2048
            fim_de_jogo(1, score); // vai para a função fim_de_jogo com a opção 1
            return; // retorna para a função main ou novo_jogo
        }

    } while(opcao != (CHAR_N || CHAR_C || ESC)); // enquanto a opção for diferente dos caracteres n, c ou ESC (em ASCII)
}
