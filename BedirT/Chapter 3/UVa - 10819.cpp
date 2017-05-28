/*
	Question: UVa - 10819
	Related Topic: Knapsack, DP
	Author: BedirT
	Date: May 28, 2017
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int knapsack(int C, int n, int * p, int * val){ // C is capacity, n is size
												// p is prices, and val is value
	int d[15000], res = 0;
	bool was[15000];
	
	memset(d, 0, sizeof d); 
	memset(was, 0, sizeof was);

	was[0] = true; // Initial starting point 

	for(int i = 1; i <= n; ++i)
		for(int j = C+200; j >= 0; --j)
			if(was[j]){
				was[j + p[i]] = true;
				d[j + p[i]] = max(d[j + p[i]], d[j] + val[i]);
			}
	
	
	for(int i = 0 ; i <= C ; ++i)
		res = max(res, d[i]);	

	if(C > 1800) // Since 1800 - 2000 Doesn't matter, because we will have at least 2001$
		for (int i = 2001; i <= C+200; ++i) // We start the loop from 2001
			res = max(res, d[i]);

	return res;
    
}

int main (){
	int m, n, price[200], fav[200]; 

	while(cin >> m >> n){ // EOF 

		for(int i = 1; i <= n; ++i)
			cin >> price[i] >> fav[i]; // Input

		cout << knapsack(m, n, price, fav) << endl; 

	}

}