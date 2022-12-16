#include <stdio.h>
#include "funcs.h"

int main(){
	char simb;
	int NumBin; // 0 its 8 1 its 16 2 its 2
	printf("Введите знак: ");
	scanf(" %c", &simb);
	if(simb == '~'){
		printf("Введите число: \n");
		char num3[128];
		scanf("%s", num3);
		if (num3[0] != '0' && num3[1] != 'x'){
			int res = ~ (Atoi_2(num3));
			DecToBin(res);
		}
		if(num3[0] == '0' && num3[1] != 'x'){
			int x = strlen(num3);
			memmove(&num3[0], &num3[0 + 1], x);
			int res;
			res = ~(Atoi_8(num3));
			DecToOctal(res);
		}
		if(num3[0] == '0' && num3[1] == 'x'){
			int x = strlen(num3);
			memmove(&num3[0], &num3[2], x - 1);
			int res;
			res = ~(Atoi_16(num3));
			printf("0x%x",res);
		}
	}
	else if (simb != '~'){
		printf("Введите два числа: \n");
		char num1[128];
		char num2[128];
		scanf("%s", num1);
		scanf("%s", num2);
		if (num1[0] != '0' && num1[1] != 'x' && num2[0] != '0' && num2[1] !='x'){
			NumBin = 2;
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
			NumBin = 0;
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
			NumBin = 0;
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
	return 0;
}
