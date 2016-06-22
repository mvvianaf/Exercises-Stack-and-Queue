#include "pilha.h"

Pilha* removerItem(Pilha* p,float v){
	Pilha* nP = cria();
	
	while(!vazia(p)){
		float temp = pop(p);
		if(temp!=v){
			push(nP,temp);
		}
	}
	
	while(!vazia(nP)){
		push(p,pop(nP));
	}
	
	libera(nP);
	
	return p;
}

int main(){
	
	Pilha* p = cria();
	
	int i;	
	for(i=1;i<=15;i++){
		push(p,i);
	}
	
	imprime(p);
	
	float valor;
	printf("\nDigite o numero que deseja remover da pilha: ");
	scanf("%f",&valor);
	printf("\n");
	
	imprime(removerItem(p,valor));
	
	
}
