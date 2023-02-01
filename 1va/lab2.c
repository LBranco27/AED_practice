#include <stdio.h>
#include <stdlib.h>

int a,b,c,maior,menor;

void maior_f(){
	if(a>b && a>c){
		maior = a;
	}else if(b>c && b>a){
		maior = b;
	}else{
		maior = c;
	}

	printf("o maior numero e:%d\n", maior);


}

void menor_f(){
	if(a<b && a<c){
		menor = a;
	}else if(b<c && b<a){
		menor = b;
	}else{
		menor = c;
	}

	printf("o menor numero e:%d\n", menor);


}

void positivo(){
	if(a >= 0){
		printf("o primeiro e positivo\n");
	}else{
		printf("o primeiro e negativo\n");
	}


	if(b >= 0){
		printf("o segundo e positivo\n");
	}else{
		printf("o segundo e negativo\n");
	}
	

	if(c >= 0){
		printf("o terceiro e positivo\n");
	}else{
		printf("o terceiro e negativo\n");
	}


}

int negativo(){
	if(a % 2 == 0){
		printf("o primeiro e par\n");
	}else{
		printf("o primeiro e impar\n");
	}


	if(b % 2 == 0){
		printf("o segundo e par\n");
	}else{
		printf("o segundo e impar\n");
	}
	

	if(c % 2 == 0){
		printf("o terceiro e par\n");
	}else{
		printf("o terceiro e impar\n");
	}


}





int main(){
	printf("Digite 3 inteiros:\n");
	scanf("%d%d%d", &a, &b, &c);

	maior_f();
	menor_f();
	positivo();
	negativo();



	return 0;
}

