#include "main.h"
#include <conio2.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fun��o que imprime o tabuleiro do jogo
void imprime_tabuleiro (long int score) { // recebe como par�metro a vari�vel score
//BACKGROUND DO TABULEIRO
  SET_COLORS(YELLOW,BLACK); // pinta o fundo do tabuleiro de amarelo e pinta a cor do texto de preto
  int i, c; // vari�veis de controle das coordenadas x e y da tela

  for (i = 2; i < 5; i = i + 2){ // percorre o eixo y de 2 at� 5 com y incrementando 2
    for(c = 1; c < 58; c++){ // percorre o eixo x de 1 at� 58 com x incrementando 1
        gotoxy(c,i); // vai para a coordenada (c,i)
        printf("*");}} // printa asterisco na coordenada
//NOME DO JOGO EM CIMA DO TABULEIRO
  textcolor(BLACK); // pinta a cor do texto de preto
  gotoxy(1,3); // vai para a coordenada (1,3)
  printf("**************************    ***************************"); // printa uma linha de asteriscos com espa�o para o
                                                                       // nome do jogo
  textcolor(RED); // pinta a cor do texto de vermelho
  gotoxy(27,3); // vai para a posi��o (27,3)
  printf("2048"); // printa 2048
  printf("\n\n"); // printa duas novas linhas
  textcolor(BLACK); // pinta a cor do texto de preto
  // imprime a estrutura do tabuleiro
  printf("+-------------+-------------+-------------+-------------+\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("+-------------+-------------+-------------+-------------+\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("+-------------+-------------+-------------+-------------+\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("+-------------+-------------+-------------+-------------+\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("|             |             |             |             |\n");
  printf("+-------------+-------------+-------------+-------------+\n");

/*TABELA SCORE*/
textbackground(DARKGRAY); // pinta o fundo do texto de cinza-escuro
for (i = 4; i < 6; i++){ // percorre o eixo y de 4 at� 6 com y incrementando 1
    for(c = 72; c < 84; c++){ // percorre o eixo x de 72 at� 84 com x incrementando 1
        gotoxy(c,i); // vai para a coordenada (c,i)
        printf(" "); // printa um espa�o em branco na coordenada

    }
}
SET_COLORS(LIGHTGRAY,RED); // pinta o fundo do texto de cinza-claro e pinta a cor do texto de vermelho
gotoxy(72,3); // vai para a coordenada (72,3)
printf("   SCORE:   "); // imprime SCORE na tela


/*TABELA MOVIMENTOS*/
textbackground(DARKGRAY); // pinta o fundo do texto de cinza-escuro
for (i = 4; i < 6; i++){ // percorre o eixo y de 4 at� 6 com y incrementando 1
    for(c = 86; c < 98; c++){ // percorre o eixo x de 86 at� 98 com x incrementando 1
        gotoxy(c,i); // vai para a coordenada (c,i)
         printf(" "); // printa um espa�o em branco na coordenada
        }
}
SET_COLORS(LIGHTGRAY,RED); // pinta o fundo do texto de cinza-claro e pinta a cor do texto de vermelho
gotoxy(86,3); // vai para a coordenada (86,3)
printf(" MOVIMENTOS:"); // imprime MOVIMENTOS na tela

imprime_ranking();

/*Lista de comandos*/
SET_COLORS(BLACK,LIGHTGRAY); // pinta o fundo do texto de cinza-claro e pinta a cor do texto de vermelho
gotoxy(72,23); // vai para a coordenada (72,23)
printf("ESC - Sair"); // imprime a instru��o de sa�da do jogo
gotoxy(72,24); // vai para a coordenada (72,24)
printf("N - Novo Jogo"); // imprime a instru��o de criar um novo jogo
gotoxy(72,25); // vai para a coordenada (72,25)
printf("C - Carregar um Jogo"); // imprime a instru��o de carregar um jogo salvo
gotoxy(72,26); // vai para a coordenada (72,26)
printf("S - Salvar o Jogo"); // imprime a instru��o de salvar o jogo atual
gotoxy(72,27); // vai para a coordenada (72,27)
printf("Setas - Jogar"); // imprime a instru��o de movimenta��o

}

// fun��o para imprimir os n�meros na tela
void imprime_numeros(peca *tabuleiro) { // recebe como par�metro o ponteiro tabuleiro
    int linha, coluna, x, y; // define as vari�veis de controle da matriz linha e coluna e as vari�veis de coordenada x e y
    textbackground(YELLOW); // pinta o fundo do texto de amarelo
    for (linha = 0, y = 8; linha < 4; linha++, y += 7) // percorre as linhas da matriz e as coordenadas de y. y come�a em 8,
                                                       // no in�cio do tabuleiro, e � incrementado de 7 em 7 posi��es
    {
        for (coluna = 0, x = 8; coluna < 4; coluna++, x += 14) // percorre as colunas da matriz e as coordenadas de x. x come�a
                                                               // em 8, no in�cio do tabuleiro, e � incrementado de 14 em 14
                                                               // posi��es
        {
            gotoxy (x, y); // vai para a posi��o (x,y)
            textcolor((tabuleiro + linha*4 + coluna)->cor); // pinta a cor do texto com a cor da pe�a na linha e coluna
            printf ("%4d", (tabuleiro + linha*4 + coluna)->valor); // imprime o valor da pe�a na linha e coluna.
                                                                   // imprime com 4 d�gitos para n�o gerar conflito de espa�o
        }
    }
}

// fun��o para imprimir a pontua��o
void imprime_score(long int score) { // recebe como par�metro a vari�vel long int score

    textcolor(MAGENTA); // pinta a cor do texto de magenta
    gotoxy(72,4); // vai para a coordenada (72,4)
    printf(" %ld ", score); // imprime a long int score

}

// fun��o para imprimir os movimentos
void imprime_movimentos(long int movimentos) { // recebe como par�metro a long int movimentos

    textcolor(MAGENTA); // pinta a cor do texto de magenta
    gotoxy(86,4); // vai para a posi��o (86,4)
    printf(" %ld ", movimentos); // imprime a long int movimentos

}

// fun��o para imprimir o ranking
void imprime_ranking() {
    int i = 0, c = 0;
    /*TABELA RANKING*/
    textbackground(DARKGRAY); // pinta o fundo do texto de cinza-escuro
    for (i = 8; i < 19; i++){ // percorre o eixo y de 8 at� 21 com y incrementando 1
        for(c = 72; c < 98; c++){ // percorre o eixo x de 72 at� 98 com x incrementando 1
            gotoxy(c,i); // vai para a coordenada (c,i)
            printf(" "); // printa um espa�o em branco na coordenada
    }
    }

    textcolor(BLACK); // pinta a cor do texto de preto
    jogador_t jogador[10]; //declara um vetor do tipo jogador_t com 10 posi�oes
    char str[10]; //declara um vetor string com 10 posi��es
    char numero[10]; //declara um vetor string com 10 posi��es



    FILE *f = fopen("ranking.txt", "rb"); //abre o arquivo ranking.txt para leitura
    for (i = 9; i < 19; i++){ // percorre o eixo y de 9 at� 14 com y incrementando 1
    c = 72; // seta sempre na posi��o 72 do eixo x
    gotoxy(c,i); // vai para a coordenada (c,i)
    fscanf(f, "%s", &str); //faz a leitura do nome do jogador e armazena em str
    if(strcmp(str, "teste") == 0) break; // se str for igual a "teste" (ou seja, posi��o vazia) quebra o la�o for
    strcpy(jogador[i-9].nome,str); //passa o nome armazenado para o nome do jogador na posi��o i-9
    fscanf(f, "%s", &numero); //faz a leitura do score do jogador e armazena em numero
    jogador[i-9].score = atol(numero); //transforma a string em inteiro longo e passa o numero armazenado para o score do
                                       // jogador na posi��o i-9
    printf("%s", jogador[i-9].nome); //printa o nome do jogador i-9 na posi��o (c,i)
    c = 84; // seta sempre na posi��o 84 do eixo x
    gotoxy(c,i); // vai para a coordenada (c,i)
    printf("%d", jogador[i-9].score); //printa o score do jogador i-9 na posi��o (c,i)
    if(feof(f) != 0) break; // se chegou no fim do arquivo, quebra o la�o for
    }

    fclose(f); // fecha o arquivo f

    SET_COLORS(LIGHTGRAY,RED); // pinta o fundo do texto de cinza-claro e pinta a cor do texto de vermelho
    gotoxy(72,8); // vai para a coordenada (72,8)
    printf("         RANKING:         "); // imprime RANKING na tela
}
