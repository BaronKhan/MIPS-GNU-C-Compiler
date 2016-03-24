#include <stdio.h>

int f_add(int a, int b);

int double_n(int n);

int result;

int main() {
	int x, y[20], i;
	x = f_add(4,2);
	y[10] = x;
	result = double_n(x);
	for (i=0; i < 6; i+=1) {
		x = i;
	}
	result += y[x+5];
	return result;
}

int f_add(int a, int b) {
	return a+b;
}

int double_n(int n) {
	return n*n;
}