#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int itoa(unsigned long int num, char *str)
{
	int i, len = 0;


	for (i = 0; num > 0; i++) {
		str[i] = (num % 10) + '0';
		len++;
		num = num / 10;
	}
	len --;
	for (i = 0; i <= len/2 ;i++) {
		char c;

		c = str[i];
		str[i] = str [len - i];
		str[len - i] = c;
	}
	str[len+1] = '\0'; 
	return len + 1 ;
}
void main()
{
	unsigned long int prg_brk1, prg_brk2, prg_brk3, len;
	char str1[25], str2[25];
	prg_brk1 = sbrk(10);
	len = itoa(prg_brk1, str1);
	write(1, &str1, len + 1);
	write(1, "\n", 2);
	prg_brk2 = sbrk(0);
	len = itoa(prg_brk2, str2);
	write(1, str2, len + 1);
	write(1, "\n", 2);
}
