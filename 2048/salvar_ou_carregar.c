#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "imprime_tabuleiro.h"

// fun��o para salvar o jogo atual ou carregar um jogo salvo
// recebe como par�metros:
// vari�vel opcao, indica se vamos salvar ou carregar
// vari�vel inicio, indica se estamos vindo da fun��o principal ou n�o
// ponteiro tabuleiro do tipo peca, � o tabuleiro do jogo
// ponteiro score do tipo long int, � o score do jogo
// ponteiro movimentos do tipo long int, � os movimentos do jogo
int salvar_ou_carregar(int opcao, int inicio, peca *tabuleiro, long int *score, long int *movimentos) {
    char bin[] = ".bin"; // extens�o do arquivo a ser salvo (arquivo bin�rio)
    char nome_arq[15]; // vari�vel que representa o nome do arquivo
    NORMALIZA; // normaliza as configura��es e limpa a tela

    if(opcao == 1) { // se a op��o for 1, ou seja, salvar
        printf("Informe o nome do arquivo a ser salvo (ate 10 caracteres): "); // pede o nome do arquivo para o usu�rio
        fgets(nome_arq, 15, stdin); // salva o nome na vari�vel nome_arq
        nome_arq[strlen(nome_arq)-1] = '\0'; // limpa o enter no fim da string nome_arq
        strcat(nome_arq, bin); // concatena a extens�o bin para o fim de nome_arq
        FILE *arquivo = fopen(nome_arq, "w"); // abre o arquivo com o nome_arq em modo escrita
        if(arquivo) { // se foi poss�vel abrir
            fwrite(score, sizeof(long), 1, arquivo); // escreve o score no arquivo
            fwrite(movimentos, sizeof(long int), 1, arquivo); // escreve os movimentos no arquivo
            fwrite(tabuleiro, sizeof(peca), 16, arquivo); // escreve as pe�as no arquivo
            fclose(arquivo); // fecha o arquivo
            printf("Jogo salvo com sucesso."); // imprime uma mensagem de sucesso
            Sleep(3000); // d� um delay de 3 segundos
            clrscr(); // limpa a tela
            imprime_tabuleiro(); // imprime o tabuleiro
            return; // retorna para a fun��o
        } else { // se n�o
            printf("Nao foi possivel salvar o jogo."); // imprime uma mensagem de erro
            Sleep(3000); // d� um delay de 3 segundos
            clrscr(); // limpa a tela
            imprime_tabuleiro(); // imprime o tabuleiro
            return; // retorna para a fun��o
        }
    } else { // se n�o (op��o for 0), ou seja, carregar
        printf("Informe o nome do arquivo a ser carregado: "); // pede o nome do arquivo a ser carregado
        fgets(nome_arq, 15, stdin); // salva o nome na vari�vel nome_arq
        nome_arq[strlen(nome_arq)-1] = '\0'; // limpa o enter no fim da string nome_arq
        strcat(nome_arq, bin); // concatena a extens�o bin para o fim de nome_arq
        FILE *arquivo = fopen(nome_arq, "r"); // abre o arquivo com o nome_arq em modo leitura
        if(arquivo) { // se foi poss�vel abrir
            fread(score, sizeof(long), 1, arquivo); // l� o score no arquivo
            fread(movimentos, sizeof(long int), 1, arquivo); // l� os movimentos no arquivo
            fread(tabuleiro, sizeof(peca), 16, arquivo); // l� o tabuleiro no arquivo
            fclose(arquivo); // fecha o arquivo
            clrscr(); // limpa a tela
            imprime_tabuleiro(); // imprime o tabuleiro
            return 1; // retorna 1, indicando que deu tudo certo
        } else { // se n�o
            printf("Nao ha nenhum jogo salvo com esse nome."); // imprime uma mensagem de erro
            Sleep(3000); // d� um delay de 3 segundos
            clrscr(); // limpa a tela
            if(inicio == 1) return 0; // se viemos da fun��o principal para essa fun��o, retorna 0
            else imprime_tabuleiro(); // se n�o, imprime o tabuleiro
            return 0; // retorna 0
        }
    }
}
