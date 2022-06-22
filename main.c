#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "pilha.c"

int perguntarTorreColocar()
{
    int op;
    printf("Em qual torre irá colocar -> ");
    scanf("%d", &op);
    return op - 1;
}
int perguntarTorreTirar()
{
    int op;
    printf("De qual torre você irá retirar -> ");
    scanf("%d", &op);
    return op - 1;
}

bool ganhou(struct Pilha *torreB, struct Pilha *torreC){

    int capacidade = torreB->capacidade;

    if(torreB->topo == capacidade - 1) return true;
    if(torreC->topo == capacidade - 1) return true;

    return false;
    
}

/// Preencher pilha com os devidos "discos".
/// O topo terá o menor número e o maior será a base
void preencherPilha(struct Pilha *torre)
{
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

    int qtdDiscos;
    printf("Insira o tamanho do pilha -> ");
    scanf("%d", &qtdDiscos);

    create(&torreA, qtdDiscos);
    create(&torreB, qtdDiscos);
    create(&torreC, qtdDiscos);
    
    preencherPilha(&torreA);

    struct Pilha *vet[] = {&torreA, &torreB, &torreC};

    struct Pilha *torreSelecionada;

    int selecao, discoSendoMovimentado;
    int contador = 0;

    while (true)
    {
        show(&torreA);
        show(&torreB);
        show(&torreC);

        printf("\n");
        selecao = perguntarTorreTirar();
        torreSelecionada = vet[selecao];

        if (isEmpty(torreSelecionada))
            printf("\nTorre Vazia\n");
        else
        {
            discoSendoMovimentado = pop(torreSelecionada);

            selecao = perguntarTorreColocar();
            torreSelecionada = vet[selecao];

            while (!isEmpty(torreSelecionada) && top(torreSelecionada) < discoSendoMovimentado)
            {
                selecao = perguntarTorreColocar();
                torreSelecionada = vet[selecao];
            }
            
            push(torreSelecionada, discoSendoMovimentado);
            contador++;
        }


        if(ganhou(&torreB, &torreC)){

            int qtdMinima = pow(2, qtdDiscos) - 1;

            printf("\n---- PARABÉNS SEU MERDA, FINALMENTE. ----\n");
            printf("A quantidade mínima de movimentos era %i!\n", qtdMinima);
            printf("Vocẽ efetuou %i movimentos para finalizar!\n", contador);
            
            return;
        }
    }
}
