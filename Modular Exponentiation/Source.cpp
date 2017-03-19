#include <iostream>
#include <bitset>
#include <sstream>
#include <string>



using namespace std;

long modulo(int a, string b, int n) {
	long result = 1;
	int count = 0;
	cout <<"length " << b.length() << endl;

	//for (int i = b.length(); i >= 1; i--) {
	for (int i = 0; i < b.length(); i++) {
		result = (result * result) % n;

		if (b[i] == '1') {
			count++;
			result = (result * a) % n;
		}
	}
	cout << "count is " << count << endl;
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

long hexToInt(string z) {
	unsigned long x;
	//int val;

	stringstream ss;
	ss << hex << z;
	ss >> x;
	long val;
	val = (signed long)x;  
	return val;

}
string intToString(int a) {
	string bin; 
	ostringstream convert;
	convert << a;
	bin = convert.str();

	return bin;
}

/*
int binary(int number) {
	int remainder;

	remainder = number % 2;
	return binary(number >> 1);    

	//return remainder;
}
*/

string hexToBin(string a) {

	stringstream ss;
	ss << hex << a;
	unsigned no;
	ss >> no;
	bitset<32> bo(no);  // outputs "00000000000000000000000000001010"
	//cout << bo.to_string() << endl;
	
	string binary = bo.to_string();
	binary.erase(0, binary.find_first_not_of('0'));
	return binary;
	

}
void printStr(string a){
	for (int i = 0; i < a.length(); i++) {
		cout << a[i];
	}
}


int main() {
	
	string a,b,n;

	/*
	string s = "7b";
	stringstream ss;
	ss << hex << s;
	unsigned no;
	ss >> no;
	bitset<32> bo(no);
	// outputs "00000000000000000000000000001010"
	cout << bo.to_string() << endl;*/



	string h = "77777777";
	string j = "34839432";
	string k = "23498834";


	cout << "hEX " << hexToInt(h) << endl;
	cout << "hEX " << hexToInt(j) << endl;
	cout << "hEX " << hexToInt(k) << endl;

	//string bins = intToString(j);

	//h = hexToInt(h);
	string bin = hexToBin(j);

	


	stringstream ss;
	ss << hex << j;
	unsigned no;
	ss >> no;
	bitset<32> bo(no);  // outputs "00000000000000000000000000001010"
	cout << bo.to_string() << endl;


	string our = hexToBin(j);
	printStr(our);
	cout << endl;

	cout << "Modulo = " << modulo(hexToInt(h) , bin , hexToInt(k) ) << endl;

	//cout << "hex "<< hex << z << endl;
	/*
	do {
		cout << "Enter a: ";
		cin >> a;
		cout << "Enter b: ";
		cin >> b;
		cout << "Enter n: ";
		cin >> n;

		string binary = hexToBin(b);

		//cout << hexToInt(a) << endl;

		cout << " Modulo = " << modulo(hexToInt(a), bin, hexToInt(n)) << endl;
		//cout << power(hexToInt(a), hexToInt(b), hexToInt(n)) << endl;
	} while (a != "33");
	

	do {
		cout << "Enter a: ";
		cin >> a;
		cout << hexToInt(a) << endl;
	} while (a != "33");
	
	*/





}

