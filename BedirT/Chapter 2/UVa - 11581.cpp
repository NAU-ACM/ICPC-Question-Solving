/*
	Question: UVa - 11581
	Related Topic: -
	Author: BedirT
	Date: 05/27/2017
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int g[2][3][3]; string s;

void f() {

	g[1][0][0] = (g[0][0][1] + g[0][1][0]) % 2;
	g[1][0][1] = (g[0][0][0] + g[0][1][1] + g[0][0][2]) % 2;
	g[1][0][2] = (g[0][0][1] + g[0][1][2]) % 2;

	g[1][1][0] = (g[0][0][0] + g[0][1][1] + g[0][2][0]) % 2;
	g[1][1][1] = (g[0][0][1] + g[0][1][0] + g[0][1][2] + g[0][2][1]) % 2;
	g[1][1][2] = (g[0][1][1] + g[0][0][2] + g[0][2][2]) % 2;

	g[1][2][0] = (g[0][2][1] + g[0][1][0]) % 2;
	g[1][2][1] = (g[0][2][0] + g[0][1][1] + g[0][2][2]) % 2;
	g[1][2][2] = (g[0][2][1] + g[0][1][2]) % 2;

	for (int i=0; i < 3; i++) 
		for (int j=0; j < 3; j++) 
			g[0][i][j] = g[1][i][j];
}

bool done(){
	for(int i = 0;i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			if(g[0][i][j] != 0) return false;
	return true;
}

int main (){
	int t; cin >> t;
 	while(t--) {
 		scanf("\n");
		for (int i = 0; i < 3; ++i) {
			cin >> s;
			for (int j = 0; j < 3; ++j) 
				g[0][i][j] = s[j]-'0';
		}

		int res = -1; 
		while (!done()) {
			f();
			res++;
		}
		cout << res << endl;
    }

}
