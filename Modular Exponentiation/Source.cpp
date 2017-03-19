#include <iostream>

#include <sstream>


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

int modExp(long b, long e, long m)
{
	long remainder;
	long x = 1;

	while (e != 0)
	{
		remainder = e % 2;
		e = e / 2;

		if (remainder == 1)
			x = (x * b) % m;
		b = (b * b) % m; // New base equal b^2 % m
	}
	//cout << 16 << endl;

	return x;

}

int power(int x, unsigned int y, int p)
{
	int res = 1;      // Initialize result

	x = x % p;  // Update x if it is more than or 
				// equal to p

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x*x) % p;
	}
	return res;
}

constexpr int powermod(int const B, int const E, int const M) {
	return ((E > 1) ? (powermod(B, E / 2, M) * powermod(B, E / 2, M) * powermod(B, E % 2, M)) % M
		: (E == 0) ? 1 : B % M);
}

int hexToInt(string z) {
	unsigned long x;
	//int val;

	std::stringstream ss;
	ss << std::hex << z;
	ss >> x;
	//val = (signed long)x;  
	return x;

}


int main() {
	
	string a,b,n;
	int z = 10;

	/*
	a = 00000001;
	b = 12345678;
	n = 12345678;

	a = 2;
	b = 3;
	n = 3;*/

	cout << "hex "<< hex << z << endl;
	
	do {
		cout << "Enter a: ";
		cin >> a;
		cout << "Enter b: ";
		cin >> b;
		cout << "Enter n: ";
		cin >> n;


		//cout << hexToInt(a) << endl;


		cout << power(hexToInt(a), hexToInt(b), hexToInt(n)) << endl;
	} while (a != "33");
	

	do {
		cout << "Enter a: ";
		cin >> a;
		cout << hexToInt(a) << endl;
	} while (a != "33");
	






}

