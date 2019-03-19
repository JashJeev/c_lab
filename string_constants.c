#include <stdio.h>

const char * const a[2] = {[1] ="abc", [0] = "def",};


void main() {
printf("%s\n",a[0]);
printf("%s\n",a[1]);
}

