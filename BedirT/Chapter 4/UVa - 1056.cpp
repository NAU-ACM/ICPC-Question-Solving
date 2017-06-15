#include <iostream>
#include <map>
#define inf 0xfffffff
using namespace std;
int ar[51][51], n, m, ct = 1;
bool flag = true;
map<string, int> mp;

int Warshall(){
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < n; ++k)
				ar[j][k] = min(ar[j][k], ar[j][i] + ar[i][k]);

	int res = -1;

	for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j){
			res = max(res, ar[i][j]);
		}

	return res;
}

int main () {
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	while(cin >> n >> m && n){

		for(int i = 0 ; i < n; ++i){
			for(int j = 0 ; j < n; ++j)
				ar[i][j] = inf;
			ar[i][i] = 0;
		}

		int cur = 0;
		for(int i = 0 ; i < m; ++i){
			string s1, s2;
			cin >> s1 >> s2;
			if(!mp[s1]) mp[s1] = ++cur;
			if(!mp[s2]) mp[s2] = ++cur;
			ar[mp[s1]-1][mp[s2]-1] = ar[mp[s2]-1][mp[s1]-1] = 1;
		}

		int fin = Warshall();

		cout << "Network " << ct++ << ": ";
		if(fin == inf) cout << "DISCONNECTED\n";
		else cout << fin << endl;
		cout << endl;

		mp.clear();
	}
	// fclose(stdin);
	// fclose(stdout);
}