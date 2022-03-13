#include "main.h"
#include "cores.h"

// fun��o para indicar se � poss�vel o movimento para cima
// recebe como par�metro:
// o ponteiro tabuleiro do tipo peca
// a vari�vel int tamanho do tabuleiro
// o ponteiro score do tipo int
// o ponteiro resultado do tipo int
// a peca zero
int pode_cima(peca *tabuleiro, int tamanho, int *score, int *resultado, peca zero) {
    int linha, coluna, flag, linha_aux, moveu = 0; // define as vari�veis de controle da matriz linha e coluna
    // define a vari�vel flag que serve para que os n�meros n�o sejam somados em sequ�ncia
    // define a vari�vel linha_aux que serve para n�o alterarmos a vari�vel linha dentro do loop
    // define a vari�vel moveu para indicar se houve movimenta��o
    for (coluna = 0; coluna < tamanho; coluna++) // percorre todas as colunas da matriz
    {
        flag = 0; // inicia flag igual a 0
        for (linha = 1; linha < tamanho; linha++) // percorre todas as linhas da matriz (come�a na linha 1 porque se fosse na 0
                                                  // n�o poderia se mover para cima)
        {
            if ((tabuleiro + linha*tamanho + coluna)->valor != 0) // se o valor da pe�a na posi��o linha e coluna da matriz
                                                                  // for diferente de 0
            {
                linha_aux = linha; // salva a linha em linha_aux
                for (linha_aux; linha_aux > flag; linha_aux--) // percorre todas as linhas poss�veis de se mover na matriz,
                                                               // de baixo para cima, sem considerar a linha 0 (salva em flag)
                {
                    if ((tabuleiro + (linha_aux-1)*tamanho + coluna)->valor == 0) // se o valor na posi��o acima de linha_aux
                                                                                  // for igual a 0
                    {
                        // define o valor nessa posi��o como o valor da pe�a em linha_aux
                        *(tabuleiro + (linha_aux-1)*tamanho + coluna) = *(tabuleiro + linha_aux*tamanho + coluna);
                        // define a pe�a em linha_aux como zero
                        *(tabuleiro + linha_aux*tamanho + coluna) = zero;
                        moveu = 1; // seta a flag de movimento para 1
                    }
                    else if ((tabuleiro + (linha_aux-1)*tamanho + coluna)->valor ==
                             (tabuleiro + linha_aux*tamanho + coluna)->valor) // se o valor na posi��o acima de linha_aux
                                                                              // for igual ao em linha_aux
                    {
                        // soma esses dois valores e salva na posi��o acima de linha_aux
                        (tabuleiro + (linha_aux-1)*tamanho + coluna)->valor =
                        ((tabuleiro + (linha_aux-1)*tamanho + coluna)->valor)*2; // como s�o valores iguais, a soma � equivalente
                                                                                 // a multiplicar por dois

                        // define a cor nessa posi��o de acordo com a fun��o cores, passando o valor da pe�a como par�metro
                        (tabuleiro + (linha_aux-1)*tamanho + coluna)->cor =
                        cores((tabuleiro + (linha_aux-1)*tamanho + coluna)->valor);

                        // define a pe�a em linha_aux como zero
                        *(tabuleiro + linha_aux*tamanho + coluna) = zero;
                        // soma o valor da pe�a acima de linha_aux ao score
                        *score += (tabuleiro + (linha_aux-1)*tamanho + coluna)->valor;
                        // define resultado como o valor da pe�a acima de linha_aux
                        *resultado = (tabuleiro + (linha_aux-1)*tamanho + coluna)->valor;
                        // seta a flag de movimenta��o para 1
                        moveu = 1;
                        flag = linha_aux; // define flag como linha_aux para impedir que seja realizada outra soma nessa posi��o
                    }
                }
            }
        }
    }
    if (moveu == 1) // se a flag de movimenta��o for igual a 1
        return 1; // retorna 1 pois ocorreu movimenta��o
    else // se n�o
        return 0; // retorna 0 pois n�o houve movimenta��o
}

// fun��o para indicar se � poss�vel o movimento para baixo
// recebe como par�metro:
// o ponteiro tabuleiro do tipo peca
// a vari�vel int tamanho do tabuleiro
// o ponteiro score do tipo int
// o ponteiro resultado do tipo int
// a peca zero
int pode_baixo(peca *tabuleiro, int tamanho, int *score, int *resultado, peca zero) {
    int linha, coluna, flag, linha_aux, moveu = 0; // define as vari�veis de controle da matriz linha e coluna
    // define a vari�vel flag que serve para que os n�meros n�o sejam somados em sequ�ncia
    // define a vari�vel linha_aux que serve para n�o alterarmos a vari�vel linha dentro do loop
    // define a vari�vel moveu para indicar se houve movimenta��o
    for (coluna = 0; coluna < tamanho; coluna++) // percorre todas as colunas da matriz
    {
        flag = (tamanho - 1); // define a flag como tamanho-1, representando a linha 3 (valor m�ximo)
        for (linha = (tamanho-2); linha >= 0; linha--) // percorre todas as linhas da matriz (come�a na linha 2 porque se fosse
        {                                              // na 3 n�o poderia se mover para baixo)
            if ((tabuleiro + linha*tamanho + coluna)->valor != 0) // se o valor da pe�a na posi��o linha e coluna da matriz
                                                                  // for diferente de 0
            {
                linha_aux = linha; // salva a linha em linha_aux
                for (linha_aux; linha_aux < flag; linha_aux++) // percorre todas as linhas poss�veis de se mover na matriz,
                                                               // de cima para baixo, sem considerar a linha 3 (salva em flag)
                {
                    if ((tabuleiro + (linha_aux+1)*tamanho + coluna)->valor == 0) // se o valor na posi��o abaixo de linha_aux
                                                                                  // for igual a 0
                    {
                        // define o valor nessa posi��o como o valor da pe�a em linha_aux
                        *(tabuleiro + (linha_aux+1)*tamanho + coluna) = *(tabuleiro + linha_aux*tamanho + coluna);
                        // define a pe�a em linha_aux como zero
                        *(tabuleiro + linha_aux*tamanho + coluna) = zero;
                        moveu = 1; // seta a flag de movimento para 1
                    }
                    else if ((tabuleiro + (linha_aux+1)*tamanho + coluna)->valor ==
                             (tabuleiro + linha_aux*tamanho + coluna)->valor ) // se o valor na posi��o abaixo de linha_aux
                                                                               // for igual ao em linha_aux
                    {
                        // soma esses dois valores e salva na posi��o abaixo de linha_aux
                        (tabuleiro + (linha_aux+1)*tamanho + coluna)->valor =
                        ((tabuleiro + (linha_aux+1)*tamanho + coluna)->valor)*2; // como s�o valores iguais, a soma � equivalente
                                                                                 // a multiplicar por dois

                        // define a cor nessa posi��o de acordo com a fun��o cores, passando o valor da pe�a como par�metro
                        (tabuleiro + (linha_aux+1)*tamanho + coluna)->cor =
                        cores((tabuleiro + (linha_aux+1)*tamanho + coluna)->valor);

                        // define a pe�a em linha_aux como zero
                        *(tabuleiro + linha_aux*tamanho + coluna) = zero;
                        // soma o valor da pe�a abaixo de linha_aux ao score
                        *score += (tabuleiro + (linha_aux+1)*tamanho + coluna)->valor;
                        // define resultado como o valor da pe�a abaixo de linha_aux
                        *resultado = (tabuleiro + (linha_aux+1)*tamanho + coluna)->valor;
                        // seta a flag de movimenta��o para 1
                        moveu = 1;
                        flag = linha_aux; // define flag como linha_aux para impedir que seja realizada outra soma nessa posi��o
                    }
                }
            }
        }
    }
    if (moveu == 1) // se a flag de movimenta��o for igual a 1
        return 1; // retorna 1 pois ocorreu movimenta��o
    else // se n�o
        return 0; // retorna 0 pois n�o houve movimenta��o
}

// fun��o para indicar se � poss�vel o movimento para esquerda
// recebe como par�metro:
// o ponteiro tabuleiro do tipo peca
// a vari�vel int tamanho do tabuleiro
// o ponteiro score do tipo int
// o ponteiro resultado do tipo int
// a peca zero
int pode_esquerda(peca *tabuleiro, int tamanho, int *score, int *resultado, peca zero) {
    int linha, coluna, flag, coluna_aux, moveu = 0; // define as vari�veis de controle da matriz linha e coluna
    // define a vari�vel flag que serve para que os n�meros n�o sejam somados em sequ�ncia
    // define a vari�vel coluna_aux que serve para n�o alterarmos a vari�vel coluna dentro do loop
    // define a vari�vel moveu para indicar se houve movimenta��o
    for (linha = 0; linha < tamanho; linha++) // percorre todas as linhas da matriz
    {
        flag = 0; // inicia flag igual a 0
        for (coluna = 1; coluna < tamanho; coluna++) // percorre todas as colunas da matriz (come�a na coluna 1 porque se fosse
                                                     // na 0 n�o poderia se mover para esquerda)
        {
            if ((tabuleiro + linha*tamanho + coluna)->valor != 0) // se o valor da pe�a na posi��o linha e coluna da matriz
                                                                  // for diferente de 0
            {
                coluna_aux = coluna; // salva a coluna em coluna_aux
                for (coluna_aux; coluna_aux > flag; coluna_aux--) // percorre todas as colunas poss�veis de se mover na matriz,
                                                                  // da direita para esquerda, sem considerar a coluna 0 (salva
                                                                  // em flag)
                {
                    if ((tabuleiro + linha*tamanho + coluna_aux-1)->valor == 0) // se o valor na posi��o a esquerda de coluna_aux
                                                                                // for igual a 0
                    {
                        // define o valor nessa posi��o como o valor da pe�a em coluna_aux
                        *(tabuleiro + linha*tamanho + coluna_aux-1) = *(tabuleiro + linha*tamanho + coluna_aux);
                        // define a pe�a em coluna_aux como zero
                        *(tabuleiro + linha*tamanho + coluna_aux) = zero;
                        moveu = 1; // seta a flag de movimento para 1
                    }
                    else if ((tabuleiro + linha*tamanho + coluna_aux-1)->valor ==
                             (tabuleiro + linha*tamanho + coluna_aux)->valor) // se o valor na posi��o a esquerda de coluna_aux
                                                                              // for igual ao em coluna_aux
                    {
                        // soma esses dois valores e salva na posi��o a esquerda de coluna_aux
                        (tabuleiro + linha*tamanho + coluna_aux-1)->valor =
                        ((tabuleiro + linha*tamanho + coluna_aux-1)->valor)*2; // como s�o valores iguais, a soma � equivalente
                                                                               // a multiplicar por dois

                        // define a cor nessa posi��o de acordo com a fun��o cores, passando o valor da pe�a como par�metro
                        (tabuleiro + linha*tamanho + coluna_aux-1)->cor =
                        cores((tabuleiro + linha*tamanho + coluna_aux-1)->valor);

                        // define a pe�a em coluna_aux como zero
                        *(tabuleiro + linha*tamanho + coluna_aux) = zero;
                        // soma o valor da pe�a a esquerda de coluna_aux ao score
                        *score += (tabuleiro + linha*tamanho + coluna_aux-1)->valor;
                        // define resultado como o valor da pe�a a esquerda de coluna_aux
                        *resultado = (tabuleiro + linha*tamanho + coluna_aux-1)->valor;
                        // seta a flag de movimenta��o para 1
                        moveu = 1;
                        flag = coluna_aux; // define flag como coluna_aux para impedir que seja realizada outra soma nessa
                                           // posi��o
                    }
                }
            }
        }
    }
    if (moveu == 1) // se a flag de movimenta��o for igual a 1
        return 1; // retorna 1 pois ocorreu movimenta��o
    else // se n�o
        return 0; // retorna 0 pois n�o houve movimenta��o
}

// fun��o para indicar se � poss�vel o movimento para direita
// recebe como par�metro:
// o ponteiro tabuleiro do tipo peca
// a vari�vel int tamanho do tabuleiro
// o ponteiro score do tipo int
// o ponteiro resultado do tipo int
// a peca zero
int pode_direita(peca *tabuleiro, int tamanho, int *score, int *resultado, peca zero) {
    int linha, coluna, flag, coluna_aux, moveu = 0; // define as vari�veis de controle da matriz linha e coluna
    // define a vari�vel flag que serve para que os n�meros n�o sejam somados em sequ�ncia
    // define a vari�vel coluna_aux que serve para n�o alterarmos a vari�vel coluna dentro do loop
    // define a vari�vel moveu para indicar se houve movimenta��o
    for (linha = 0; linha < tamanho; linha++) // percorre todas as linhas da matriz
    {
        flag = (tamanho - 1); // define a flag como tamanho-1, representando a coluna 3 (valor m�ximo)
        for (coluna = (tamanho-2); coluna >= 0; coluna--) // percorre todas as colunas da matriz (come�a na coluna 2 porque se
                                                          // fosse na 3 n�o poderia se mover para direita)

        {
            if ((tabuleiro + linha*tamanho + coluna)->valor != 0) // se o valor da pe�a na posi��o linha e coluna da matriz
                                                                  // for diferente de 0
            {
                coluna_aux = coluna; // salva a coluna em coluna_aux
                for (coluna_aux; coluna_aux < flag; coluna_aux++) // percorre todas as colunas poss�veis de se mover na matriz,
                                                                  // da esquerda para direita, sem considerar a coluna 3
                                                                  // (salva em flag)
                {
                    if ((tabuleiro + linha*tamanho + coluna_aux+1)->valor == 0) // se o valor na posi��o a direita de coluna_aux
                                                                                // for igual a 0
                    {
                        // define o valor nessa posi��o como o valor da pe�a em coluna_aux
                        *(tabuleiro + linha*tamanho + coluna_aux+1) = *(tabuleiro + linha*tamanho + coluna_aux);
                        // define a pe�a em coluna_aux como zero
                        *(tabuleiro + linha*tamanho + coluna_aux) = zero;
                        moveu = 1; // seta a flag de movimento para 1
                    }
                    else if ((tabuleiro + linha*tamanho + coluna_aux+1)->valor ==
                             (tabuleiro + linha*tamanho + coluna_aux)->valor) // se o valor na posi��o a direita de coluna_aux
                                                                              // for igual ao em coluna_aux
                    {
                        // soma esses dois valores e salva na posi��o a direita de coluna_aux
                        (tabuleiro + linha*tamanho + coluna_aux+1)->valor =
                        ((tabuleiro + linha*tamanho + coluna_aux+1)->valor)*2; // como s�o valores iguais, a soma � equivalente
                                                                               // a multiplicar por dois

                        // define a cor nessa posi��o de acordo com a fun��o cores, passando o valor da pe�a como par�metro
                        (tabuleiro + linha*tamanho + coluna_aux+1)->cor =
                        cores((tabuleiro + linha*tamanho + coluna_aux+1)->valor);

                         // define a pe�a em coluna_aux como zero
                        *(tabuleiro + linha*tamanho + coluna_aux) = zero;
                        // soma o valor da pe�a a direita de coluna_aux ao score
                        *score += (tabuleiro + linha*tamanho + coluna_aux+1)->valor;
                        // define resultado como o valor da pe�a a direita de coluna_aux
                        *resultado = (tabuleiro + linha*tamanho + coluna_aux+1)->valor;
                        // seta a flag de movimenta��o para 1
                        moveu = 1;
                        flag = coluna_aux; // define flag como coluna_aux para impedir que seja realizada outra soma nessa
                                           // posi��o
                    }
                }
            }
        }
    }
    if (moveu == 1) // se a flag de movimenta��o for igual a 1
        return 1; // retorna 1 pois ocorreu movimenta��o
    else // se n�o
        return 0; // retorna 0 pois n�o houve movimenta��o
}
