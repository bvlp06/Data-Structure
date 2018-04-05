#ifndef LISTADUPLAE_H
#define LISTADUPLAE_H
#define TRUE 1
#define FALSE 0
#include <stdlib.h>

typedef struct no {
	char *info;
	float valor;
	struct no * prox;
	struct no * ant;
}No;

typedef struct listaDE {
	int *numItens;
	No *inicio;
}ListaDE;

ListaDE * criarListaDE();

No * newNode(char *info ,float valor);

int insereFim(ListaDE *l, char *info,float valor);

No * buscarDE(ListaDE *l, char *info);

int deletarDE(ListaDE *l, char *info);

void allLista(ListaDE *l);

int listaVazia(ListaDE *l);

void destroiLista(ListaDE *l);

#endif
