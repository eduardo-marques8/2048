#include "main.h"
#include <conio2.h>
#include <conio.h>
#include <time.h>
#include "imprime_tabuleiro.h"
#include "cores.h"

// função para gerar a peça 2 inicial no tabuleiro
void gera2(peca *tabuleiro, int tamanho, peca zero) { // recebe como parâmetros o ponteiro tabuleiro, a variável int
                                                      // tamanho e a peça neutra zero
    int flag, linha, coluna; // define a variável auxiliar de flag e as variáveis de controle da matriz linha e coluna
    flag = 0; // define flag como zero
    srand(time(NULL)); // gera uma semente para a função utilizando o tempo atual. necessária para gerar números novos a cada
                       // execução
    while (flag == 0) // enquanto flag for igual a 0
    {
        flag = 1; // define flag como 1
        linha = rand()%tamanho; // sorteia uma linha aleatória entre 0 e 3 (tamanho - 1)
        coluna = rand()%tamanho; // sorteia uma coluna aleatória entre 0 e 3 (tamanho - 1)
        if ((tabuleiro + linha*tamanho + coluna)->valor == 0) // se o valor da peça nessa linha e coluna for igual a 0
        {
            (tabuleiro + linha*tamanho + coluna)->valor = 2; // o valor dessa peça vai se tornar 2
            // a cor dessa peça vai ser definida de acordo com seu valor passado para a função cores
            (tabuleiro + linha*tamanho + coluna)->cor = cores((tabuleiro + linha*tamanho + coluna)->valor);
            return; // retorna para novo_jogo
        }
        // se o espaço sorteado não for vazio
        // verifica se há outro espaço disponível no tabuleiro
        for (linha = 0; linha < tamanho; linha++) // passa por todas as linhas do tabuleiro
        {
            for (coluna = 0; coluna < tamanho; coluna++) // passa por todas as colunas do tabuleiro
            {
                if ((tabuleiro + linha*tamanho + coluna)->valor == 0) // se o valor da peça nessa linha e coluna for
                                                                      // igual a 0
                    flag = 0; // flag se torna 0
            }
        }
    }
}

// função que gera a peça 2 ou 4 no tabuleiro
void gera2ou4(peca *tabuleiro, int tamanho) { // recebe como parâmetros o ponteiro tabuleiro e a variável int tamanho
    int disponivel, linha, coluna, probabilidade; // define as variáveis
                                                  // disponivel = para checar se existe pelo menos uma posição disponível
                                                  // para colocar um dois ou um quatro
                                                  // linha, coluna = variáveis de controle da matriz
                                                  // probabilidade = probabilidade da peça ser 2 ou 4
    disponivel = 0; // define disponivel como 0
    while (!disponivel) // enquanto não estiver disponível
    {
        disponivel = 1; // disponivel igual a 1
        linha = rand()%tamanho; // sorteia uma linha aleatória entre 0 e 3 (tamanho - 1)
        coluna = rand()%tamanho; // sorteia uma coluna aleatória entre 0 e 3 (tamanho - 1)
        if ((tabuleiro + linha*tamanho + coluna)->valor == 0) // se o valor da peça na linha e coluna sorteadas for
                                                              // igual a 0
        {
            probabilidade = rand()%10; // define o valor de probabilidade, sendo 10% oara 4 e 90% para 2
            if (probabilidade >= 1) { // se a probabilidade for maior ou igual a 1
                (tabuleiro + linha*tamanho + coluna)->valor = 2; // define o valor dessa peça como 2
                // a cor dessa peça vai ser definida de acordo com seu valor passado para a função cores
                (tabuleiro + linha*tamanho + coluna)->cor = cores((tabuleiro + linha*tamanho + coluna)->valor);
            } else { // se não
                (tabuleiro + linha*tamanho + coluna)->valor = 4; // define o valor dessa peça como 4
                // a cor dessa peça vai ser definida de acordo com seu valor passado para a função cores
                (tabuleiro + linha*tamanho + coluna)->cor = cores((tabuleiro + linha*tamanho + coluna)->valor);
            }
            return 0; // sai da função após colocar a peça na casa disponível
        }
        // se o espaço sorteado não for vazio
        // verifica se há algum espaço disponível no tabuleiro
        for (linha = 0; linha < tamanho; linha++) // passa por todas as linhas do tabuleiro
        {
            for (coluna = 0; coluna < tamanho; coluna++) // passa por todas as colunas do tabuleiro
            {
                if ((tabuleiro + linha*tamanho + coluna)->valor == 0) // se o valor da peça nessa linha e coluna for
                                                                      // igual a 0
                    disponivel = 0; // define disponivel como 0, retornando para o loop e procurando a casa disponível
                                    // para inserir 2 ou 4
            }
        }
    }
}
