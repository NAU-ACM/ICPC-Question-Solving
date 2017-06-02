#include <bits/stdc++.h>

using namespace std;

string dec2bin(int x) {
	string result = "";
	
	while (x > 0) {
		result = char((x % 2) + '0') + result;
		x /= 2;
	}
	
	return result;
}

int main() {
	int n;
	
	while (cin >> n, n != 0) {
		string bin = dec2bin(n);
		bool alternate = true;
		int a = 0, b = 0, len = bin.length() - 1;
		
		for (int i = len; i >= 0; --i) {
			if (bin[i]=='1' && alternate) {
				a += pow(2, len-i);
				alternate = false;
			}
			else if (bin[i]=='1') {
				b += pow(2, len-i);
				alternate = true;
			}
		}
		
		cout << a << " " << b << endl;
	}
	
	return 0;
}
