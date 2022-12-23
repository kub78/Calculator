#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Bin.h"
#include "Oct.h"
#include "Hex.h"
int main(){
	char simb;
	int i;
	char* line = NULL;
	size_t len = 0;
	char LineSize = 0;
	char num1[128];
	char num2[128];
	LineSize = getline(&line,&len,stdin);
	line[LineSize - 1] = '\0';
	if (sscanf(line,"%s %c %s", num1, &simb, num2) == 3){
		if (num1[0] != '0' && num1[1] != 'x' && num2[0] != '0' && num2[1] !='x'){
			if(simb == '+'){
				int res = Atoi_2(num1) + Atoi_2(num2);
				DecToBin(res);
				printf(" (%d)", res);
			}
			if(simb == '-'){
				int res = Atoi_2(num1) - Atoi_2(num2);
				if (res < 0){
					res = -res;
				DecToBin(res);
				printf(" (-%d)", res);
				}
				else{
					DecToBin(res);
					printf(" (%d)", res);
				}
			}
			if(simb == '*'){
				int res = Atoi_2(num1) * Atoi_2(num2);
				DecToBin(res);
				printf(" (%d)", res);
			}
			if(simb == '%'){
				int res = Atoi_2(num1) % Atoi_2(num2);
				DecToBin(res);
				printf(" (%d)", res);
			}
			if(simb == '&'){
				int res = Atoi_2(num1) & Atoi_2(num2);
				DecToBin(res);
				printf(" (%d)", res);
			}
			if(simb == '|'){
				int res = Atoi_2(num1) | Atoi_2(num2);
				DecToBin(res);
				printf(" (%d)", res);
			}
			if(simb == '^'){
				int res = Atoi_2(num1) ^ Atoi_2(num2);
				DecToBin(res);
				printf(" (%d)", res);
			}
		} 
		else if (num1[0] == '0' && num1[1] != 'x' && num2[0] == '0' && num2[1] !='x' ){
			int x = strlen(num1);
			memmove(&num1[0], &num1[0 + 1], x);
			memmove(&num2[0], &num2[0 + 1], x);
			x = strlen(num1);
			if(simb == '+'){
				int res = Atoi_8(num1) + Atoi_8(num2);
				DecToOctal(res);
				printf(" (%d)", res);
				
			}
			if(simb == '-'){
				int res = Atoi_8(num1) - Atoi_8(num2);
				if (res < 0){
					res = -res;
				DecToOctal(res);
				printf(" (-%d)", res);
				}
				else{
					DecToOctal(res);
					printf(" (%d)", res);
				}
			}
			if(simb == '*'){
				int res = Atoi_8(num1) * Atoi_8(num2);
				DecToOctal(res);
				printf(" (%d)", res);
			}
			if(simb == '%'){
				int res = Atoi_8(num1) % Atoi_8(num2);
				DecToOctal(res);
				printf(" (%d)", res);
			}
			if(simb == '&'){
				int res = Atoi_8(num1) & Atoi_8(num2);
				DecToOctal(res);
				printf(" (%d)", res);
			}
			if(simb == '|'){
				int res = Atoi_8(num1) | Atoi_8(num2);
				DecToOctal(res);
				printf(" (%d)", res);
			}
			if(simb == '^'){
				int res = Atoi_8(num1) ^ Atoi_8(num2);
				DecToOctal(res);
				printf(" (%d)", res);
			}
		}
		else if (num1[0] == '0' && num1[1] == 'x' && num2[0] == '0' && num2[1] == 'x'){
			int x = strlen(num1);	
			memmove(&num1[0], &num1[2], x - 1);
			memmove(&num2[0], &num2[2], x - 1);
			if(simb == '+'){
				int res = Atoi_16(num1) + Atoi_16(num2);
				printf("0x%x (%d) \n",res,res);
			}
			if(simb == '-'){
				int res = Atoi_16(num1) - Atoi_16(num2);
				if (res < 0){
					res = -res;
					printf("-0x%x (-%d) \n",res,res);
				}
				else{
					printf("0x%x (%d) \n",res,res);
				}					
	
			}
			if(simb == '*'){
				int res = Atoi_16(num1) * Atoi_16(num2);
				printf("0x%x (%d) \n",res,res);
			}
			if(simb == '%'){
				int res = Atoi_16(num1) % Atoi_16(num2);
				printf("0x%x (%d) \n",res,res);
			}
			if(simb == '&'){
				int res = Atoi_16(num1) & Atoi_16(num2);
				printf("0x%x (%d) \n",res,res);
			}
			if(simb == '|'){
				int res = Atoi_16(num1) | Atoi_16(num2);
				printf("0x%x (%d) \n",res,res);
			}
			if(simb == '^'){
				int res = Atoi_16(num1) ^ Atoi_16(num2);
				printf("0x%x (%d) \n",res,res);
			}
		}
		else{
			printf("Ошибка: системы счисления не совпадают\n ");
		}
	}
	else if (sscanf(line,"~%s",num2) == 1){
		if (num2[0] != '0' && num2[1] != 'x'){
			int res = ~ (Atoi_2(num2));
			DecToBin(res);
			printf("(%d)", res);
		}
		if(num2[0] == '0' && num2[1] != 'x'){
			int x = strlen(num2);
			memmove(&num2[0], &num2[0 + 1], x);
			int res;
			res = ~(Atoi_8(num2));
			DecToOctal(res);
			printf("(%d)", res);
		}
		if(num2[0] == '0' && num2[1] == 'x'){
			int x = strlen(num2);
			memmove(&num2[0], &num2[2], x - 1);
			int res;
			res = ~(Atoi_16(num2));
			printf("0x%x (%d)",res,res);
			
		}
	}
	else{
		printf("Ошибка: Неправильный ввод\n ");
	}


	return 0;
}
