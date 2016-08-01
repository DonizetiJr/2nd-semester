// Escreva uma função que receba um vetor de números inteiros e retorne o MMC.

#include <stdio.h>  

int mdc(int num1,int num2) {  
	if(num2 == 0) return num1;  
	else return mdc(num2,num1%num2); 
} 

int mmc(int num1,int num2) {
 int div;
  if(num2 == 0) return num1;
  else
   div = (num1*num2)/(mdc(num1,num2));
 return (div);
}

int main(int argc, char *argv[]) {
	int a, b;
	scanf("%d %d", &a, &b);
 	
 	printf("%d\n", mmc(a,b)); 

 	return 0;
}
