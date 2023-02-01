#include <stdio.h>
#include <stdlib.h>

struct LinkedList{
    int data;
    struct LinkedList *next;
 };typedef struct LinkedList node;

node* CreateNode(){
	node *temp;
	temp = malloc(sizeof(node));
	temp->next = NULL;
	return temp;
}

node AddNode(node *head, int value){
	node *temp,*p;
	temp = CreateNode();
	temp->data = value;
	if(head == NULL){
		head = temp;
	}else{
		p = head;
		while(p->next != NULL){	
			p = p->next;
		}
		p->next = temp;
	}
	return *head;
}
	
void ConcatenaL1(node *concatenada, node *L1){
	node *temp;
	temp = L1;
	while(temp->next != NULL){
		AddNode(concatenada, temp->data);
		temp = temp->next;
	}
}

void ConcatenaL2(node *concatenada, node *L2){
	node *temp;
	temp = L2;
	while(temp->next != NULL){
		AddNode(concatenada, temp->data);
		temp = temp->next;
	}
}

node *Inverte(node *concatenada){
	node *temp;
	node *nova = CreateNode();
	while(temp != NULL){
		while(temp->next != NULL){
			temp = temp->next;
		}
		AddNode(nova, temp->data);
		temp = NULL;
		temp = concatenada;
	}
}

node *concatena(node *L1, node *L2){
	node *concatenada;
	concatenada = CreateNode();
	ConcatenaL1(concatenada, L1);
	ConcatenaL2(concatenada, L2);
	Inverte(concatenada);
	return concatenada;

}

int main(){
	int listaAtual = 1;
	node *lista1 = malloc(sizeof(node));
	node *lista2 = malloc(sizeof(node));
	node *conc;
	while(1){
		char escolha;
		printf("escolha o valor para ser inserido na lista(%d). Digite (n) para passar para a segunda lista ou terminar o programa caso ja esteja na segunda lista\n", listaAtual);
		scanf("%c", &escolha);
		printf("\npassou do scanf\n");
		if(escolha == 'n'){
			if(listaAtual == 2){
				conc = concatena(lista1,lista2);
				exit(0);
			}
			listaAtual = listaAtual + 1;
		}
		else if(escolha < 48 || escolha > 57){
			printf("Valor nao inserido. Digite um numero\n");
		}else{
			if(listaAtual == 1){
				AddNode(lista1, escolha);
			}
			if(listaAtual == 2){
				printf("teste");
				AddNode(lista2, escolha);
			}
		}
	}
	free(lista1);
	free(lista2);
	free(conc);
	return 0;
}

