#include<stdio.h>
#include<stdlib.h>
#define TAMVET(vet) (sizeof(vet)/sizeof((vet)[0]))

typedef struct no{
	float info;
	char text;
	struct no* prox;	
}No;

typedef struct pilha{
	No* prim;
	int tam;
}Pilha;

Pilha* cria (void){
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->prim=NULL;
	p->tam=0;
	return p;
}

No* ins_ini(No* l,float v){
	No* p = (No*)malloc(sizeof(No));
	p->info=v;
	p->prox=l;
	return p;
}

No* ins_ini_char(No* l,char v){
	No* p = (No*)malloc(sizeof(No));
	p->text=v;
	p->prox=l;
	return p;
}

No* ret_ini(No* l){
	No* p = l->prox;
	free(l);
	return p;
}

void push (Pilha* p, float v){
	p->prim = ins_ini(p->prim,v);
	p->tam++;
}

void push_char(Pilha* p, char v){
	p->prim = ins_ini_char(p->prim,v);
	p->tam++;
}

int vazia (Pilha* p){
	return (p->prim==NULL);
}

float pop (Pilha* p){
	float v;
	if(vazia(p)){
		printf("Pilha Vazia!\n");
		exit(1);
	}
	v = p->prim->info;	
	p->prim = ret_ini(p->prim);
	p->tam--;
	return v;
}

char pop_char(Pilha* p){
	char v;
	if(vazia(p)){
		printf("Pilha Vazia!\n");
		exit(1);
	}
	v = p->prim->text;	
	p->prim = ret_ini(p->prim);
	p->tam--;
	return v;
}

void libera (Pilha* p){
	No* q=p->prim;
	while(q!=NULL){
		No* t=q->prox;
		free(q);
		q = t;
	}
	free(p);
}

void imprime (Pilha* p){
	No* q;
	for (q=p->prim; q!=NULL; q=q->prox)
		printf("%.2f\n",q->info);
}

void imprime_char(Pilha* p){
	No* q;
	for (q=p->prim; q!=NULL; q=q->prox)
		printf("%c",q->text);
	printf("\n");
}

int tamanho(Pilha* p){
	Pilha* nP = p;
	int i=-1;
	while(!vazia(nP)){
		i++;
		pop(nP);
	}
	return i;	
}

Pilha* inverter(Pilha* p){
	Pilha* nP = cria();
	while(!vazia(p))
		push_char(nP,pop_char(p));
	return nP;
}
