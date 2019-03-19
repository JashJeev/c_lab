#include<stdio.h>
typedef union
{
    struct {
        unsigned char byte4;
        unsigned char byte3;
        unsigned char byte2;
        unsigned char byte1;
    } bytes;
    unsigned int dword;
} HW_Register;
HW_Register reg;


void main()
{
	reg.dword = 0xAABBCCDD;
	if (reg.bytes.byte1 == 0xAA)
		printf("Register enabled\n");
	printf("byte2 = 0x%x\n", reg.bytes.byte2);
}
