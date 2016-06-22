#include "pilha.h"
#include<ctype.h>

//REFERENCIA AAABBABABBACABBABABBAAA

int xcy(Pilha* p){
	
	//MONTANDO X
	char x[(p->tam)-1];
	char temp;
	int i=0;
	while(!vazia(p)){
		temp = pop_char(p);
		if(temp=='C')
			break;
		if(temp!=' ' && temp!='\n'){
			x[i] = temp;
			i++;
		}
	}
	x[i]='\0';
	
	//MONTANDO Y
	if(!vazia(p)){
		
		char y[(p->tam)-1];
		i=0;
		p = inverter(p);
		while(!vazia(p)){
			temp = pop_char(p);
			if(temp!=' ' && temp!='\n'){
				y[i] = temp;
				i++;
			}
		}
		y[i]='\0';
	
		printf("X = %s Y = %s\n",x,y);
		
		return !strcasecmp(x,y);
	}
			
	return 0;
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

	printf("A sequencia de caracteres e xCy ?\n%s",xcy(p) ? "SIM" : "NAO");
	
}
