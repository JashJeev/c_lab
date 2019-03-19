#include<stdio.h>
#include<stdlib.h>

struct calc_interface {
	void (*sum)(void *, void *);
	void (*sub)(void *, void *);
	void (*mul)(void *, void *);
	void (*div)(void *, void *);
};

struct calc {
	void *op1;
	void *op2;
	struct calc_interface operation;
	void (*print) (void);
};
struct complex_t {
	int real;
	int img;
};
void add(int *a, int *b)
{
	int c = *a + *b;
	printf("The sum of %d and %d is: %d\n", *a, *b, c);
}
char* print_c(struct complex_t *c)
{
	char * res = malloc(sizeof(char) *64);
	sprintf(res, "(%d + %di)", (c->real), (c->img));
	return res;
}

void add_c(struct complex_t *c1, struct complex_t *c2)
{
	struct complex_t c;
	c.real = c1->real + c2->real;
	c.img = c1->img + c2->img;
	printf("The sum of %s and %s is: %s\n", print_c(c1), print_c(c2), print_c(&c));	
}

void get(struct calc *cal)
{
	static int n = 0;

	if (n%2) {
		struct complex_t c1 = {1, 2}, c2 = {3, 4};
		cal->op1 = malloc(sizeof(struct complex_t));
		cal->op2 = malloc(sizeof(struct complex_t));
		memcpy(cal->op1, &c1, sizeof(struct complex_t));
		memcpy(cal->op2, &c2, sizeof(struct complex_t));
		cal->operation.sum = add_c;
	} else {
		int c1 = 10, c2 = 15;
                cal->op1 = malloc(sizeof(int));
                cal->op2 = malloc(sizeof(int));
		memcpy(cal->op1, &c1, sizeof(int));
		memcpy(cal->op2, &c2, sizeof(int));
		cal->operation.sum = add;
	}
	n++;
}
void main()
{
	struct calc cal1, cal2;
	get(&cal1);
	cal1.operation.sum(cal1.op1, cal1.op2);
	get(&cal2);
	cal2.operation.sum(cal2.op1, cal2.op2);
}
