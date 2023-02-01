#include <stdlib.h>
#include <stdio.h>
void soma(int a, int b, int *s, int *p){
	*s = a+b;
	printf("%d", *s);

}

int main(){
	int *s = malloc (8),*p = malloc (8);
	*s = 0;
	*p = 0;
	soma(5,5,s,p);
	free(s);
	free(p);
	return 0;
}
