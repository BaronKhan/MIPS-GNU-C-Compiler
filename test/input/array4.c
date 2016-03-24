#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[10], b[20], x;
	a[1] = 5;
	b[3] = 2;
	x = b[3]+a[1]+b[a[1]-2];
	return x;
}
