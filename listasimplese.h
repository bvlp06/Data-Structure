#ifndef LISTA_H
#define LISTA_H
#define TRUE 1
#define FALSE 0
#include <stdlib.h>

typedef struct no {
	char * chave;
	char * valor; 
	struct no * prox; /// ponteiro que guarda o endereço do proximo no
}No;

typedef struct lista {
	int * numItens;
	No * inicio; // primeiro no da lista
}Lista;

Lista * criarLista();

No * newNode(char *valor, char *chave);

void inserir(Lista *l, char *valor, char *chave);

int buscar(Lista *l, char *chave);

void deletar(Lista *l, char *chave);

#endif
