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
int Pow_2(int size){
	int num = 1;
	for(int i = 0 ;i < size; i++){
		num = num * 2;	
	}
	return num;
}
int Pow_8(int size){
	int num = 1;
	for(int i = 0 ;i < size; i++){
		num = num * 8;	
	}
	return num;
}
int Pow_16(int size){
	int num = 1;
	for(int i = 0 ;i < size; i++){
		num = num * 16;	
	}
	return num;
}
int Atoi_2(char* str) {
	int num = 0;
	char* new_str1 = calloc(strlen(str), sizeof(char));
	for(int i = 0; i < strlen(str); i++) {
		new_str1[i] = str[strlen(str) - i - 1];
	}
	for(int i = 0; i < strlen(str); i++) {
		num = num + ((new_str1[i] - '0') * (Pow_2(i)));
	}
	return num;
}
int Atoi_8(char* str){
	int num = 0;
	char* new_str1 = calloc(strlen(str), sizeof(char));
	for(int i = 0; i < strlen(str); i++) {	
		new_str1[i] = str[strlen(str) - i - 1];
	}
	for(int i = 0; i < strlen(str); i++) {
		num = num + ((new_str1[i] - '0') * (Pow_8(i)));
	}
	return num;
}
int Atoi_16(char* str){
	int num = 0;
	char* new_str1 = calloc(strlen(str), sizeof(char));
	for(int i = 0; i < strlen(str); i++) {	
		new_str1[i] = str[strlen(str) - i - 1];
	}
	for(int i = 0; i < strlen(str); i++) {
		if (new_str1[i] >= 'a' && new_str1[i] <= 'f'){
		num = num + ((new_str1[i] - 'a' + 10) * Pow_16(i));
	}
		else{
			num = num + ((new_str1[i] - '0') * (Pow_16(i)));
		}
	}
	return num;
}
