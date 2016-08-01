// Faça um programa que receba dois inteiros e retorne o MDC.

#include <stdio.h>  

int mdc(int num1,int num2) {  
	if(num2 == 0) return num1;  
	else return mdc(num2,num1%num2); 
} 

int main(int argc, char *argv[]) {
	int a, b;
	scanf("%d %d", &a, &b);
 	
 	printf("%d\n", mdc(a,b)); 

 	return 0;
}
