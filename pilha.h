#ifndef PILHA_H
#define PILHA_H
#define TRUE 1
#define FALSE 0


typedef struct {
		int max;
        char *vetor;
        int topo;
}pilha;

//cria pilha
pilha *createP(int n);

//destroi pilha
int destroyP(pilha *c);

//coloca item no topo da pilha
int push (pilha *c,char item);

//retira o item do topo e retorna ele
char pop (pilha *c);

//consulta topo da pilha
char topo (pilha *c);

//retorna V se a pilha está vazia e F caso contrário
int pilhaIsEmpty (pilha *c);

#endif
