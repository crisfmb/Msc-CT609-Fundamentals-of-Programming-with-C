#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bola // struct e um tipo de modelo de dados ou variavel que contem variaveis dentro que podem ser de diferentes tipos. Todas as variaveis dentro de um vetor precisam ser do mesmo tipo e no struct não. NÃO ESQUECE A DIFERENÇA.
{
    int codigo;
    float preco;
    char marca[255];
};

int main()
{
    system("clear"); //limpa a tela quanto executa novamente

    struct bola primeiraBola; //criando uma variavel do tipo struct bola

    primeiraBola.codigo = 1;              // estou atribuindo um valor para o campo codigo
    primeiraBola.preco = 10.5;            // estou atribuindo um valor para o campo preco
    strcpy(primeiraBola.marca, "Regata"); //estou atribuindo um valor para o campo marca, porem como e uma string precisa strpcy(stringcopy)

    printf("Código da bola: %d", primeiraBola.codigo);
    printf("O preço da bola: %.2f", primeiraBola.preco);
    printf("A marca da bola: %s", primeiraBola.marca);

    return 0;
}
