#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>


Hash * criar(int tamanho){
	Hash *t = (Hash*)malloc(sizeof(Hash));   /// aloca a estrutura hash

	if(tamanho>0){                           //verifica se o tamanho é maior que zero
			t->tamanho = tamanho;        /// a variavel tamanho da estrutura recebe o tamanho da tabela q o usuario definiu
			t->tabela = (No**)malloc(sizeof(No*)*tamanho); /// aloca a tabela
			int i;
			for(i= 0;i<tamanho;i++){  
				t->tabela[i] = NULL; // inicializa o inicio da lista com zero
			}
			return t; 	//retorna a hashtable
		}	
	else return FALSE;
}

int hash(Hash * t, char *chave){
	
	int i, valor=0;
	int tam=strlen(chave);
	for (i=0;i<tam;i++){
		valor = 31*valor + (int)chave[i]; 
	}
	if(valor<0) valor=valor*(-1);
	
	int posicao = valor % t->tamanho;
	
	return posicao;
	

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

void inserir(Hash *t, char *valor, char *chave){
	int posicao = 0;
	posicao = hash (t, chave); //usar a hash para encontrar um slot para a chave dada
	No * noAuxiliar = t->tabela[posicao];
	No * novoNo = newNode(valor, chave);
		// inserir o elemento na lista contida no slot mapeado
	if(noAuxiliar == NULL ) {
		t->tabela[posicao] = novoNo;
	} else {
        while(noAuxiliar->prox != NULL) noAuxiliar= noAuxiliar->prox;
		noAuxiliar->prox = novoNo;	
	}
}

int buscar(Hash *t, char *chave){
	int posicao = 0;
	posicao = hash (t, chave);
	No *auxiliar = t->tabela[posicao];
	if(!auxiliar) return FALSE;
	if (strcmp(auxiliar->chave, chave)==0){
	return TRUE;
	}else if (strcmp(auxiliar->chave, chave)!=0){	
	while(strcmp(auxiliar->chave, chave)!=0) auxiliar=auxiliar->prox;
	return TRUE;
	} else return FALSE;	
}

void deletar(Hash *t, char *chave){
	// deleta um elemento de uma lista
	int posicao = 0;
	posicao = hash (t, chave);
	No *auxiliar = t->tabela[posicao];
	
	if (strcmp(auxiliar->chave, chave)== 0){
		t->tabela[posicao]= auxiliar->prox;
		free(auxiliar);
	}else{	auxiliar=auxiliar->prox;
	while(strcmp(auxiliar->chave, chave)!=0) auxiliar=auxiliar->prox;
	auxiliar->prox = auxiliar->prox->prox;
	free(auxiliar);
	}
} 


	
	
	


