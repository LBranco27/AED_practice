#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define size 50

struct pilha {
	int n;
	float vet[size];
	int aluno[size];
}; typedef struct pilha Pilha;

struct fila {
	int n;
	char vet[size][100];
}; typedef struct fila Fila;

Pilha *pilha_cria(){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p -> n = 0;
	return p;
}

Fila *fila_cria(){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	f -> n = 0;
	return f;
}

void pilha_insere (Pilha *p, float v, int indice){
	if ((*p).n == 50) {
		exit(1);
	}
	p->vet[p->n] = v;
	p->aluno[p->n] = indice;
	p->n++;
}

void fila_insere (Fila *f, char v[100]){
	if ((*f).n == 50){
		exit(1);
	}
	strcpy(f->vet[f->n], v);
	f->n++;
}

int pilha_vazia (Pilha *p){
	if(p -> n == 0){
		return 1;
	}else{
		return 0;
	}
}

int fila_vazia (Fila *f){
	if(f->n == 0){
		return 1;
	}else{
		return 0;
	}
}

float pilha_remove (Pilha *p){
	float v;
	if (pilha_vazia(p)){
		exit(1);
	}
	v = p -> vet[p -> n-1];
	p -> n--;
	return v;
}

char* fila_remove (Fila *f){
	char *v[100];
	if (fila_vazia(f)){
		exit(1);
	}
	strcpy(*v, f->vet[0]);
	for(int i = 0; i < f->n; i++){
		strcpy(f->vet[i], f->vet[i+1]);
	}
	f->n--;
	return *v;
}

void pilha_libera (Pilha *p){
	free(p);
}

void fila_libera (Fila *f){
	free(f);
}

float pilha_topo(Pilha *p){
	if(p -> n == 0){
		printf("a pilha esta vazia\n");
	}
	return p -> vet[p -> n-1];
}

void fila_exibe(Fila *f){
	for(int i = 0; i < f->n; i++){
		printf("indice: %d\n", i);
		printf("nome: %s\n", f->vet[i]);
	}
}

void pilha_exibe(Pilha *p){
	for(int i = 0; i < p->n; i++){
		printf("indice: %d\n", i);
		printf("indice do aluno: %d\n", p->aluno[i]);
		printf("nota: %f\n", p->vet[i]);
	}
}

int main(){

	char nome[100];
	int escolha = -1;
	int indice = 0;
	float valor = 0;
	struct pilha *p = pilha_cria();
	struct fila *f = fila_cria();
	while(1){
		printf("digite a escolha:\n\n");
		printf("1 - insere nome do aluno \n");
		printf("2 - insere nota do aluno \n");
		printf("3 - remove aluno (fila)\n");
		printf("4 - remove nota (pilha)\n");
		printf("5 - exibe alunos\n");
		printf("6 - exibe notas\n");
		printf("7 - sair\n");
		scanf("%d", &escolha);
		switch (escolha){
			case 0:
				break;
			case 1:
				printf("Digite o valor desejado\n");
				scanf("%s", &nome);
				fila_insere(f, nome);
				break;
			case 2:
				printf("Digite o indice do aluno desejado\n");
				scanf("%d", &indice);
				printf("Digite o valor da nota\n");
				scanf("%f", &valor);
				pilha_insere(p, valor, indice);
				break;
			case 3:
				printf("valor removido: %s\n", fila_remove(f));
				break;
			case 4:
				printf("valor removido: %f\n", pilha_remove(p));
				break;
			case 5:
				fila_exibe(f);
				break;
			case 6:
				pilha_exibe(p);
				break;
			case 7:
				exit(0);
			default:
				break;
		}
	}
	return 0;
}     
