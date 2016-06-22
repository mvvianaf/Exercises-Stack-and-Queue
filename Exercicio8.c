#include "fila.h"

int main(){
	
	Fila* f= cria();
	int opcao;
	printf("+---------------------------------------------------------------------------------------------------------------------+\n");
	printf("|                                                                                                                     |\n");
	printf("|                                                        MENU                                                         |\n");
	printf("|                                                                                                                     |\n");
	printf("|                            [1] Listar o numero de avioes aguardando na fila de decolagem                            |\n");
	printf("|                            [2] Autorizar a decolagem do primeiro aviao da fila                                      |\n");
	printf("|                            [3] Adicionar um aviao a fila de espera                                                  |\n");
	printf("|                            [4] Listar todos os avioes na fila de espera                                             |\n");
	printf("|                            [5] Listar as caracterosticas do primeiro aviao da fila                                  |\n");
	printf("|                                                                                                                     |\n");
	printf("+---------------------------------------------------------------------------------------------------------------------+\n");
	do{
		printf("Digite a opcao deseja: ");	
		scanf("%d",&opcao);
		setbuf(stdin,NULL);
		
		if(opcao==1){
			printf("Existem %d %s aguardando na fila de decolagem",f->tam,f->tam>1 ? "avioes" : "aviao");
		}
		else if(opcao==2){
			printf("Aviao %s (%d) autorizado para decolagem...\n\n",f->ini->nome,f->ini->info);
			retira(f);
		}
		else if(opcao==3){
			int numero;
			char nome[255];
			printf("\nDigite o nome do aviao: ");
			gets(nome);
			setbuf(stdin,NULL);
			printf("Digite o identificador do aviao: ");
			scanf("%d",&numero);
			insere(f,numero,nome);		
		}
		else if(opcao==4){
			No* ini = f->ini;
			printf("\nAvioes aguardando liberacao..\n");
			while(ini!=NULL){
				printf("Aviao: %s \n",ini->nome);
				printf("Identificador: %d \n",ini->info);
				ini = ini->prox;		
			}
		}
		else if(opcao==5){
			printf("Caracteristicas do primeiro aviao da fila\nAviao: %s \nIdentificador: %d \n",f->ini->nome,f->ini->info);
		}
		else{
			printf("Opcao invalida");
		}
			
		printf("\n\nDeseja realiazar outra operacao? [1] SIM | [0] NAO");
		scanf("%d",&opcao);
		setbuf(stdin,NULL);
		
	}while(opcao!=0);
}
