int main() {
	int x = 5;
	int y = x+10;
	return (x+y & y | 1)*(x^x+4); 
}