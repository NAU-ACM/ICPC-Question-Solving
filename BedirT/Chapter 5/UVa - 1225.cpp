#include <iostream>
#include <cstring>
using namespace std;
int dig[10];

void addDigits(int x){
	while(x > 0){
		dig[x%10]++;
		x /= 10;
	}
}

int main (){
	int t, n;
	cin >> t;
	while(t--){
		memset(dig, 0, sizeof dig);
		cin >> n;
		for(int i = 1; i <= n; ++i)
			addDigits(i);
		for(int i = 0; i < 10; ++i)
			cout << dig[i] << (i == 9 ? "\n" : " ");
	}
}