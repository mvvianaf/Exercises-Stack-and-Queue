#include "pilha.h"
#include<ctype.h>

int palindromo(Pilha* p){
	
	char palavraInvertida[(p->tam)-1];
	char palavraNormal[(p->tam)-1];
	
	Pilha* nP = cria();
	//Obtendo a plavra em forma invertida sem espaços ou pontos
	int i=0;
	char temp;
	while(!vazia(p)){
		temp = pop_char(p);
		//isaplha VERIFICA SE E UM CARACTER
		if(isalpha(temp)){
			palavraInvertida[i] = temp;
			i++;
		}
		push_char(nP,temp);
	}
	palavraInvertida[i]='\0';
	
	//Obtendo a palavra normal sem espaço ou pontos
	i=0;
	while(!vazia(nP)){
		temp = pop_char(nP);
		if(isalpha(temp)){
			palavraNormal[i] = temp;
			i++;
		}
		push_char(p,temp);
	}
	palavraNormal[i]='\0';
	
	return !strcasecmp(palavraNormal,palavraInvertida);
}

int main(){
	
	Pilha* p = cria();
	int i=0,c;
	
	printf("Digite a sequencia de caracteres:\n");
	
	while(c != '\n'){
		c = getchar();
		push_char(p,c);
		i++;
	}
	
	printf("\nA sequencia de caractres invertido fica:");
	imprime_char(p);
	printf("A sequencia de caractres e um palindromo?\n%s",palindromo(p) ? "SIM" : "NAO");
	
	
}
