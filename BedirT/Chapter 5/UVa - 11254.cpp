#include <iostream>
#include <cmath>
using namespace std;

int main (){
	int n;

	while(cin >> n && n != -1){
		int s = -1, r = -1;
		for (int i = sqrt(2*n); i >= 1; i--){
			int x = (2 * n + i - i * i) / (2 * i);
			if(i * (2 * x + (i-1)) == 2 * n){
				s = x, r = i;
				break;
			}
		}
		printf("%d = %d + ... + %d\n", n, s, s+r-1);
	}
}