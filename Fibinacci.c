#include<stdio.h>
#include<stdlib.h>

int Fib(int n);


int main(int *argc, char *argv[]){

	int n = atoi(argv[1]);
	int number;

	number = Fib(n);

	printf("\n%d", number);

}

int Fib(int n){
	int i;
	int fibNum=0;
	for(i = 2; i<n; i++){
		fibNum = (i-1) + (i-2);
		printf("%d\n", fibNum);
	}
	return i;
}