#include "pilha.h"

Pilha* unirPilhasOrdenados(Pilha* p1,Pilha* p2){
	
	Pilha* nP = cria();
	
	while(!vazia(p1) && !vazia(p2)){
		
		float a = pop(p1);
		float b = pop(p2);
	
		if(a < b){
			push(nP,a);
			push(p2,b);
		}
		
		else if(a > b){
			push(nP,b);
			push(p1,a);
		}
		
		else{
			push(nP,a);
			push(nP,b);
		}
		
	}	
	
	while(!vazia(p1)){
		push(nP,pop(p1));
	}
	
	while(!vazia(p2)){
		push(nP,pop(p2));
	}
	
	return nP;
}

int main(){
	
	Pilha* p1 = cria();
	Pilha* p2 = cria();
	
	int i;
	for(i=4;i>0;i--){
		push(p1,i);
		push(p2,i*2);
	}
	
	printf("\nPilha 1\n");
	imprime(p1);
	
	printf("\nPilha 2\n");
	imprime(p2);
	
	printf("\nPilha 3\n");
	imprime(unirPilhasOrdenados(p1,p2));
}
