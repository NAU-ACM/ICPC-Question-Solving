#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main () {

	while(1){
		int n;
		cin >> n;
		if(n == 0) break;
		map<vector<int>, int> mp;
		int mx = 1;
		for(int i = 0 ; i < n; ++i){
			vector<int> v(5);
			for(int j = 0; j < 5; ++j) cin >> v[j];
			sort(v.begin(), v.end());
			mp[v]++;
		}
		int counter = 0;
		for(map<vector<int>, int>::iterator it = mp.begin(); it != mp.end(); ++it){
			int a = it->second;
			if(a == mx){
				counter += a;
			}
		       	if(a > mx){
				mx = a;
				counter = mx;
			}
		}
		cout << counter << endl;
		
	}
}
