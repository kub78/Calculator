#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void DecToBin(int n)
 {
 	if (n < 0){
		n = -n;
		printf("-");
	}
	if ( n >= 2 )
	{
		DecToBin( n/2 );
}
	printf("%d", n % 2);
 
}

int Pow_2(int size){
	int num = 1;
	for(int i = 0 ;i < size; i++){
		num = num * 2;	
	}
	return num;
}

int Atoi_2(char* str) {
	int num = 0;
	int flag = 1;
	if (str[0] == '-'){
		memmove(&str[0], &str[1], strlen(str));
		flag = -1;
	}
	char* new_str1 = calloc(strlen(str), sizeof(char));
	for(int i = 0; i < strlen(str); i++) {
		new_str1[i] = str[strlen(str) - i - 1];
	}
	for(int i = 0; i < strlen(str); i++) {
		if (new_str1[i] >= '2' || new_str1[i] < '0'){
			printf("Ошибка: Неправильный ввод \n");
			exit(1);
		}
		num = num + ((new_str1[i] - '0') * (Pow_2(i)));
	}
	
	return num * flag;
}