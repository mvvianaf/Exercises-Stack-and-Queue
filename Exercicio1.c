#include "pilha.h"

void liberaImprime (Pilha* p){
	No* q=p->prim;
	while(q!=NULL){
		printf("%.0f",q->info);
		No* t=q->prox;
		free(q);
		q = t;
	}
	free(p);
}

int main(){
	
	Pilha* p = cria();
	int i;
	for(i=0;i<15;i++){
		if(i%2==0)
			push(p,i);
		else
			pop(p);
	}
	liberaImprime(p);
	
}
