#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

fila *qCreate (int n){
	int i, j;
	if(n>0){ /// se numero de itens maior q 0
	
	fila *c = (fila*)malloc(sizeof(fila));  /// cria uma fila
	
	if(c!=NULL){     // se deu certo
	
		c->vetor = (Pacote*)malloc(sizeof(Pacote)*n);   //// cria uma matriz dentro da fila de tamanho max 
		if (c->vetor != NULL){
			c->inicio = 0;
			c->final = 0;
			c->max = n;
		}
		return c;
	
	}
	
	}
	return NULL;
}

int qDestroy (fila *c){
    	if(c != NULL){    /// se a fila não está vazia
		free(c->vetor); // creio que se fizer somente o "free(c);" já destroi a matriz 
				free(c);     //// toca fogo na fila
		return TRUE;   // retorna V
	} else return FALSE;   // retorna F

}

void qEnqueue(fila *c, Pacote item){
	int i;
	if(c != NULL){  /// se a fila é valida
		if(c->vetor != NULL){ // se a matriz é valida
			if(c->final < c->max){    // se tem espaço na matriz
				c->vetor[c->final] = item;
				c->final++;
			
			}
		}
	}
 
}

void *qDequeue (fila *c){
	if(c != NULL){  /// se a fila é valida
		if(c->vetor != NULL){ // se a matriz é valida
			if(c != NULL){    /// se a fila não está vazia
				int i;
				Pacote aux = c->vetor[c->inicio];     /// guarda o primeiro elemento
	
	for(i=0;i<c->max;i++)      	c->vetor[i]=c->vetor[i+1];                   /// rearranja a fila
}
}
}
}

Pacote  qFirst(fila *c){
    	if(c != NULL){  /// se a fila é valida
	if(c->vetor != NULL){ // se a matriz é valida
	if(c->final != 0){ // se a fila n ta vazia
  		return c->vetor[c->inicio]; /// retorna o 1º
		  }
		  }
		  }
}

int qIsEmpty(fila *c){
	if(c != NULL){  /// se a fila é valida
	if(c->vetor != NULL){ // se a matriz é valida
	if(c->final == 0){ // se a fila ta vazia
  return TRUE;
  }
  }
  }
  return FALSE;
}

void listaTodos(fila *c){
	
	if(c != NULL){  /// se a fila é valida
		if(c->vetor != NULL){ // se a matriz é valida
			if(c->final > 0){ // se a fila ta vazia
				 for(int i=0;i<c->final;i++) printf(" \n %s %d \n ", c->vetor[i].nome, c->vetor[i].num);
}
}
}
}

