#include <iostream>
#include <cstring>
using namespace std;

int main () {

	int t, n, a, ct = 1;
	int counter[105];
	cin >> t;
	while(t--){
		cin >> n;
		memset(counter, 0, sizeof counter);
		bool ok = true;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> a;
				if(++counter[a] > n)
					ok = false;
			}
		}
		cout << "Case " << ct++ << (ok ? ": yes\n" : ": no\n");
	}
}
