#include <iostream>
#include <cmath>
using namespace std;

int main () {
	string s;
	while(cin >> s){
		if(s[0] == '0' && s[1] == 0) return 0;
		int rem = 0;
		for(int i = 0; s[i]; ++i)
			rem = ( rem * 10 + s[i] - 48 ) % 17;
		cout << (rem ? "0\n" :"1\n");
	}
}
