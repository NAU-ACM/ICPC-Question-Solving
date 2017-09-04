#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;

int main (){
	// freopen("out.txt", "w", stdout);
	int n, k;
	int ar[10005];
	while(cin >> n >> k && n != -1){
		
		for(int i = n; i >= 0 ; --i)
			cin >> ar[i];

		for(int i = 0; i <= n-k; ++i){
			ar[i+k] -= ar[i];
			ar[i] = 0;
		}
			
		int cur = 0;
		while(ar[cur] == 0 && cur <= n) cur++;

		if(n < cur) cout << "0";

		for(int i = n; i >= cur; --i){
			if(i != n) cout << " ";
			cout << ar[i];
		}
		cout << endl;
	}
	// fclose(stdout);
}