#include"generator.h"

/*
* gen_start - start generating password
* param(size) - length of password
* setting password parametrs
*/
void gen_start(int size,int* symbols,int* numbers,int* upLet,int* downLet)
{
	printf("Press 'k' to use numbers\n");
	printf("Press 'l' to use Upper Letters\n");
	printf("Press 'j' to use Down Letters\n");
	printf("Press 'h' to use symbols\n");
	printf("Press 'G' to generate\n");

	while (1)
	{
		if (kbhit())
		{
			switch (getche()) //check to see what key was hit
			{
			case 'g':
				printf("\n");
				return;
				break;
			case 'k':
				printf("\n");
				*numbers = 1;
				break;
			case 'l':
				printf("\n");
				*upLet = 1;
				break;
			case 'j':
				printf("\n");
				*downLet = 1;
				break;
			case 'h':
				printf("\n");
				*symbols = 1;
				break;
			}
		}
	}
}
/*
* generate - actual function of generating password
* param(size) - length of password,some paramaters for password
* generating password rigth here
*/
void generate(int size, int symbols, int numbers, int upLet, int downLet)
{
	system("cls");
	char* arr = (char*)malloc(size * sizeof(char));

	for (int i = 0; i < size; i++)
	{
		arr[i] = '1';
 	}
	printf("Your generated password: ");
	fwrite(arr, sizeof(char), size, stdout);
	printf("\n");
	printf("Press 'q' to stop generating\n");
	printf("Press 'e' to change generation parametrs\n");
	printf("Press 'p' to regenerate\n");
	free(arr);
}
/*
* gen_while - stop whole system
*/
void gen_stop()
{
	exit(EXIT_SUCCESS);
}
/*
* gen_while - proccess of generating password
* param(size) - length of password,some pointer
* you may regenerate or stop or start new generation with some properties which you set
*/
void gen_while(int size,int symbols, int numbers, int upLet, int downLet)
{
	generate(size, symbols, numbers, upLet, downLet);
	while (1)
	{
		if (kbhit())
		{
			switch (getche())
			{
			case 'q':
				gen_stop();
				break;
			case 'e':
				return;
				break;
			case 'p':
				generate(size, symbols, numbers, upLet,downLet);
				break;
			}
		}
	}
}

