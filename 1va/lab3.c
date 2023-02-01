#include <stdio.h>
#include <stdlib.h>

struct livro{
	int numero;
	int qtd_p;
	int valor_r;
	int valor_d;
};typedef struct livro livro;

void exibir_livro(livro l){
	printf("numero do livro:%d\n", l.numero);
	printf("quantidade de paginas:%d\n", l.qtd_p);
	printf("valor em real:%d\n", l.valor_r);
	printf("valor em dolar:%d\n", l.valor_d);
}

void atualizar_valor_dolar(livro *l, int pos){
	l[pos].valor_d = l[pos].valor_r*5;
}

void mudar_valor_livro(livro *l, int v, int pos){
	l[pos].valor_r = v;
	atualizar_valor_dolar(l, pos);
}

int main(){
	int escolha = -1,i = 0,num,qtd,valor,pos;
	livro *l = malloc (sizeof (livro) * 10);
	while(1){
		printf("Digite sua escolha:\n1: cadastrar livro\n2: exibir livro\n3: mudar valor do livro\n0: sair\n");
		scanf("%d", &escolha);
		switch (escolha){
			case 1:
				printf("Digite o numero do livro:\n");
				scanf("%d", &num);
				printf("Digite a quantidade de paginas:\n");
				scanf("%d", &qtd);
				printf("Digite o valor em reais:\n");
				scanf("%d", &valor);
				l[i].numero = num;
				l[i].qtd_p = qtd;
				l[i].valor_r = valor;
				atualizar_valor_dolar(l, i);
				i++;
				break;
			case 2:
				printf("Digite a posicao do livro que deseja exibir:\n");
				scanf("%d", &pos);
				exibir_livro(l[pos]);
				break;
			case 3:
				printf("Digite a posicao do livro que deseja mudar o valor junto ao valor:\n");
				scanf("%d %d", &pos, &valor);
				mudar_valor_livro(l, valor, pos);
				break;
			case 0:
				exit(0);
			default:
				break;
		}
				
	}

	return 0;
}

