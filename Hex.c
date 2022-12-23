#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int Pow_16(int size){
	int num = 1;
	for(int i = 0 ;i < size; i++){
		num = num * 16;	
	}
	return num;
}
int Atoi_16(char* str){
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
			if ((new_str1[i] < 'a' || new_str1[i] > 'f') && (new_str1[i] < '0' || new_str1[i] > '9')){
			printf("Ошибка: Неправильный ввод \n");
			exit(1);
		}
		if (new_str1[i] >= 'a' && new_str1[i] <= 'f'){
		num = num + ((new_str1[i] - 'a' + 10) * Pow_16(i));
		}
		else{
			//printf("%d ", num);
			num = num + ((new_str1[i] - '0') * (Pow_16(i)));
		}
	}
	//printf("%d ", num);
	return num * flag;
}