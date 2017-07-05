#include <iostream>
#include <cmath>
using namespace std;

int main () {
	
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		if(n == 1) printf("0.000\n");
		else printf("%.3f\n", sqrt(2) * (n-2) * (n-2) + 4 * (n-1));
	}
}