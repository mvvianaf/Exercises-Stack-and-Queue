#include "pilha.h"

int main(){
	
	Pilha* n = cria();
	Pilha* p = cria();
	
	float v;
	int opcao;
	do{
		printf("Digite um valor: ");
		scanf("%f",&v);
		if(v<0)
			push(n,v);
		else if(v>0)
			push(p,v);
		else{
			pop(p);
			pop(n);
		}
		printf("Deseja inserir outro valor? [1] Sim | [0] Nao: ");
		scanf("%d",&opcao);
		printf("\n");
	}while(opcao!=0);
	
	printf("\nPilha de positivos\n");
	imprime(p);
	printf("\nPilha de negativos\n");
	imprime(n);
	
}
