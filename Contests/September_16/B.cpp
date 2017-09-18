#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main (){
	long long x , y;
	cin >> x >> y;
	long long res = 1, result = 1;
	while(y--){
		res *= 2;
		result += res;
	}
	// cout << result << endl;
	if (result >= x) cout << "yes\n";
	else cout << "no\n";
}
