#include "main.h"
#include <conio2.h>
#include <conio.h>
#include <time.h>
#include "imprime_tabuleiro.h"
#include "cores.h"

// fun��o para gerar a pe�a 2 inicial no tabuleiro
void gera2(peca *tabuleiro, int tamanho, peca zero) { // recebe como par�metros o ponteiro tabuleiro, a vari�vel int
                                                      // tamanho e a pe�a neutra zero
    int flag, linha, coluna; // define a vari�vel auxiliar de flag e as vari�veis de controle da matriz linha e coluna
    flag = 0; // define flag como zero
    srand(time(NULL)); // gera uma semente para a fun��o utilizando o tempo atual. necess�ria para gerar n�meros novos a cada
                       // execu��o
    while (flag == 0) // enquanto flag for igual a 0
    {
        flag = 1; // define flag como 1
        linha = rand()%tamanho; // sorteia uma linha aleat�ria entre 0 e 3 (tamanho - 1)
        coluna = rand()%tamanho; // sorteia uma coluna aleat�ria entre 0 e 3 (tamanho - 1)
        if ((tabuleiro + linha*tamanho + coluna)->valor == 0) // se o valor da pe�a nessa linha e coluna for igual a 0
        {
            (tabuleiro + linha*tamanho + coluna)->valor = 2; // o valor dessa pe�a vai se tornar 2
            // a cor dessa pe�a vai ser definida de acordo com seu valor passado para a fun��o cores
            (tabuleiro + linha*tamanho + coluna)->cor = cores((tabuleiro + linha*tamanho + coluna)->valor);
            return; // retorna para novo_jogo
        }
        // se o espa�o sorteado n�o for vazio
        // verifica se h� outro espa�o dispon�vel no tabuleiro
        for (linha = 0; linha < tamanho; linha++) // passa por todas as linhas do tabuleiro
        {
            for (coluna = 0; coluna < tamanho; coluna++) // passa por todas as colunas do tabuleiro
            {
                if ((tabuleiro + linha*tamanho + coluna)->valor == 0) // se o valor da pe�a nessa linha e coluna for
                                                                      // igual a 0
                    flag = 0; // flag se torna 0
            }
        }
    }
}

// fun��o que gera a pe�a 2 ou 4 no tabuleiro
void gera2ou4(peca *tabuleiro, int tamanho) { // recebe como par�metros o ponteiro tabuleiro e a vari�vel int tamanho
    int disponivel, linha, coluna, probabilidade; // define as vari�veis
                                                  // disponivel = para checar se existe pelo menos uma posi��o dispon�vel
                                                  // para colocar um dois ou um quatro
                                                  // linha, coluna = vari�veis de controle da matriz
                                                  // probabilidade = probabilidade da pe�a ser 2 ou 4
    disponivel = 0; // define disponivel como 0
    while (!disponivel) // enquanto n�o estiver dispon�vel
    {
        disponivel = 1; // disponivel igual a 1
        linha = rand()%tamanho; // sorteia uma linha aleat�ria entre 0 e 3 (tamanho - 1)
        coluna = rand()%tamanho; // sorteia uma coluna aleat�ria entre 0 e 3 (tamanho - 1)
        if ((tabuleiro + linha*tamanho + coluna)->valor == 0) // se o valor da pe�a na linha e coluna sorteadas for
                                                              // igual a 0
        {
            probabilidade = rand()%10; // define o valor de probabilidade, sendo 10% oara 4 e 90% para 2
            if (probabilidade >= 1) { // se a probabilidade for maior ou igual a 1
                (tabuleiro + linha*tamanho + coluna)->valor = 2; // define o valor dessa pe�a como 2
                // a cor dessa pe�a vai ser definida de acordo com seu valor passado para a fun��o cores
                (tabuleiro + linha*tamanho + coluna)->cor = cores((tabuleiro + linha*tamanho + coluna)->valor);
            } else { // se n�o
                (tabuleiro + linha*tamanho + coluna)->valor = 4; // define o valor dessa pe�a como 4
                // a cor dessa pe�a vai ser definida de acordo com seu valor passado para a fun��o cores
                (tabuleiro + linha*tamanho + coluna)->cor = cores((tabuleiro + linha*tamanho + coluna)->valor);
            }
            return 0; // sai da fun��o ap�s colocar a pe�a na casa dispon�vel
        }
        // se o espa�o sorteado n�o for vazio
        // verifica se h� algum espa�o dispon�vel no tabuleiro
        for (linha = 0; linha < tamanho; linha++) // passa por todas as linhas do tabuleiro
        {
            for (coluna = 0; coluna < tamanho; coluna++) // passa por todas as colunas do tabuleiro
            {
                if ((tabuleiro + linha*tamanho + coluna)->valor == 0) // se o valor da pe�a nessa linha e coluna for
                                                                      // igual a 0
                    disponivel = 0; // define disponivel como 0, retornando para o loop e procurando a casa dispon�vel
                                    // para inserir 2 ou 4
            }
        }
    }
}
