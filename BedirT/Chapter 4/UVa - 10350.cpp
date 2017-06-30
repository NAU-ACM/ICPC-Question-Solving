#include <iostream>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;

int main () {

	int n, m;
	string s;
	int dist[100001];
	while(cin >> s){
		cin >> n >> m;

		memset(dist, inf, sizeof dist);
		for(int i = 0; i < m; ++i) dist[i] = 0;

		for(int i = 0; i < n - 1; ++i){
			for(int j = 0; j < m; ++j){
				for(int k = 0; k < m; ++k){
					int ct; 
					cin >> ct;
					int x = m * (i + 1) + k; 
					int y = m * i + j;
					dist[x] = min(dist[x], dist[y] + ct + 2);
				}
			}
		}
		
		int mn = inf;
		for (int i = n * m - m; i < n * m ; i++) {
			mn = min(mn, dist[i]);
		}
        
        cout << s << endl << mn << endl;
	}

}