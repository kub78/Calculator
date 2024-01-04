#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Pow_8(int size){
	int num = 1;
	for(int i = 0 ;i < size; i++){
		num = num * 8;	
	}
	return num;
}

int Atoi_8(char* str){
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
		if (new_str1[i] >= '8' || new_str1[i] < '0'){
			printf("Ошибка: Неправильный ввод \n");
			exit(1);
		}
		num = num + ((new_str1[i] - '0') * (Pow_8(i)));
	}
	return num * flag;
}

void DecToOctal(int n)
 {
 	if (n < 0){
		n = -n;
		printf("-");
	}
	if ( n >= 8 )
	{
		DecToOctal(n/8);
}
	printf("%d", n % 8);
}