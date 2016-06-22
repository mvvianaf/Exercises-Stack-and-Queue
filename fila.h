#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct no{
	int info;
	char nome[255];
	struct no* prox;
}No;

typedef struct fila{
	No* ini;
	No* fim;
	int tam;	
}Fila;

Fila* cria(void){
	Fila* f = (Fila*)malloc(sizeof(Fila));
	f->ini=f->fim=NULL;
	f->tam=0;
	return f;
}

No* ins_fim(No* fim,int v,char nome[255]){
	No* p = (No*)malloc(sizeof(No));
	
	p->info = v;
	strcpy(p->nome,nome);
	p->prox = NULL;
	
	if(fim != NULL)
		fim->prox = p;
	return p;
}

No* ret_ini(No* ini){
	No* p = ini->prox;
	free(ini);
	return p;
}

void insere(Fila* f, int v,char nome[255]){
	f->fim = ins_fim(f->fim,v,nome);
	if(f->ini==NULL)
		f->ini=f->fim;
	f->tam++;
}

int vazia(Fila* f){
	return (f->ini==NULL);
}

No* retira(Fila* f){
	if(vazia(f)){
		printf("Fila Vazia!\n");
		exit(1);
	}
	No* v = f->ini;
	f->ini = ret_ini(f->ini);
	if(f->ini==NULL)
		f->fim=NULL;
	f->tam--;
	return v;
}

void libera(Fila* f){
	No* q = f->ini;
	while(q!=NULL){
		No* t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}
