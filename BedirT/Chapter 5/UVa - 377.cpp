#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
#include <fstream>
using namespace std;
string num1, num2, res;
char op;
string alph = "VUCD";
map<char, int> m;
void runA(){
	m['V'] = 0, m['U'] = 1, m['C'] = 2, m['D'] = 3;
	res = ""; int carry = 0;
	for(int i = num2.size()-1; i >= 0; --i){
		res = alph[(m[num1[i]] + m[num2[i]] + carry) % 4] + res;
		if(m[num1[i]] + m[num2[i]] + carry > 3) carry = 1;
		else 							carry = 0;
	}
	if(carry) res = 'U' + res;
	num2 = res;
}

void runL(){
	num2 += 'V';
}

void runR(){
	num2 = num2.substr(0, num2.size()-1);
	num2 = 'V' + num2;
}

void operate(){
	if(op == 'A') runA();
	else if(op == 'L') runL();
	else if(op == 'R') runR();
	num2 = num2.substr(num2.size()-8, num2.size());
	num1 = num1.substr(num1.size()-8, num1.size());
	// cout << num2 << endl;
}

int main (){
	int t;
	cin >> t;
	cout << "COWCULATIONS OUTPUT\n";
	while(t--){
		cin >> num1 >> num2;
		while(num2.size() < 8) num2 = 'V' + num2;
		while(num1.size() < 8) num1 = 'V' + num1;
		for(int i = 0; i < 3; ++i){
			cin >> op;
			operate();
		}
		cin >> res;
		// cout << num2 << endl;
		cout << ((res == num2) ? "YES\n" : "NO\n");
	}
	cout << "END OF OUTPUT\n";

}