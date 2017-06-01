#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
long long d[101][101];
int main (){
	
	// freopen("output.txt" , "w", stdout);

	int t, n, m, k, ct = 1;
	cin >> t;
	
	while(t--){
		cin >> n >> m >> k;
		memset(d, 0, sizeof d);

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> d[i][j];
				if(i) d[i][j] += d[i-1][j];
				if(j) d[i][j] += d[i][j-1];
				if(i && j) d[i][j] -= d[i-1][j-1];
			}
		}
		
		long long res, mx = 0, d1 = 0, d2 = 0;
		for(int i1 = 0; i1 < n; ++i1)
			for(int j1 = 0; j1 < m; ++j1)
				for(int i2 = i1; i2 < n; ++i2)
					for(int j2 = j1; j2 < m; ++j2){
						mx = d[i2][j2];
						if(j1) mx -= d[i2][j1-1];
						if(i1) mx -= d[i1-1][j2];
						if(i1 && j1) mx += d[i1-1][j1-1];
						if(mx <= k && (i2-i1+1)*(j2-j1+1) >= d1*d2){
							if((i2-i1+1)*(j2-j1+1) == d1*d2 && res < mx);
							else res = mx;
							d1 = i2-i1+1, d2 = j2-j1+1;
						}
					}
		printf("Case #%d: %lld %lld\n", ct++, d1*d2, res);
	}

	// fclose(stdout);
}