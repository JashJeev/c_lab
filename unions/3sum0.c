#include<stdio.h>
#include<stdlib.h>
#define N 100


void main() {

	int *pos = malloc(sizeof(int) * N);
	int *neg = malloc(sizeof(int) * N);		
	int table [N][N] = {0};

	fill_arr(pos, neg);
	fill_table(table, pos, neg);



