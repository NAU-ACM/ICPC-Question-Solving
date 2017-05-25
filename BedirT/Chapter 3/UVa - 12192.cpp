/*
    Question Name: 12192 - Grapevine
    Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3344
    Topic: Divide & Conquer
    Algo Used: Binary Search (lower_bound)
    Author: BedirT
    Date: 2016 ...
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, q, arr[501][501], low, high, maxx, mIdx;

int main () {

	cin >> n >> m;
	while(n != 0 && m != 0){
		for(int i = 0 ; i < n ; ++i)
			for(int j = 0 ; j < m ; ++j)
				cin >> arr[i][j];

		cin >> q;
		while(q--){
			cin >> low >> high;
			maxx = -1;
			for (int i = 0; i < n; ++i){
				mIdx = lower_bound(arr[i] , arr[i]+m, low) - arr[i];
				for (int j = 0; j < n; ++j){
					if(arr[i+j][mIdx+j] > high || i+j >= n || mIdx+j >= m) break;
					if(j >= maxx) maxx = j;
				}
			}
			cout << maxx+1 << endl;
		}
		cout << "-" << endl;
		cin >> n >> m;
	}

}