#include <iostream>
#include <fstream>
// #define debug
using namespace std;
int ar[1000005];
int main () {
	int t, n;
	cin >> t;
	#ifdef debug
		freopen("output.txt", "w", stdout);
	#endif
	for(int ct = 1; ct <= t; ++ct){
		cin >> n; int k = 0; n++; // for computing first step too
		ar[0] = 0;
		for(int i = 1; i < n; ++i) cin >> ar[i];
		for(int i = n-1; i >= 1; --i){
			int gap = ar[i] - ar[i-1];
			if(gap > k) k = gap;
			else if(k == gap) k++;
		}
		printf("Case %d: %d\n", ct, k);
	}
	#ifdef debug
		fclose(stdout);
	#endif
}
