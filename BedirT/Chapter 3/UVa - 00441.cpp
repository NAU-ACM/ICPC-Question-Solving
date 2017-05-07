#include <iostream>
#include <cstring>
#define INF 0xfffffff
using namespace std;
int ar[50];
int main (){
	int n;
	cin >> n;
	while(1){
		if(n == 0) return 0;
		memset(ar, 0, n);
		for(int i = 0; i < n; ++i) cin >> ar[i];
		for(int i = 0; i < n-5; ++i){
			for(int j = i+1; j < n-4; ++j){
				for(int k = j+1; k < n-3; ++k){
					for(int l = k+1; l < n-2; ++l){
						for(int m = l+1; m < n-1; ++m){
							for(int f = m+1; f < n; ++f){
								printf("%d %d %d %d %d %d\n", ar[i],ar[j],ar[k],ar[l],ar[m],ar[f]);
							}
						}
					}
				}
			}
		}
		cin >> n;
		if(n != 0) cout << endl;
	}
}	
