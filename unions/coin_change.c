#include<stdio.h>

#define MAX_N 100

struct coin_t {
	int value;
	int 

struct set_t {
	struct coin_t *coin;
	int num_elems;
};

int init_set(struct set_t *set)
{
	int i = 0;

	assert(set);
	set->elem = (int *) malloc(MAX_N * sizeof (struct elem_t)); 
	printf("Enter the number of elements\n");
	scanf("%d", &set->num_elems);
	printf("Enter the elements");

	for (i = 0; i < set->num_elems; i++) {
		int elem;

		scanf("%d", &elem);
		if (elem <= 0 || elem > MAX_NUM)
			exit(-1);
		set[elem - 1] = elem;
	}
	
}
void main()
{
	struct set;
	fill_array(set);
