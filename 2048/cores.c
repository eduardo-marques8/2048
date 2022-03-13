#include <conio2.h>

// função para definir as cores das peças
COLORS cores(int valor) { // recebe como parâmetro a variável valor (da peça)
    // cada número possível do jogo 2048 (2^n, com n entre 1 e 11) recebe uma cor associada a ele
    if (valor == 2)
        {
            return BLACK;
        }
        else if (valor == 4)
        {
            return LIGHTGRAY;
        }
        else if (valor == 8)
        {
            return DARKGRAY;
        }
        else if (valor == 16)
        {
            return GREEN;
        }
        else if (valor == 32)
        {
            return BLUE;
        }
        else if (valor == 64)
        {
            return LIGHTMAGENTA;
        }
        else if (valor == 128)
        {
            return CYAN;
        }
        else if (valor == 256)
        {
            return RED;
        }
        else if (valor == 512)
        {
            return BROWN;
        }
        else if (valor == 1024)
        {
            return LIGHTGREEN;
        }
        else if (valor == 2048)
        {
            return MAGENTA;
        }
        else if (valor == 0) // se valor for igual a 0
        {
            return YELLOW; // pinta com a cor de fundo do programa
        }
}
