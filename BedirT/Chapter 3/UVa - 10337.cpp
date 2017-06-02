#include <iostream>
#include <cstring>
using namespace std;
int n , t, ar[10][10001], d[10][10001];

int main (){
	cin >> t;
	while(t--){
		
		scanf("\n%d", &n);

		memset(ar, 0, sizeof ar);

		for(int i = 9; i >= 0; --i)
			for(int j = 0; j < n/100; ++j){
				cin >> ar[i][j];
			}
			// Input array constructed
			// Initial values added to d
		
		for(int i = 0; i < 10; ++i){
			d[i][0] = 0;
			for(int j = 1; j <= n/100+1; ++j)
				d[i][j] = 0xfffffff;
		}


		for(int j = 0; j <= n/100+1; ++j)
			for(int i = 0; i < 10; ++i){
				d[i][j+1] = min(d[i][j+1], d[i][j] - ar[i][j+1] + 30);
				if(i != 9) d[i+1][j+1] = min(d[i+1][j+1], d[i][j] - ar[i+1][j+1] + 20);
				if(i != 0) d[i-1][j+1] = min(d[i-1][j+1], d[i][j] - ar[i-1][j+1] + 60);
			}

		// for(int i = 0; i < 10; ++i){
		// 	for(int j = 0; j <= n/100+1; ++j){
		// 		cout << d[i][j] << " ";
		// 	}cout << endl;
		// }

		int res = 0;
		for(int i = 0; i < 10; ++i) res = min(res, d[i][n/100]);
		cout << res << endl;
		if(t) cout << endl; 
	
	}
}