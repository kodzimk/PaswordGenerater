#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void generate(int size, int symbols, int numbers, int upLet, int downLet);
void gen_start(int size, int* symbols, int* numbers, int* upLet, int* downLet);
void gen_while(int size, int symbols, int numbers, int upLet, int downLet);
void gen_stop();