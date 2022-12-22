#include <stdio.h>
#include "funcs.h"

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
			}
			if(simb == '-'){
				int res = Atoi_2(num1) - Atoi_2(num2);
				DecToBin(res);
			}
			if(simb == '*'){
				int res = Atoi_2(num1) * Atoi_2(num2);
				DecToBin(res);
			}
			if(simb == '%'){
				int res = Atoi_2(num1) % Atoi_2(num2);
				DecToBin(res);
			}
			if(simb == '&'){
				int res = Atoi_2(num1) & Atoi_2(num2);
				DecToBin(res);
			}
			if(simb == '|'){
				int res = Atoi_2(num1) | Atoi_2(num2);
				DecToBin(res);
			}
			if(simb == '^'){
				int res = Atoi_2(num1) ^ Atoi_2(num2);
				DecToBin(res);
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
			}
			if(simb == '-'){
				int res = Atoi_8(num1) - Atoi_8(num2);
				DecToOctal(res);
			}
			if(simb == '*'){
				int res = Atoi_8(num1) * Atoi_8(num2);
				DecToOctal(res);
			}
			if(simb == '%'){
				int res = Atoi_8(num1) % Atoi_8(num2);
				DecToOctal(res);
			}
			if(simb == '&'){
				int res = Atoi_8(num1) & Atoi_8(num2);
				DecToOctal(res);
			}
			if(simb == '|'){
				int res = Atoi_8(num1) | Atoi_8(num2);
				DecToOctal(res);
			}
			if(simb == '^'){
				int res = Atoi_8(num1) ^ Atoi_8(num2);
				DecToOctal(res);
			}
		}
		else if (num1[0] == '0' && num1[1] == 'x' && num2[0] == '0' && num2[1] == 'x'){
			int x = strlen(num1);	
			memmove(&num1[0], &num1[2], x - 1);
			memmove(&num2[0], &num2[2], x - 1);
			if(simb == '+'){
				int res = Atoi_16(num1) + Atoi_16(num2);
				printf("0x%x \n",res);
			}
			if(simb == '-'){
				int res = Atoi_16(num1) - Atoi_16(num2);
				if (res < 0){
					res = -res;
				}
				printf("-0x%x \n",res);
			}
			if(simb == '*'){
				int res = Atoi_16(num1) * Atoi_16(num2);
				printf("0x%x \n",res);
			}
			if(simb == '%'){
				int res = Atoi_16(num1) % Atoi_16(num2);
				printf("-0x%x \n",res);
			}
			if(simb == '&'){
				int res = Atoi_16(num1) & Atoi_16(num2);
				printf("0x%x \n",res);
			}
			if(simb == '|'){
				int res = Atoi_16(num1) | Atoi_16(num2);
				printf("0x%x \n",res);
			}
			if(simb == '^'){
				int res = Atoi_16(num1) ^ Atoi_16(num2);
				printf("0x%x \n",res);
			}
		}
		else{
			printf("Ошибка: системы счисления не совпадают\n ");
		}
	}
	if (sscanf(line,"~%s",num2) == 1){
		if (num2[0] != '0' && num2[1] != 'x'){
			int res = ~ (Atoi_2(num2));
			DecToBin(res);
		}
		if(num2[0] == '0' && num2[1] != 'x'){
			int x = strlen(num2);
			memmove(&num2[0], &num2[0 + 1], x);
			int res;
			res = ~(Atoi_8(num2));
			DecToOctal(res);
		}
		if(num2[0] == '0' && num2[1] == 'x'){
			int x = strlen(num2);
			memmove(&num2[0], &num2[2], x - 1);
			int res;
			res = ~(Atoi_16(num2));
			printf("0x%x",res);
		}
	}
	else{
		printf("Ошибка: Неправильный ввод\n ");
	}


	return 0;
}
