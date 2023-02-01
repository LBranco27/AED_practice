#include <stdlib.h>
#include <stdio.h>


void print_vector(int a[], int size){
	printf("---{");
	for(int i = 0; i < size; i++){
		printf ("| %d ", a[i]);
	}
	printf("|}---\n");
}

void order(int a[], int size){
	int bcount = 0;
	int lcount = 9;
	int detected = 0;
	while(lcount >= bcount+2){
		//maior------------------
		int bigger = a[bcount];
		int bigger_pos;
		for(int i = 1+bcount; i < size; i++){
			if(a[i] > bigger){
				bigger = a[i];
				bigger_pos = i;
				detected = 1;
			}
		}

		if(detected == 1){
			for(int i = bigger_pos; i > 0+bcount ; i--){
				a[i] = a[i-1];
			}
			a[bcount] = bigger;
		}
		detected = 0;
		bcount = bcount+1;

		printf("\nVetor apos ordenar %d maior elemento:\n", bcount);
		print_vector(a,size);
		
		//maior------------------
		//
		//
		//menor------------------

		int lower = a[lcount];
		int lower_pos;
		for(int i = lcount; i > 0; i--){
			if(a[i-1] < lower){
				lower = a[i-1];
				lower_pos = i-1;
				detected = 1;
			}
		}

		if(detected == 1){
			for(int i = lower_pos; i <= lcount; i++){
				a[i] = a[i+1];
			}		
			a[lcount] = lower;
		}
		detected = 0;
		lcount = lcount-1;
		
		printf("\nVetor apos ordenar(pelo menor) %d maior elemento:\n", lcount+2);
		print_vector(a,size);

		//menor------------------
	}
}



void remove_data(int size, int a[], int remove){
	a[remove] = 0;
	//ordenar;
}


int main(){
	int choice = 11;
	int index;
	int *a = malloc(sizeof(int)*10);
	a[0] = 15;
	a[1] = 25;
	a[2] = 23;
	a[3] = 1;
	a[4] = 2;
	a[5] = 5;
	a[6] = 66;
	a[7] = 45;
	a[8] = 14;
	a[9] = 12;

	printf("Vetor antes da ordenação:\n");
	print_vector(a,10);
	printf("\n");
	order(a,10);
	printf("------------------Ordenacao concluida------------------\n\n\n");

	while (1){
		printf ("Digite sua choice:\n");
		printf ("1 - Imprimir na tela os elementos do vetor\n");
		printf ("2 - Remover elemento específico do vetor, substituindo por 0 o valor removido e deixando o valor 0 na última posição do vetor\n");
		printf ("0 - Sair\n");
		scanf ("%d", &choice);
		switch (choice){
			case 1:
				print_vector(a,10);
				break;
			case 2:
				printf("Selecione o indice para exclusao (comecando do 0):");
				scanf("%d", &index);
				a[index] = 0;
				order(a,10);
				break;
			case 0:
				free(a);
				return 0;
		}
	}
	return 0;
}
				
