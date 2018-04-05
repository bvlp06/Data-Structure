#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "lista.h"


Lista * criarLista(){
		
	Lista * l = (Lista*)malloc(sizeof(Lista));   /// aloca a estrutura lista

	if(l!=NULL){

		l->numItens = 0;
		l->inicio = (No*)malloc(sizeof(No)); /// aloca o ponteiro p ponteiro do inicio da lista
		l->inicio = NULL; // inicializa o inicio da lista com zero
			
		return l;	
	}else{
		free(l);
		return NULL;
	}
}

No * newNode(char *valor, char *chave){
	No * node;  
	node = (No*) malloc(sizeof(No)); // aloca um novo No
	// Inicializa os campos
	node->chave = (char*)malloc(30*sizeof(char));
	strcpy(node->chave,chave);
	node->valor = (char*)malloc(30*sizeof(char));
	strcpy(node->valor,valor);
	node->prox = NULL;
	return node; 	// retorna o No criado
}

void inserir(Lista * l, char *valor, char *chave){

	No * noAuxiliar = l->inicio;
	No * novoNo = newNode(valor, chave);
		// inserir o elemento na lista contida no slot mapeado
	if(noAuxiliar == NULL ) {
		l->inicio = novoNo;
	} else {
        
		while(noAuxiliar->prox != NULL) noAuxiliar= noAuxiliar->prox;
		noAuxiliar->prox = novoNo;	
	
	}
	l->numItens++;
}

int buscar(Lista *l, char *chave){
	No *auxiliar = l->inicio;
	if(!auxiliar) return FALSE;
	if (strcmp(auxiliar->chave, chave)==0){
	return TRUE;
	}else if (strcmp(auxiliar->chave, chave)!= 0){	
	while(strcmp(auxiliar->chave, chave)!=0) {
	auxiliar=auxiliar->prox;
	if(auxiliar == NULL) return FALSE;
	}
	return TRUE;
	} else return FALSE;	
}

void deletar(Lista * l, char *chave){
	// deleta um elemento de uma lista

	No *auxiliar = l->inicio;
	
	if (strcmp(auxiliar->chave, chave)== 0){
		l->inicio = auxiliar->prox;
		free(auxiliar);
	}else{
		while(strcmp(auxiliar->prox->chave, chave)!=0) auxiliar=auxiliar->prox;
		No*b= auxiliar->prox;
		auxiliar->prox = auxiliar->prox->prox;
		free(b);
	}
	l->numItens--;
} 

void imprimir(Lista*l){
	
		No *auxiliar = l->inicio;
		
		while(auxiliar!=NULL){
			
			printf("%s \n", auxiliar->chave);
			
			auxiliar=auxiliar->prox;
		}	
	
}
