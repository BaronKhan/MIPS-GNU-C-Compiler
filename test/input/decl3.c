#include <stdio.h>

int i = 5;

int add_f(int a, int b);


int main() {
        i = add_f(4, 2);
	return i;
}

int add_f(int a, int b) {
        return a+b;
}

