#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <conio2.h>
#define CHAR_N 'n'
#define CHAR_C 'c'
#define CHAR_S 's'
#define ESC 27
#define OBJETIVO 2048
#define CIMA 72
#define BAIXO 80
#define ESQ 75
#define DIR 77
#define TAM_RANKING 10
#define SET_COLORS(X,Y) textbackground(X);textcolor(Y);
#define NORMALIZA normvideo();clrscr();

int main();
typedef struct { // defini��o de estrutura do tipo Pe�a
    int valor; // valor da pe�a, tipo int
    COLORS cor; // cor da pe�a, tipo COLORS
} peca;

typedef struct jogador //define uma estrutura jogador
{
    char nome[10]; //estrutura jogador recebe um nome com at� 10 caracteres, \0 incluso
    long int score; //estrutura jogador recebe um inteiro referente ao score
} jogador_t;

#endif // MAIN_H_INCLUDED
