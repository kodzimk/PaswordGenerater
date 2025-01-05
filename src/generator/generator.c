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
* generating password right here
*/
void generate(int size, int symbols, int numbers, int upLet, int downLet)
{
	system("cls");
	char* arr = (char*)malloc(size * sizeof(char));

	int count = 0;
	int symbol = 0;
	int number = 0;
	int up = 0;
	int down = 0;


	for (int i = 0; i < size; i++)
	{
		while (1)
		{		
			int random = rand() % 3 + 1;
			if (random == 1 && numbers == 1)
			{
				random = rand() % 8 + 1;
				arr[i] = random + '0';
				break;
			}
			else if (random == 2 && symbols == 1)
			{
				random = rand() % 6 + 10;
				arr[i] = random + '0';
				break;
			}
			else if (random == 3 && upLet == 1)
			{
				random = rand() % 25 + 65;
				arr[i] = random + '0';
				break;
			}
			else if (random == 4 && downLet == 1)
			{
				random = rand() % 30 + 97;
				arr[i] = random + '0';
				break;
			}
		}
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

