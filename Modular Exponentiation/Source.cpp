#include <iostream>

using namespace std;

int modulo(int a, int b, int n) {
	int result;
	result = 1;
	for (int i = 0; i < b; i++) {
		//a = (a*a) % n;
		result = (a * result) % n;
	}
	return result;
}

int modExp(int b, int e, int m)
{
	int remainder;
	int x = 1;

	while (e != 0)
	{
		remainder = e % 2;
		e = e / 2;

		if (remainder == 1)
			x = (x * b) % m;
		b = (b * b) % m; // New base equal b^2 % m
	}
	return x;
}


int main() {
	
	int a, b, n;
	a = 00000001;
	b = 12345678;
	n = 12345678;

	a = 2;
	b = 3;
	n = 3;


	cout << modExp(a, b, n);

	

}