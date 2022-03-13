#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "imprime_tabuleiro.h"

// função para confirmar início de novo jogo
void confirma_novo(peca *tabuleiro, long int score, long int movimentos) {
    char s_ou_n; // variável para confirmar encerramento
    NORMALIZA; // normaliza as configurações da tela e limpa a tela
    // confirma se o jogador quer mesmo começar um novo jogo
    printf("Deseja mesmo iniciar um novo jogo?\n");
    printf("\t['s'] para sim\n");
    printf("\t['n'] para nao\n");
    do{ // faz
        s_ou_n = getch(); // pega o caractere digitado pelo usuário

        switch(s_ou_n) { // analisa as opções de s_ou_n
            case CHAR_S: // se s_ou_n for igual a 's'
                novo_jogo(tabuleiro, 1, 0, 0); // começa um novo jogo (vai para a função novo_jogo), mandando tabuleiro, o
                                               // valor 1 (que representa se o jogo é novo ou não) e resetando score e movimentos
                return; // retorna para a função main ou novo_jogo
                break; // para

            case CHAR_N: // se s_ou_n for igual a 'n'
                novo_jogo(tabuleiro, 0, score, movimentos); // vai para a função novo_jogo, mandando tabuleiro, o
                                                            // valor 0 (que representa se o jogo é novo ou não),
                                                            // o score e os movimentos
                return; // retorna para a função main ou novo_jogo
                break; // para
        }
    } while(s_ou_n != (CHAR_S || CHAR_N)); // enquanto s_ou_n for diferente de 's' ou 'n'
    return; // retorna para novo_jogo
}

// função para confirmar saída do jogo
void confirma_saida(peca *tabuleiro, long int score, long int movimentos) {
    char s_ou_n; // variável para confirmar encerramento
    NORMALIZA; // normaliza as configurações da tela e limpa a tela
    // confirma se o usuário quer mesmo encerrar o jogo
    printf("Deseja mesmo encerrar o jogo?\n");
    printf("\t['s'] para sim\n");
    printf("\t['n'] para nao\n");
        do{ // faz
            s_ou_n = getch(); // pega o caractere digitado pelo usuário

            switch(s_ou_n) { // analisa as opções de s_ou_n
                case CHAR_S: // se s_ou_n for igual a 's'
                    printf("Obrigado por jogar 2048.\n"); // printa uma mensagem de encerramento
                    return; // retorna para a função main ou novo_jogo
                    break;

                case CHAR_N: // se s_ou_n for igual a 'n'
                    novo_jogo(tabuleiro, 0, score, movimentos); // vai para a função novo_jogo, mandando tabuleiro, o
                                                                // valor 0 (que representa se o jogo é novo ou não),
                                                                // o score e os movimentos
                    return; // retorna para a função main ou novo_jogo
                    break; // para
            }
        } while(s_ou_n != (CHAR_S || CHAR_N)); // enquanto s_ou_n for diferente de 's' ou 'n'
}

// função para indicar se houve derrota no jogo, ou seja, não há mais movimentações disponíveis
int derrota(peca *tabuleiro, int tamanho) { // recebe como parâmetros o tabuleiro e o tamanho dele
    int linha, coluna; // variáveis de controle da matriz

    // perccorre toda a matriz
    for (linha = 0; linha < tamanho; linha++){
        for (coluna = 0; coluna < tamanho; coluna++){
            if ((tabuleiro + linha*tamanho + coluna)->valor == 0) // se o valor de alguma peça no tabuleiro for igual a 0
                return 0; // retorna 0, pois ainda há movimentação
        }
    }

    // percorre toda a matriz
    for (linha = 0; linha < tamanho; linha++){
        for (coluna = 0; coluna < tamanho; coluna++){
            if (linha == 0){ // se estiver na linha 0
                if (coluna == 0){ // se estiver na coluna 0
                    // se o valor na linha 0 e coluna 0 for igual ao valor em linha 0 coluna 1 ou linha 1 coluna 0
                    if (((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + linha*tamanho + (coluna+1))->valor) ||
                        ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + (linha+1)*tamanho + coluna)->valor))
                        return 0; // retorna 0, pois ainda há movimentação
                }
                else if (coluna == tamanho-1){ // se estiver na coluna 3
                    // se o valor na linha 0 e coluna 3 for igual ao valor em linha 0 coluna 2 ou linha 1 coluna 3
                    if (((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + linha*tamanho + coluna-1)->valor) ||
                        ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + (linha+1)*tamanho + coluna)->valor))
                        return 0; // retorna 0, pois ainda há movimentação
                }
                else{ // se estiver em qualquer outra coluna n (1 ou 2)
                    // se o valor na linha 0 e coluna n for igual ao valor em linha 1 coluna n ou linha 0 coluna n-1
                    // ou linha 0 coluna n+1
                    if (((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + (linha+1)*tamanho + coluna)->valor) ||
                        ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + linha*tamanho + coluna-1)->valor) ||
                        ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + linha*tamanho + coluna+1)->valor))
                        return 0; // retorna 0, pois ainda há movimentação
                }
            }
            else if (coluna == 0){ // se estiver na coluna 0
                if (linha == tamanho-1){ // se estiver na linha 3
                    // se o valor na linha 3 e coluna 0 for igual ao valor em linha 3 coluna 1 ou linha 2 coluna 0
                    if (((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + linha*tamanho + coluna+1)->valor) ||
                        ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + (linha-1)*tamanho + coluna)->valor))
                        return 0; // retorna 0, pois ainda há movimentação
                }
                else{ // se estiver em qualquer outra linha n (1 ou 2)
                    // se o valor na linha n e coluna 0 for igual ao valor em linha n coluna 1 ou linha n-1 coluna 0
                    // ou linha n+1 coluna 0
                    if (((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + linha*tamanho + coluna+1)->valor) ||
                        ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + (linha-1)*tamanho + coluna)->valor) ||
                        ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + (linha+1)*tamanho + coluna)->valor))
                        return 0; // retorna 0, pois ainda há movimentação

                }
            }
            else if (linha == tamanho-1){ // se estiver na linha 3
                if (coluna == tamanho-1){ // se estiver na coluna 3
                    // se o valor na linha 3 e coluna 3 for igual ao valor em linha 2 coluna 3 ou linha 3 coluna 2
                    if (((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + (linha-1)*tamanho + coluna)->valor) ||
                        ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + linha*tamanho + (coluna-1))->valor))
                        return 0; // retorna 0, pois ainda há movimentação
                }
                else{ // se estiver em qualquer outra coluna n (1 ou 2)
                    // se o valor na linha 3 e coluna n for igual ao valor em linha 3 coluna n-1 ou linha 3 coluna n+1
                    // ou linha 2 coluna n
                    if (((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + linha*tamanho + (coluna-1))->valor) ||
                        ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + linha*tamanho + (coluna+1))->valor) ||
                        ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + (linha-1)*tamanho + coluna)->valor))
                        return 0; // retorna 0, pois ainda há movimentação
                }
            }
            else if (coluna == tamanho-1){ // se estiver na coluna 3 (linha 1 e 2 restantes da matriz)
                // se o valor na linha n e coluna 3 for igual ao valor em linha n coluna 2 ou linha n-1 coluna 3
                // ou linha n+1 coluna 3
                if (((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + linha*tamanho + coluna-1)->valor) ||
                    ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + (linha-1)*tamanho + coluna)->valor) ||
                    ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + (linha+1)*tamanho + coluna)->valor))
                    return 0; // retorna 0, pois ainda há movimentação
            }
            else{ // se estiver em outros valores (o "miolo" da matriz)
                // se o valor na linha n e coluna m for igual ao valor em linha n coluna m-1 ou linha n coluna m+1
                // ou linha n-1 coluna m ou linha n+1 coluna m
                if (((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + linha*tamanho + coluna-1)->valor) ||
                    ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + linha*tamanho + coluna+1)->valor) ||
                    ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + (linha-1)*tamanho + coluna)->valor) ||
                    ((tabuleiro + linha*tamanho + coluna)->valor == (tabuleiro + (linha+1)*tamanho + coluna)->valor))
                    return 0; // retorna 0, pois ainda há movimentação
            }
        }
    }
    return 1; // retorna 1, pois não há mais movimentos disponíveis
}

//função para realizar o ordenamento dos jogadores dentro do ranking
void ordenamento(jogador_t *jogadores)
{

    // declaração das variaveis
    int i, sinal, fim = TAM_RANKING - 1;
    jogador_t aux;

    do{
        sinal = 0; //sinal igual a zero se não houver alteraçoes no ranking
        for (i = 0; i < fim; i++) //introduz um for para percorrer e compara o jogador atual, i, com proximo jogador i+1
        {
            if (jogadores[i].score < jogadores[i+1].score) //caso o jogador i+1 tiver score maior que o jogador atual
            {
                aux = jogadores[i+1]; // salva o jogador i+1 em uma variável auxiliar
                jogadores[i+1] = jogadores[i]; // define jogador i+1 como jogador i
                jogadores[i] = aux; // define jogador i como aux
                sinal = 1; //levanta a flag de sinal =1, para repetir o processo
            }
        }
        fim--;
    } while (sinal == 1); //ele sairia do laço quando fizer uma verificação e não houver alteraçoes
}

// função de finalização do jogo, seja por derrota ou por vitória
void fim_de_jogo(int opcao, long int score) { // recebe como parâmetro a variável opcao, sendo 0 para fim de jogo e 1 para
                                              // vitória, e o score do jogador atual
    char nome[TAM_RANKING]; // string do nome do jogador
    SET_COLORS(BLACK,LIGHTGRAY); // pinta o fundo do texto de preto e pinta a cor do texto de cinza-claro
    gotoxy(1,35); // vai para a coordenada (1,35)
    if(opcao == 0) { // se a opcao enviada for igual a 0
        printf("Nao ha mais movimentos disponiveis.\n"); // imprime que não há mais movimentos disponíveis
    } else { // se não
        printf("Parabens! Voce alcancou o numero 2048 e venceu o jogo.\n"); // imprime uma mensagem de parabéns
    }
    Sleep(5000); // da um delay de 5 segundos
    NORMALIZA; // normaliza as configurações da tela e limpa a tela

    int i; //declara um inteiro i

    jogador_t jogador[TAM_RANKING]; //declara um vetor do tipo jogador_t com 10 posiçoes
    FILE *f = fopen("ranking.txt", "rb"); //abre o arquivo ranking.txt para leitura


    char str[TAM_RANKING]; //declara um vetor string com 10 posições
    char numero[TAM_RANKING]; //declara um vetor string com 10 posições


    for(i = 0; i < TAM_RANKING; i++){ //inicia um laço for para percorrer todas as posições de jogador
        fscanf(f, "%s", &str); //faz a leitura do nome do jogador e armazena em str
        strcpy(jogador[i].nome, str); //passa o nome armazenado para o nome do jogador na posição i
        fscanf(f, "%s", &numero); //faz a leitura do score do jogador e armazena em numero
        jogador[i].score = atol(numero); //transforma a string em inteiro longo e passa o numero armazenado para o score do
                                         // jogador na posição i
    }

    fclose(f); //fecha o arquivo

    ordenamento(jogador); // ordena o vetor jogador

    if(score > jogador[i-1].score){ // se o score do jogador atual for maior que o score do último no ranking
        char nomejogador[TAM_RANKING]; //declara uma variavel string com 10 posições
        printf("Informe seu nome: "); // pede o nome do usuário
        fgets(nomejogador, TAM_RANKING, stdin); // salva o nome na variável nomejogador
        nomejogador[strlen(nomejogador)-1] = '\0'; // limpa o enter no fim da string
        jogador[i-1].score = score; //passa o score do jogador atual para o jogador na última posição do ranking
        strcpy(jogador[i-1].nome, nomejogador); //Passa o nome do jogador atual para o jogador na última posição do ranking
        ordenamento(jogador); // ordena o vetor jogador
    }

    f = fopen("ranking.txt", "wb"); //abre o arquivo ranking.txt para escrita
    for(i = 0; i < TAM_RANKING; i++){ //abre um laço for para percorrer todas as posições de jogador
        fprintf(f, "%s %ld" ,jogador[i].nome, jogador[i].score); //escreve o nome e o score do jogador i no arquivo                                      // da um espaço para escrever o score ao lado do nome
        fputs("\n", f); // põe uma nova linha a cada jogador
    }

    fclose(f); // fecha o arquivo

    printf("\nObrigado por jogar 2048.\n"); // imprime uma mensagem de encerramento
    imprime_ranking(); // imprime o ranking na tela
    Sleep(2000); // da um delay de 2 segundos

}
