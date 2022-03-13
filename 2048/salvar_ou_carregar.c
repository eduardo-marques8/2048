#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "imprime_tabuleiro.h"

// função para salvar o jogo atual ou carregar um jogo salvo
// recebe como parâmetros:
// variável opcao, indica se vamos salvar ou carregar
// variável inicio, indica se estamos vindo da função principal ou não
// ponteiro tabuleiro do tipo peca, é o tabuleiro do jogo
// ponteiro score do tipo long int, é o score do jogo
// ponteiro movimentos do tipo long int, é os movimentos do jogo
int salvar_ou_carregar(int opcao, int inicio, peca *tabuleiro, long int *score, long int *movimentos) {
    char bin[] = ".bin"; // extensão do arquivo a ser salvo (arquivo binário)
    char nome_arq[15]; // variável que representa o nome do arquivo
    NORMALIZA; // normaliza as configurações e limpa a tela

    if(opcao == 1) { // se a opção for 1, ou seja, salvar
        printf("Informe o nome do arquivo a ser salvo (ate 10 caracteres): "); // pede o nome do arquivo para o usuário
        fgets(nome_arq, 15, stdin); // salva o nome na variável nome_arq
        nome_arq[strlen(nome_arq)-1] = '\0'; // limpa o enter no fim da string nome_arq
        strcat(nome_arq, bin); // concatena a extensão bin para o fim de nome_arq
        FILE *arquivo = fopen(nome_arq, "w"); // abre o arquivo com o nome_arq em modo escrita
        if(arquivo) { // se foi possível abrir
            fwrite(score, sizeof(long), 1, arquivo); // escreve o score no arquivo
            fwrite(movimentos, sizeof(long int), 1, arquivo); // escreve os movimentos no arquivo
            fwrite(tabuleiro, sizeof(peca), 16, arquivo); // escreve as peças no arquivo
            fclose(arquivo); // fecha o arquivo
            printf("Jogo salvo com sucesso."); // imprime uma mensagem de sucesso
            Sleep(3000); // dá um delay de 3 segundos
            clrscr(); // limpa a tela
            imprime_tabuleiro(); // imprime o tabuleiro
            return; // retorna para a função
        } else { // se não
            printf("Nao foi possivel salvar o jogo."); // imprime uma mensagem de erro
            Sleep(3000); // dá um delay de 3 segundos
            clrscr(); // limpa a tela
            imprime_tabuleiro(); // imprime o tabuleiro
            return; // retorna para a função
        }
    } else { // se não (opção for 0), ou seja, carregar
        printf("Informe o nome do arquivo a ser carregado: "); // pede o nome do arquivo a ser carregado
        fgets(nome_arq, 15, stdin); // salva o nome na variável nome_arq
        nome_arq[strlen(nome_arq)-1] = '\0'; // limpa o enter no fim da string nome_arq
        strcat(nome_arq, bin); // concatena a extensão bin para o fim de nome_arq
        FILE *arquivo = fopen(nome_arq, "r"); // abre o arquivo com o nome_arq em modo leitura
        if(arquivo) { // se foi possível abrir
            fread(score, sizeof(long), 1, arquivo); // lê o score no arquivo
            fread(movimentos, sizeof(long int), 1, arquivo); // lê os movimentos no arquivo
            fread(tabuleiro, sizeof(peca), 16, arquivo); // lê o tabuleiro no arquivo
            fclose(arquivo); // fecha o arquivo
            clrscr(); // limpa a tela
            imprime_tabuleiro(); // imprime o tabuleiro
            return 1; // retorna 1, indicando que deu tudo certo
        } else { // se não
            printf("Nao ha nenhum jogo salvo com esse nome."); // imprime uma mensagem de erro
            Sleep(3000); // dá um delay de 3 segundos
            clrscr(); // limpa a tela
            if(inicio == 1) return 0; // se viemos da função principal para essa função, retorna 0
            else imprime_tabuleiro(); // se não, imprime o tabuleiro
            return 0; // retorna 0
        }
    }
}
