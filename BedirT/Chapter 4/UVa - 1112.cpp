#include <iostream>
#include <vector>
#include <cstring>
#define INF 0xfffffff
using namespace std;
int ar[101][101], d[101];

bool djikstra(int n, int s, int end, int time){
	bool visited[101];
	for(int i = 0; i <= n; ++i) d[i] = INF, visited[i] = false;
	d[s] = 0;
	for(int ct = 0; ct < n ; ++ct){
		for(int i = 1; i <= n; ++i)
			if(ar[s][i] != -1 && d[i] > d[s] + ar[s][i])
				d[i] = d[s] + ar[s][i];
			
		visited[s] = true;

		int mn = INF;
		for(int i = 1; i <= n; ++i)
			if(mn > d[i] && !visited[i])
				mn = d[i], s = i;
	}

	if(d[end] <= time) return true;
	else return false;
}

int main () {
	int t, n, e, time, m;
	scanf("%d", &t);
	while(t--){
		scanf("\n%d %d %d %d", &n, &e, &time, &m);

		memset(ar, -1, sizeof ar);

		for(int i = 0, a, b, w; i < m; ++i){
			scanf("%d %d %d", &a, &b, &w);
			ar[a][b] = w;
		}

		int res = 0;
		for(int i = 1; i <= n; ++i)
			if(djikstra(n, i, e, time))
				res++;

		printf("%d\n", res);
		if(t) cout << endl;
	}
}