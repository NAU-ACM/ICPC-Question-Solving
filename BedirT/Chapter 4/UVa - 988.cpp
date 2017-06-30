#include <iostream>
#include <vector>
using namespace std;

int main (){
	
	int n, a, k; bool flag = true;
	long long numberOfLife;
	vector<int> vc[100001];

	while(cin >> n && n){

		if(flag) flag = false;
		else cout << endl;

		for(int i = 0; i < n; ++i){
			cin >> k;
			while(k--){
				cin >> a;
				vc[i].push_back(a);
			}
		}

		vector<int> val(n, 0);
		numberOfLife = 0;
		val[0] = 1;

		for (int i = 0; i < n ; ++i){
			if(!vc[i].size()) numberOfLife += val[i];
			for(int v : vc[i]) val[v] += val[i];
		}

		cout << numberOfLife << endl;

		for(int i = 0; i < n; ++i) vc[i].clear();	
	}
}