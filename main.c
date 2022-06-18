#include <stdio.h>
#include <stdbool.h>
#include "pilha.c"

int perguntarTorreColocar()
{
    int op;
    printf("Em qual torre irá colocar -> ");
    scanf("%i", op);
    return op - 1;
}
int perguntarTorreTirar()
{
    int op;
    printf("De qual torre você irá retirar -> ");
    scanf("%i", op);
    return op - 1;
}

/// Preencher pilha com os devidos "discos".
/// O topo terá o menor número e o maior será a base
void preencherPilha(struct Pilha *torre){
    int tamanho = torre->capacidade;

    for (int i = 0; i < tamanho; i++)
    {
        push(torre, tamanho - i);
    }
    // tamanho de exemplo: 4
    // posição na torre
    // |    /- numero que vai ser inserido na posição
    // 0 | 4  =  4 - 0
    // 1 | 3  =  4 - 1
    // 2 | 2  =  4 - 2
    // 3 | 1  =  4 - 3
}

void main()
{
    struct Pilha torreA;
    struct Pilha torreB;
    struct Pilha torreC;

    int capacidade = 4;

    create(&torreA, capacidade);
    create(&torreB, capacidade);
    create(&torreC, capacidade);
    
    preencherPilha(&torreA);

    struct Pilha *vet[] = {&torreA, &torreB, &torreC};

    struct Pilha *torreSelecionada;

    int selecao, auxiliar;

    while (true)
    {
        show(&torreA);
        show(&torreB);
        show(&torreC);

        printf("\n");
        selecao = perguntarTorreTirar();        // usuário escolhe entre 1, 2 ou 3, porem o retorno é subtraido em 1
        torreSelecionada = vet[selecao];    // o erro acontece aqui, ao tentar acessar o endereço no vetor

        if (isEmpty(torreSelecionada))
            printf("\nTorre Vazia\n");
        else
        {
            auxiliar = pop(torreSelecionada);

            selecao = perguntarTorreColocar();
            torreSelecionada = vet[selecao - 1];

            push(torreSelecionada, auxiliar);
        }
    }
}
