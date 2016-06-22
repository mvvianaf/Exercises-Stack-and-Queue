#include "pilha.h"

int main(){
	
	char expressao[] = " )A+B( – C ou (A+B)) – (C + D";
	
	int controlador=0;
	
	int pE = 0; //CONTADOR DE PARENTESE DA ESQUERDA
	int pD = 0; //CONTADOR DE PARENTESE DA DIREITA
	
	int i;
	for(i=0;i<TAMVET(expressao)-1;i++){
		
		if(expressao[i]=='('){
			controlador++;
			pE++;
		}
		else if(expressao[i]==')'){
			controlador--;
			if(controlador<0)
				break;
			pD++;
		}
		
	}
	
	if(pE!=pD)
		printf("Atencao! Esta expressao viola a primeira restricao!\n(1)Se o numero de parenteses a esquerda e a direita sao iguais e\n\n");
	if(controlador!=0)
		printf("Atencao! Esta expressao viola a segunda restricao!\nSe todo parentese aberto e seguido posteriormente por um fechamento de parentese");
	
	
}
