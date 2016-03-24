#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 4|0xFF;
	int b = 20;
	return ((a==5) || (b == 20));
}
