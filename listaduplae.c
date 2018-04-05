#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "listaduplae.h"

ListaDE * criarListaDE(){
		
	ListaDE * l = (ListaDE*)malloc(sizeof(ListaDE));   /// aloca a estrutura lista

	if(l!=NULL){

		l->numItens = 0;
		l->inicio = (No*)malloc(sizeof(No)); /// aloca o ponteiro p ponteiro do inicio da lista	
		l->inicio = NULL; // inicializa o inicio da lista com zero	
		
		return l;	
	}else{
		 return NULL;
		 free(l);
	}
}

No * newNode(char *info, float valor){
	No * node;  
	node = (No*) malloc(sizeof(No)); // aloca um novo No
	
	// Inicializa os campos
	node->info = (char*)malloc(30*sizeof(char));
	strcpy(node->info,info);
	node->valor = valor;
	node->ant=NULL;
	node->prox = NULL;
	
	return node; 	// retorna o No criado
}

int insereFim(ListaDE *l, char *info,float valor){	
	if(l!=NULL){
		No * noAuxiliar = l->inicio;
		No * novoNo = newNode(info, valor);
		// inserir o elemento na lista contida no slot mapeado
		if(noAuxiliar == NULL ) {
			l->inicio = novoNo;		
		} else {
        	while(noAuxiliar->prox != NULL) noAuxiliar= noAuxiliar->prox;
			novoNo->ant = noAuxiliar;
			noAuxiliar->prox = novoNo;	
		}
		l->numItens++;
		return TRUE;
	}
	return FALSE;
}

No * buscarDE(ListaDE *l, char *info){
	
	if(l != NULL && l->inicio != NULL){
	
		No *auxiliar = l->inicio;
	
		if (strcmp(auxiliar->info, info)==0){
			return auxiliar;
		}else if (strcmp(auxiliar->info, info)!= 0){	
			while(strcmp(auxiliar->info, info)!=0) {
				auxiliar = auxiliar->prox;
				if(auxiliar == NULL) return NULL;
			}
			return auxiliar;
		} else return NULL;
	}
	return NULL;
}

int deletarDE(ListaDE *l, char *info){
	
	if(l != NULL && l->inicio != NULL){
	
		No *auxiliar = l->inicio;
	
		if (strcmp(auxiliar->info, info)==0){
			l->inicio = auxiliar->prox;
			l->inicio->ant = NULL;
			free(auxiliar);
			l->numItens--;
			return TRUE;
		}else if (strcmp(auxiliar->info, info)!= 0){	
			while(strcmp(auxiliar->info, info)!=0) {
				auxiliar = auxiliar->prox;
				if(auxiliar == NULL) return FALSE;
			}
			auxiliar->ant->prox = auxiliar->prox;
			auxiliar->prox->ant = auxiliar->ant;
			free(auxiliar);
			l->numItens--;
			return TRUE;
		}else return FALSE;
	}
	return FALSE;
}

void allLista(ListaDE *l){
	if(l != NULL && l->inicio != NULL){
		No *auxiliar = l->inicio;
		if(l->inicio != NULL) printf("     NOME         |      VALOR      \n");
		while(auxiliar!=NULL){
			printf("  %s         |    %1f      \n", auxiliar->info, auxiliar->valor);
			auxiliar=auxiliar->prox;
		}
	}
}

int listaVazia(ListaDE *l){
	if(l != NULL && l->inicio == NULL && l->numItens == 0){
		return TRUE;
	}
	return FALSE;
}

void destroiLista(ListaDE *l){
	
	if(l!=NULL && l->inicio!=NULL){
		while (listaVazia(l) == FALSE) deletar(l,l->inicio->info);
		free(l);
	}
}

