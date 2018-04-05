#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



pilha *createP(int n) {
  if(n>0){    /// se num de itens maior q 0
  pilha *c = malloc(sizeof(pilha));   // cria a pilha
  
  if(c!=NULL){     // se deu certo
  	
  	c->vetor = malloc(sizeof(char)*n); // cria um vetor dentro da pilha de tamanho max

	   if(c->vetor != NULL){   /// se deu certo 
	   /// atribui valores aos campos da pilha
		   c->max = n;    
		   c->topo = -1;
		   // retorna a pilha com vetor dentro
	   return c;
	   }
	   else free(c); // se não, destroi a pilha
	   
  }
  }
  return NULL;
}

  
int destroyP (pilha *c){
    
	if(c != NULL){    /// se a pilha não está vazia
		free(c->vetor);   //// creio que se fizer somente o "free(c);" já destroi o vetor 
		free(c);     //// toca fogo na pilha
		return TRUE;   // retorna V
	} else return FALSE;   // retorna F

}


int push (pilha *c, char item){
    if(c != NULL){  /// se a pilha é valida
	if(c->vetor != NULL){ // se o vetor é valido
	if(c->topo < c->max){    // se tem espaço no vetor
		c->topo++;
		c->vetor[c->topo] = item; // insere o item 
		return TRUE;	// retorna V
	}
	}
	}
	return FALSE; // retorna F
}


char pop (pilha *c){
if(c != NULL){  /// se a pilha é valida
	if(c->vetor != NULL){ // se o vetor é valido
	if(c->topo > -1 && c->topo < c->max){ // se a pilha n ta vazia
		char aux = c->vetor[c->topo];  /// guarda o elemento que está no topo
		//free(c->vetor[c->topo];
		c->topo--; // decrementa o topo
		return aux;	/// retorna o elemento que está no topo
	}
	}
	}
	return 0;
}

char topo (pilha *c){
	if(c != NULL){  /// se a pilha é valida
	if(c->vetor != NULL){ // se o vetor é valido
	if(c->topo > -1 && c->topo < c->max){ // se a pilha n ta vazia
	
	return c->vetor[c->topo] ; /// retorna o elemento que está no topo

}
}
}
	return 0;	   
}


int pilhaIsEmpty (pilha *c){
	if(c != NULL){  /// se a pilha é valida
	if(c->vetor != NULL){ // se o vetor é valido
	if(c->topo < 0){ // se a pilha ta vazia
  		return TRUE;
		  }
		  }
		  }
  		return FALSE;
}

main (){
	setlocale(LC_ALL, "Portuguese");
	int n=100, i=0;
	char item[n];
	
	pilha *c = createP(n);
	scanf("%s", &item);

for(i=0;i<n;i++){

if (item[i]=='['  ||  item[i]=='(' )  push(c, item[i]);
if (item[i]==']'  && c->vetor[c->topo] == '[' ) pop (c);
if (item[i]==')'  && c->vetor[c->topo] == '(') pop (c);

}
	 int resposta = pilhaIsEmpty (c);
	
	if (resposta == 1) printf("\n é uma sequencia bem formada");
	if (resposta == 0) printf("\n é uma sequencia mal formada");
}


