#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H
#define TRUE 1
#define FALSE 0
#define MAX 65536
#include <stdlib.h>

typedef struct No{
	int *valor;
	struct No *esquerda;
	struct No *direita;
	
}No;

typedef struct Arvore{
	No *raiz;
}Arvore;

Arvore * criarArvore();

No * novoNo(int *valor);

int inserirNo(Arvore *c,int *valor);

int buscarNo(Arvore *c, int *valor);

int deletarNo(Arvore *c, int *valor);

void destruirArvore(Arvore *c );


#endif

