#include <iostream>
#include <cstring>
using namespace std;
int main () {
	int T, n, a, ar[101];
	cin >> T;
	int ct = 1;
	while(T--){
		cin >> n;
		bool ok = true;
		memset(ar, 0 , sizeof(ar));
		for(int i = 0; i < n ; ++i){
			for(int j = 0; j < n; ++j){
				cin >> a;
				ar[a]++;		
			}
		}
		for(int i = 0; i < n; ++i){
			if(ar[i] > n){
				ok = false;
				break;
			}
		}
		cout << "Case " << ct++ << ": " << (ok ? "yes\n" : "no\n"); 
	}

}
