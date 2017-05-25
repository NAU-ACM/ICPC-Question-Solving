/*
	Question: UVa - 11085
	Related Topic: Backtracking
	Author: BedirT
	Date: May 25, 2017
*/
#include <iostream>
using namespace std;

int q[9], past[9], t = 1;

bool check(int x, int y){
	for(int i = 1; i < y; ++i)
		if(past[i] == x || abs(i - y) == abs(past[i] - x)) return false;
	return true;
}

int backtrack(int y){

	if(y == 9) return 0;
	int tot = 10;
	for(int i = 1; i <= 8; ++i){
		if(check(i, y)){
			past[y] = i;
			tot = min(tot, (i == q[y]) ? backtrack(y + 1) : 1 + backtrack(y + 1));
		}
	}
	return tot;
}

int main () {
	while(cin >> q[1] >> q[2] >> q[3] >> q[4] >> q[5] >> q[6] >> q[7] >> q[8]){
		printf("Case %d: %d\n",t++, backtrack(1));
	}

}
