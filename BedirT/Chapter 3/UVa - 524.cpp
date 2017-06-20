/*
	Question: UVa - 00524
	Related Topic: Backtrack
	Author: BedirT
	Date: 05/25/2017
*/
#include <iostream>
#include <bitset>
#include <vector>
#include <fstream>
// #define debug
using namespace std;
int primes[11] = {2,3,5,7,11,13,17,19,23,29,31}, n, cycle[20];
bitset<20> used;

bool isPrime (int num) {
	for(int i = 0; i < 11; ++i)
		if(num == primes[i]) return true;
	return false;
}

bool beans (int pos, int x) {
	if(pos == n-1 && isPrime(x + cycle[0]) && isPrime(x + cycle[pos-1])) return true; 
	else if(pos != n-1 && isPrime(x + cycle[pos-1])) return true;
	else return false;
}

void backtrack (int x) {
	if(x == n){
		for(int i = 0; i < n; ++i){
			cout << cycle[i] << (i == n-1 ? "\n" : " ");
		} return;
	}
	for(int i = 2; i <= n; ++i){
		if(!used[i] && beans(x, i)){
			used[i] = 1;
			cycle[x] = i;
			backtrack(x+1);
			used[i] = 0;
		}
	}
}

int main () {
	int t = 1;
	#ifdef debug
		freopen("output.txt", "w", stdout);
	#endif
	while(cin >> n){
		if(t != 1) cout << endl;
		printf("Case %d:\n", t++);
		used[0] = cycle[0] = 1;
		backtrack(1);
	}
	#ifdef debug
		fclose(stdout);
	#endif
}