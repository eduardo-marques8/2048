#ifndef ENCERRAMENTOS_H_INCLUDED
#define ENCERRAMENTOS_H_INCLUDED

void confirma_saida(peca *tabuleiro, long int score, long int movimentos);
void confirma_novo(peca *tabuleiro, long int score, long int movimentos);
int derrota(peca *tabuleiro, int tamanho);
void fim_de_jogo(int opcao, long int score);
void ordenamento(jogador_t *jogadores);

#endif // ENCERRAMENTOS_H_INCLUDED
