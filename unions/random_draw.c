#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define RED 1
#define BLUE 2
#define GREEN 3
#define BLANK 0
#define ROW 100
#define COL 1000/ROW

int get_random_index(int *a)
{
	int i;
	i = rand() % 1000;
	while (a[i] != BLANK) {
		i = i + 1;
		if (i >= 1000)
			i = 0;
	}
	return i;
}

int get_random(int *a)
{
	int i;
	i = rand() % 1000;
	while (a[i] == BLANK) {
		i = i + 1;
		if (i >= 1000)
			i = 0;
	}
	return i;
}
int get_random_2(int *a, int row)
{
	int i;
	i = rand() % COL;
	while (a[i+row] == BLANK) {
		i = i + 1;
		if (i >= COL)
			i = 0;
	}
	return (i + row);
}

int get_random_2_index(int *a, int row)
{
	int i;
	i = rand() % COL;
	while (a[i+row] != BLANK) {
		i = i + 1;
		if (i >= COL)
			i = 0;
	}
	return (i + row);
}



void print_a(int *a) {
	int i = 0, j = 0, k = 0;
	int r_count = 0, b_count = 0, g_count = 0;
	float r,b,g,sum;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			if (a[k] == RED)	
				r_count++;
			if (a[k] == BLUE)	
				b_count++;
			if (a[k] == GREEN)	
				g_count++;
				
			printf("%d ",a[k]);
			k++;
		}
		printf("\n");
	}
	sum = r_count + b_count + g_count;	
	r = 100.0 * r_count / sum;
	b = 100.0 * b_count / sum;
	g = 100.0 * g_count / sum;
	printf("RED = %d percent = %f\nBLUE = %d percent = %f\nGREEN = %d percent = %f\n",r_count,r, b_count,b, g_count,g);
}

void main()
{
	time_t t;
	int i = 0, j = 0, k = 0;
	int a[1000] = {0};
	int index,ch;
	srand((unsigned)time(&t));
	for (i = 0 ; i < 100 ;i++) {
		index = get_random_index(&a);
		a[index] = BLUE;	
		index = get_random_index(&a);
		a[index] = GREEN;	
	}
/*
	for (i = 0; i  < ROW; i++) {
			int chance = rand() % 2;
			if (chance != 1)	
				continue;
		for (j = 0; j < COL; j++) {
			index = get_random_2_index(&a, i*COL);
			if (j %2)
				a[index] = BLUE;
			else
				a[index] = GREEN;
		}
	}
*/
	for (i = 0 ; i < 1000 ; i++) {
		if (a[i] == BLANK)
			a[i] = RED;
	}
	print_a(&a);	
	printf("\nEnter choice 1 or 2 : ");
	scanf("%d",&ch);
	if (ch ==1) {

		for (i = 0; i < 900; i++) {
			index = get_random(&a);
			a[index] = BLANK;
		}
	}
	else {
		for (i = 0; i < ROW; i++) {
			for (j = 0; j < COL; j++) {
				index = get_random_2(&a, i*COL);
				a[index] = BLANK;
			}
			if (i == ROW -10 )
				break;
		}
	}


	print_a(&a);	

}
