#include "arvoreBinaria.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <locale.h>


Arvore * criarArvore(){
	Arvore *c = (Arvore*)malloc(sizeof(Arvore));  //// aloca a estrutura Arvore
	if (c != NULL){  ///se a arvore existir
		c->raiz = (No*)malloc(sizeof(No)); //aloca a raiz
	} 
	return c; //retorna arvore;
}

No * novoNo(int *valor){
	No * node;  
	node = (No*) malloc(sizeof(No)); // aloca o No
    // Inicializa os campos
	node->valor = valor;
	node->esquerda = NULL;
	node->direita = NULL;	
	return node; 	// retorna o No criado
}

int inserirNo(Arvore *c, int *valor){
	No * noAuxiliar = c->raiz;
	No * novoElemento = novoNo(valor);
	
	while(noAuxiliar != NULL) {
		if (valor < noAuxiliar->valor){
			noAuxiliar = noAuxiliar->esquerda; 
		}else if(valor > noAuxiliar->valor){
			noAuxiliar = noAuxiliar->direita; 
		} else {
		printf("Esse valor já está inserido");
		return FALSE;
		}
	}
	
	if(noAuxiliar == NULL){
		noAuxiliar = novoElemento;
	}
	return TRUE;	
}

int buscarNo(Arvore *c, int *valor){
	No * noAuxiliar = c->raiz;
	
	while(noAuxiliar != NULL) {
		if (valor < noAuxiliar->valor){
			noAuxiliar = noAuxiliar->esquerda; 
		}else if(valor > noAuxiliar->valor){
			noAuxiliar = noAuxiliar->direita; 
		} else if(valor == noAuxiliar->valor){
		printf("Esse valor se encontra na arvore");
		return TRUE;
		}
	}
	
	printf("Esse valor não se encontra na arvore");
	return FALSE;
		
}
      
int deletarNo(Arvore *c, int *valor){
	No * noAuxiliar = c->raiz;
	
	if(noAuxiliar->valor == valor){
		
	}
	
/*/	while(noAuxiliar != NULL) {
		if (valor < noAuxiliar->valor){
			noAuxiliar = noAuxiliar->esquerda; 
		}else if(valor > noAuxiliar->valor){
			noAuxiliar = noAuxiliar->direita; 
		} else if(valor == noAuxiliar->valor){
		printf("Esse valor se encontra na arvore");
		return TRUE;
		}
	}
	
	printf("Esse valor não se encontra na arvore");
	return FALSE;
/*/	
}
