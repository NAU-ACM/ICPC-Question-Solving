#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<bool> v(n, 0);

		int num1; cin >> num1;
		for (int i=0; i < n-1; i++) {
			int num2; cin >> num2;
			if (abs(num2-num1) < n)
				v[abs(num2-num1)] = 1;
			num1 = num2;
		}

		bool jolly = true;
		for (int i=1; i < n; i++) 
			if(v[i] == 0) {
				jolly = false;
				break;
			}
		cout << (jolly?"Jolly":"Not jolly") << endl;
	}
}