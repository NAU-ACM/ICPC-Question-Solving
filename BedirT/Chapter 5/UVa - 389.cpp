#include <iostream>
#include <cstring>
#include <cmath>
// #include <fstream>
using namespace std;

int conv(char c){
	if(c - '0' < 10){
		return c - '0';
	}
	else{
		switch(c){
			case 'A':
				return 10;
			case 'B':
				return 11;
			case 'C':
				return 12;
			case 'D':
				return 13;
			case 'E':
				return 14;
			case 'F':
				return 15;
		}
	}
}

char convback(int c){
	if(c < 10){
		return c + '0';
	}
	else{
		switch(c){
			case 10:
				return 'A';
			case 11:
				return 'B';
			case 12:
				return 'C';
			case 13:
				return 'D';
			case 14:
				return 'E';
			case 15:
				return 'F';
		}
	}
}


int main () {

	string s;
	int a, b;

	while(cin >> s >> a >> b){
		long long norm = 0;
		for(int i = 0; i < s.size() ; ++i){
			int k = conv(s[i]);
			norm += k * pow(a, (s.size() - i - 1));
		}
		string res = "";
		cout.width(7);
		if(b == 10 || norm == 0) 
			if (norm > 9999999) cout << "ERROR" << endl;
			else cout << norm << endl;
		else if(b < 10){
			while(norm > 0){
				char ch = (norm % b + '0');
				res = ch + res;
				norm /= b;
			}
			if (res.size() > 7) cout << "ERROR" << endl;
			else cout << res << endl;
		} else {
			while (norm > 0) {
				res = convback(norm % b) + res;
				norm /= b;
			}
			if (res.size() > 7) cout << "ERROR" << endl;
			else cout << res << endl;
		}
	}
}
