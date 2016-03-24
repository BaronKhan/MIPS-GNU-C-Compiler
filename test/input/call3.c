#include <stdio.h>


int add_f(int a, int b) {
        return a+b;
}

int mul_add_f(int a, int b, int c) {
	return a*b+c;
}

int four_times_five() {
	return 4*5;
}

int main() {
        int i = four_times_five();
	i = add_f(i, i);
	i = mul_add_f(i,3,4);
	return i;
}

