#include <iostream>
using namespace std;
int g[3][3];

void f() {
	int h[3][3];

	h[0][0] = (g[0][1] + g[1][0]) % 2;
	h[0][1] = (g[0][0] + g[1][1] + g[0][2]) % 2;
	h[0][2] = (g[0][1] + g[1][2]) % 2;

	h[1][0] = (g[0][0] + g[1][1] + g[2][0]) % 2;
	h[1][1] = (g[0][1] + g[1][0] + g[1][2] + g[2][1]) % 2;
	h[1][2] = (g[1][1] + g[0][2] + g[2][2]) % 2;

	h[2][0] = (g[2][1] + g[1][0]) % 2;
	h[2][1] = (g[2][0] + g[1][1] + g[2][2]) % 2;
	h[2][2] = (g[2][1] + g[1][2]) % 2;

	for (int i=0; i < 3; i++) 
		for (int j=0; j < 3; j++) 
			g[i][j] = h[i][j];
}

bool isZero() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (g[i][j] > 0)
				return false;
		}
	}
	return true;
}

int main() {
	int t; cin >> t;

	while (t--) {
		for (int i=0; i < 3; i++) {
			string s; cin >> s;
			for (int j=0; j < 3; j++) 
			 	g[i][j] = s[j]-'0';
		}

		int ind = -1;
		while (!isZero()) {
			f();
			ind++;
		}
		cout << ind << endl;
	}

	return 0;
}