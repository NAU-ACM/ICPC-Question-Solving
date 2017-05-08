
#include <iostream>
#include <vector>
using namespace std;

int main (){
	int n, t, a, k;
	vector<int> vc;
	cin >> t;
	while(t--){
		cin >> k >> n;
		bool ok = false;
		for(int i = 0; i < n; ++i){
			cin >> a;
			if(vc.size() == 0 || vc.back() != k){
				vc.push_back(a);
				int sz = vc.size();
				for(int j = 0; j < sz-1 ; ++j){
					if(a + vc[j] <= k) vc.push_back(a + vc[j]);
					if(vc.back() == k){
						ok = true; break;
					}
				}
			}
		}
		if(!ok && k != 0) cout << "NO\n";
		else cout << "YES\n";
		vc.clear();
	}
}

