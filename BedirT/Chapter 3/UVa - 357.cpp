/*
	Question: UVa - 357
	Related Topic: Dynamic, Coin Change
	Author: BedirT
	Date: May 29, 2017
*/

#include <iostream>
using namespace std;
long long d[30001];
int coins[] = {1, 5, 10, 25, 50}, n = 30000;

int main () {
	
	// Coin Change algo...
	d[0] = 1;
	for(int i = 0; i < 5; ++i)
		if(coins[i] <= n)
			for(int j = coins[i]; j <= n; ++j)
				d[j] += d[j-coins[i]];

	while(cin >> n){
		if(n < 5) printf("There is only 1 way to produce %d cents change.\n", n);
		else printf("There are %lld ways to produce %d cents change.\n", d[n], n);
	}
}