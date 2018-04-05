#ifndef Fila_H
#define Fila_H
#define TRUE 1
#define FALSE 0

typedef struct pacote{
	char nome[30];
	int num;
}Pacote;


typedef struct fila {
        int final, inicio;
    	int max;
        Pacote *vetor;
}fila;
        

fila * qCreate(int max);

int qDestroy(fila *c);

int qEnFila(fila *c, Pacote *item);

void  qDeFila(fila *c);

Pacote  qFirst (fila *c);

int qIsEmpty(fila *c);

void listaTodos(fila *c);

#endif
