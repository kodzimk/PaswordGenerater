#include<stdio.h>
#include"generator/generator.h"

int main()
{
	while (1)
	{
		int symbols = 0;
		int numbers = 0;
		int upLet = 0;
		int downLet = 0;
		int size = 0;

		printf("Hello!!! Enter size of your password:\n");
		scanf_s("%d", &size);

		gen_start(size,&symbols, &numbers, &upLet, &downLet);
		gen_while(size, symbols, numbers, upLet, downLet);

		system("cls");
	}


	return -1;
}