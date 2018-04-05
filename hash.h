#ifndef HASH_H
#define HASH_H
#define TRUE 1
#define FALSE 0
#define MAX 65536
#include <stdlib.h>


typedef struct elemento{
	char *chave;
	char *valor;
	struct elemento *prox;
}No;

typedef struct HASH_{
	 int tamanho;
	No **tabela;
}Hash;

Hash * criar(int tamanho);

int hash(Hash * t, char *chave);

No * newNode(char *valor, char *chave);

void inserir(Hash *t, char *valor, char *chave);

int buscar(Hash *t, char *chave);

void deletar(Hash *t, char *chave);


#endif
