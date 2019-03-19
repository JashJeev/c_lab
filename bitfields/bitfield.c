#include<stdio.h>
#include<stdlib.h>
struct test 
{ 
unsigned int x; 
//long unsigned int y; 
long unsigned int y:1; 
//long unsigned int y:33; 
unsigned int z; 
} t; 
int main() 
{ 
printf("%ld\n", sizeof(t)); 
printf("%ld\n", sizeof(t.x)); 
//printf("%ld\n", sizeof(t.y)); 
printf("%ld\n", sizeof(t.z)); 
printf("%ld\n", sizeof(size_t)); 
return 0; 
}

