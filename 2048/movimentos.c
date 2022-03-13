#include "main.h"
#include "cores.h"

// função para indicar se é possível o movimento para cima
// recebe como parâmetro:
// o ponteiro tabuleiro do tipo peca
// a variável int tamanho do tabuleiro
// o ponteiro score do tipo int
// o ponteiro resultado do tipo int
// a peca zero
int pode_cima(peca *tabuleiro, int tamanho, int *score, int *resultado, peca zero) {
    int linha, coluna, flag, linha_aux, moveu = 0; // define as variáveis de controle da matriz linha e coluna
    // define a variável flag que serve para que os números não sejam somados em sequência
    // define a variável linha_aux que serve para não alterarmos a variável linha dentro do loop
    // define a variável moveu para indicar se houve movimentação
    for (coluna = 0; coluna < tamanho; coluna++) // percorre todas as colunas da matriz
    {
        flag = 0; // inicia flag igual a 0
        for (linha = 1; linha < tamanho; linha++) // percorre todas as linhas da matriz (começa na linha 1 porque se fosse na 0
                                                  // não poderia se mover para cima)
        {
            if ((tabuleiro + linha*tamanho + coluna)->valor != 0) // se o valor da peça na posição linha e coluna da matriz
                                                                  // for diferente de 0
            {
                linha_aux = linha; // salva a linha em linha_aux
                for (linha_aux; linha_aux > flag; linha_aux--) // percorre todas as linhas possíveis de se mover na matriz,
                                                               // de baixo para cima, sem considerar a linha 0 (salva em flag)
                {
                    if ((tabuleiro + (linha_aux-1)*tamanho + coluna)->valor == 0) // se o valor na posição acima de linha_aux
                                                                                  // for igual a 0
                    {
                        // define o valor nessa posição como o valor da peça em linha_aux
                        *(tabuleiro + (linha_aux-1)*tamanho + coluna) = *(tabuleiro + linha_aux*tamanho + coluna);
                        // define a peça em linha_aux como zero
                        *(tabuleiro + linha_aux*tamanho + coluna) = zero;
                        moveu = 1; // seta a flag de movimento para 1
                    }
                    else if ((tabuleiro + (linha_aux-1)*tamanho + coluna)->valor ==
                             (tabuleiro + linha_aux*tamanho + coluna)->valor) // se o valor na posição acima de linha_aux
                                                                              // for igual ao em linha_aux
                    {
                        // soma esses dois valores e salva na posição acima de linha_aux
                        (tabuleiro + (linha_aux-1)*tamanho + coluna)->valor =
                        ((tabuleiro + (linha_aux-1)*tamanho + coluna)->valor)*2; // como são valores iguais, a soma é equivalente
                                                                                 // a multiplicar por dois

                        // define a cor nessa posição de acordo com a função cores, passando o valor da peça como parâmetro
                        (tabuleiro + (linha_aux-1)*tamanho + coluna)->cor =
                        cores((tabuleiro + (linha_aux-1)*tamanho + coluna)->valor);

                        // define a peça em linha_aux como zero
                        *(tabuleiro + linha_aux*tamanho + coluna) = zero;
                        // soma o valor da peça acima de linha_aux ao score
                        *score += (tabuleiro + (linha_aux-1)*tamanho + coluna)->valor;
                        // define resultado como o valor da peça acima de linha_aux
                        *resultado = (tabuleiro + (linha_aux-1)*tamanho + coluna)->valor;
                        // seta a flag de movimentação para 1
                        moveu = 1;
                        flag = linha_aux; // define flag como linha_aux para impedir que seja realizada outra soma nessa posição
                    }
                }
            }
        }
    }
    if (moveu == 1) // se a flag de movimentação for igual a 1
        return 1; // retorna 1 pois ocorreu movimentação
    else // se não
        return 0; // retorna 0 pois não houve movimentação
}

// função para indicar se é possível o movimento para baixo
// recebe como parâmetro:
// o ponteiro tabuleiro do tipo peca
// a variável int tamanho do tabuleiro
// o ponteiro score do tipo int
// o ponteiro resultado do tipo int
// a peca zero
int pode_baixo(peca *tabuleiro, int tamanho, int *score, int *resultado, peca zero) {
    int linha, coluna, flag, linha_aux, moveu = 0; // define as variáveis de controle da matriz linha e coluna
    // define a variável flag que serve para que os números não sejam somados em sequência
    // define a variável linha_aux que serve para não alterarmos a variável linha dentro do loop
    // define a variável moveu para indicar se houve movimentação
    for (coluna = 0; coluna < tamanho; coluna++) // percorre todas as colunas da matriz
    {
        flag = (tamanho - 1); // define a flag como tamanho-1, representando a linha 3 (valor máximo)
        for (linha = (tamanho-2); linha >= 0; linha--) // percorre todas as linhas da matriz (começa na linha 2 porque se fosse
        {                                              // na 3 não poderia se mover para baixo)
            if ((tabuleiro + linha*tamanho + coluna)->valor != 0) // se o valor da peça na posição linha e coluna da matriz
                                                                  // for diferente de 0
            {
                linha_aux = linha; // salva a linha em linha_aux
                for (linha_aux; linha_aux < flag; linha_aux++) // percorre todas as linhas possíveis de se mover na matriz,
                                                               // de cima para baixo, sem considerar a linha 3 (salva em flag)
                {
                    if ((tabuleiro + (linha_aux+1)*tamanho + coluna)->valor == 0) // se o valor na posição abaixo de linha_aux
                                                                                  // for igual a 0
                    {
                        // define o valor nessa posição como o valor da peça em linha_aux
                        *(tabuleiro + (linha_aux+1)*tamanho + coluna) = *(tabuleiro + linha_aux*tamanho + coluna);
                        // define a peça em linha_aux como zero
                        *(tabuleiro + linha_aux*tamanho + coluna) = zero;
                        moveu = 1; // seta a flag de movimento para 1
                    }
                    else if ((tabuleiro + (linha_aux+1)*tamanho + coluna)->valor ==
                             (tabuleiro + linha_aux*tamanho + coluna)->valor ) // se o valor na posição abaixo de linha_aux
                                                                               // for igual ao em linha_aux
                    {
                        // soma esses dois valores e salva na posição abaixo de linha_aux
                        (tabuleiro + (linha_aux+1)*tamanho + coluna)->valor =
                        ((tabuleiro + (linha_aux+1)*tamanho + coluna)->valor)*2; // como são valores iguais, a soma é equivalente
                                                                                 // a multiplicar por dois

                        // define a cor nessa posição de acordo com a função cores, passando o valor da peça como parâmetro
                        (tabuleiro + (linha_aux+1)*tamanho + coluna)->cor =
                        cores((tabuleiro + (linha_aux+1)*tamanho + coluna)->valor);

                        // define a peça em linha_aux como zero
                        *(tabuleiro + linha_aux*tamanho + coluna) = zero;
                        // soma o valor da peça abaixo de linha_aux ao score
                        *score += (tabuleiro + (linha_aux+1)*tamanho + coluna)->valor;
                        // define resultado como o valor da peça abaixo de linha_aux
                        *resultado = (tabuleiro + (linha_aux+1)*tamanho + coluna)->valor;
                        // seta a flag de movimentação para 1
                        moveu = 1;
                        flag = linha_aux; // define flag como linha_aux para impedir que seja realizada outra soma nessa posição
                    }
                }
            }
        }
    }
    if (moveu == 1) // se a flag de movimentação for igual a 1
        return 1; // retorna 1 pois ocorreu movimentação
    else // se não
        return 0; // retorna 0 pois não houve movimentação
}

// função para indicar se é possível o movimento para esquerda
// recebe como parâmetro:
// o ponteiro tabuleiro do tipo peca
// a variável int tamanho do tabuleiro
// o ponteiro score do tipo int
// o ponteiro resultado do tipo int
// a peca zero
int pode_esquerda(peca *tabuleiro, int tamanho, int *score, int *resultado, peca zero) {
    int linha, coluna, flag, coluna_aux, moveu = 0; // define as variáveis de controle da matriz linha e coluna
    // define a variável flag que serve para que os números não sejam somados em sequência
    // define a variável coluna_aux que serve para não alterarmos a variável coluna dentro do loop
    // define a variável moveu para indicar se houve movimentação
    for (linha = 0; linha < tamanho; linha++) // percorre todas as linhas da matriz
    {
        flag = 0; // inicia flag igual a 0
        for (coluna = 1; coluna < tamanho; coluna++) // percorre todas as colunas da matriz (começa na coluna 1 porque se fosse
                                                     // na 0 não poderia se mover para esquerda)
        {
            if ((tabuleiro + linha*tamanho + coluna)->valor != 0) // se o valor da peça na posição linha e coluna da matriz
                                                                  // for diferente de 0
            {
                coluna_aux = coluna; // salva a coluna em coluna_aux
                for (coluna_aux; coluna_aux > flag; coluna_aux--) // percorre todas as colunas possíveis de se mover na matriz,
                                                                  // da direita para esquerda, sem considerar a coluna 0 (salva
                                                                  // em flag)
                {
                    if ((tabuleiro + linha*tamanho + coluna_aux-1)->valor == 0) // se o valor na posição a esquerda de coluna_aux
                                                                                // for igual a 0
                    {
                        // define o valor nessa posição como o valor da peça em coluna_aux
                        *(tabuleiro + linha*tamanho + coluna_aux-1) = *(tabuleiro + linha*tamanho + coluna_aux);
                        // define a peça em coluna_aux como zero
                        *(tabuleiro + linha*tamanho + coluna_aux) = zero;
                        moveu = 1; // seta a flag de movimento para 1
                    }
                    else if ((tabuleiro + linha*tamanho + coluna_aux-1)->valor ==
                             (tabuleiro + linha*tamanho + coluna_aux)->valor) // se o valor na posição a esquerda de coluna_aux
                                                                              // for igual ao em coluna_aux
                    {
                        // soma esses dois valores e salva na posição a esquerda de coluna_aux
                        (tabuleiro + linha*tamanho + coluna_aux-1)->valor =
                        ((tabuleiro + linha*tamanho + coluna_aux-1)->valor)*2; // como são valores iguais, a soma é equivalente
                                                                               // a multiplicar por dois

                        // define a cor nessa posição de acordo com a função cores, passando o valor da peça como parâmetro
                        (tabuleiro + linha*tamanho + coluna_aux-1)->cor =
                        cores((tabuleiro + linha*tamanho + coluna_aux-1)->valor);

                        // define a peça em coluna_aux como zero
                        *(tabuleiro + linha*tamanho + coluna_aux) = zero;
                        // soma o valor da peça a esquerda de coluna_aux ao score
                        *score += (tabuleiro + linha*tamanho + coluna_aux-1)->valor;
                        // define resultado como o valor da peça a esquerda de coluna_aux
                        *resultado = (tabuleiro + linha*tamanho + coluna_aux-1)->valor;
                        // seta a flag de movimentação para 1
                        moveu = 1;
                        flag = coluna_aux; // define flag como coluna_aux para impedir que seja realizada outra soma nessa
                                           // posição
                    }
                }
            }
        }
    }
    if (moveu == 1) // se a flag de movimentação for igual a 1
        return 1; // retorna 1 pois ocorreu movimentação
    else // se não
        return 0; // retorna 0 pois não houve movimentação
}

// função para indicar se é possível o movimento para direita
// recebe como parâmetro:
// o ponteiro tabuleiro do tipo peca
// a variável int tamanho do tabuleiro
// o ponteiro score do tipo int
// o ponteiro resultado do tipo int
// a peca zero
int pode_direita(peca *tabuleiro, int tamanho, int *score, int *resultado, peca zero) {
    int linha, coluna, flag, coluna_aux, moveu = 0; // define as variáveis de controle da matriz linha e coluna
    // define a variável flag que serve para que os números não sejam somados em sequência
    // define a variável coluna_aux que serve para não alterarmos a variável coluna dentro do loop
    // define a variável moveu para indicar se houve movimentação
    for (linha = 0; linha < tamanho; linha++) // percorre todas as linhas da matriz
    {
        flag = (tamanho - 1); // define a flag como tamanho-1, representando a coluna 3 (valor máximo)
        for (coluna = (tamanho-2); coluna >= 0; coluna--) // percorre todas as colunas da matriz (começa na coluna 2 porque se
                                                          // fosse na 3 não poderia se mover para direita)

        {
            if ((tabuleiro + linha*tamanho + coluna)->valor != 0) // se o valor da peça na posição linha e coluna da matriz
                                                                  // for diferente de 0
            {
                coluna_aux = coluna; // salva a coluna em coluna_aux
                for (coluna_aux; coluna_aux < flag; coluna_aux++) // percorre todas as colunas possíveis de se mover na matriz,
                                                                  // da esquerda para direita, sem considerar a coluna 3
                                                                  // (salva em flag)
                {
                    if ((tabuleiro + linha*tamanho + coluna_aux+1)->valor == 0) // se o valor na posição a direita de coluna_aux
                                                                                // for igual a 0
                    {
                        // define o valor nessa posição como o valor da peça em coluna_aux
                        *(tabuleiro + linha*tamanho + coluna_aux+1) = *(tabuleiro + linha*tamanho + coluna_aux);
                        // define a peça em coluna_aux como zero
                        *(tabuleiro + linha*tamanho + coluna_aux) = zero;
                        moveu = 1; // seta a flag de movimento para 1
                    }
                    else if ((tabuleiro + linha*tamanho + coluna_aux+1)->valor ==
                             (tabuleiro + linha*tamanho + coluna_aux)->valor) // se o valor na posição a direita de coluna_aux
                                                                              // for igual ao em coluna_aux
                    {
                        // soma esses dois valores e salva na posição a direita de coluna_aux
                        (tabuleiro + linha*tamanho + coluna_aux+1)->valor =
                        ((tabuleiro + linha*tamanho + coluna_aux+1)->valor)*2; // como são valores iguais, a soma é equivalente
                                                                               // a multiplicar por dois

                        // define a cor nessa posição de acordo com a função cores, passando o valor da peça como parâmetro
                        (tabuleiro + linha*tamanho + coluna_aux+1)->cor =
                        cores((tabuleiro + linha*tamanho + coluna_aux+1)->valor);

                         // define a peça em coluna_aux como zero
                        *(tabuleiro + linha*tamanho + coluna_aux) = zero;
                        // soma o valor da peça a direita de coluna_aux ao score
                        *score += (tabuleiro + linha*tamanho + coluna_aux+1)->valor;
                        // define resultado como o valor da peça a direita de coluna_aux
                        *resultado = (tabuleiro + linha*tamanho + coluna_aux+1)->valor;
                        // seta a flag de movimentação para 1
                        moveu = 1;
                        flag = coluna_aux; // define flag como coluna_aux para impedir que seja realizada outra soma nessa
                                           // posição
                    }
                }
            }
        }
    }
    if (moveu == 1) // se a flag de movimentação for igual a 1
        return 1; // retorna 1 pois ocorreu movimentação
    else // se não
        return 0; // retorna 0 pois não houve movimentação
}
