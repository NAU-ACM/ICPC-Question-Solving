#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
using namespace std;

int main () {

	int n;
	cin >> n;
	while(n != 0){
		string bin = bitset<32>(n).to_string();
		int a = 0, b = 0;
		bool flag = true;
		for(int i = 0 ; i < 32; ++i){
			if(bin[31-i] == '1' && flag){
				a += pow(2, i);
				flag = false;
			}else if(bin[31-i] == '1'){
				b += pow(2, i);
				flag = true;
			}
		}
		cout << a << " " << b << endl;
	       	cin >> n;	
	}

}
