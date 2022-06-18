#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct Pilha {
	int topo; /* posição elemento topo */
	int capacidade;
	int *pElem;
};

void create( struct Pilha *p, int c ){
   p->topo = -1;
   p->capacidade = c;
   p->pElem = (int*) malloc (c * sizeof(int));
}

bool isEmpty(struct Pilha *p){
   return (p->topo == -1);
}
bool isFull( struct Pilha *p ){
	return (p->topo == p->capacidade - 1);
}

void push(struct Pilha *p, int v){

	p->topo++;
	p->pElem[p->topo] = v;

}
int pop(struct Pilha *p ){
   int aux = p->pElem[p->topo];
   p->pElem[p->topo] = 0;
   p->topo--;
   return aux;
}

int top(struct Pilha *p){
   return p->pElem[p->topo];
}

void show(struct Pilha *p){
	int tamanho = p->capacidade;
	printf("|");
	for (int i = 0; i < tamanho; i++)
	{
		if(p->pElem[i]) printf("%i", p->pElem[i]);
		else printf("-");
	}
	printf("\n");

}