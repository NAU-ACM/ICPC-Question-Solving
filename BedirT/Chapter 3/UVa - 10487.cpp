#include <iostream>
#include <cstring>
#define INF 0xfffffff
using namespace std;
int ar[1005];

int main (){
	int a, n, m, k =1;
	while(cin >> n){
		if (n == 0) return 0;
		for(int i = 0; i < n; ++i){
			cin >> ar[i];
		}
		cout << "Case " << k++ << ":\n";
		cin >> m;
		while(m--){
			cin >> a;
			cout << "Closest sum to " << a;
			int close = -INF;
			for(int i = 0; i < n; ++i){
				 for(int j = i+1; j < n; ++j){
				 	if(abs(a - ar[i] - ar[j]) < abs(a - close)){
						close = ar[i] + ar[j];
						if(close == 0) break;
					}
				 }
			}
			cout << " is " << close << ".\n";
		}
		memset(ar, 0, n);
	}
}
