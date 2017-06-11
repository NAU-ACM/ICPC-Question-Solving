#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
struct node{
	int x, y, v;
	node (int a, int b, int w){
		x = a, y = b, v = w;
	}
};

vector<node> vc;
vector<int> res;
int parent[10001];

void Union(int x, int y){
	if(x > y) parent[y] = x;
	else parent[x] = y;
}

int find(int x){
	if(parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

int cmp(node x, node y){
	return x.v < y.v;
}

int main (){
	
	int n, m;
	// freopen("out.txt", "w", stdout);
	while(cin >> n >> m && n){
	
		for(int i = 0; i <= n; ++i) parent[i] = i;
		vc.clear(); res.clear();
	
		for(int i = 0 ; i < m; ++i){
			int a, b, w;
			cin >> a >> b >> w;
			vc.push_back(node(a,b,w));
		}
	
		sort(vc.begin(), vc.end(), cmp);

		// MST
		for(int i = 0; i < m; ++i){
			int x = find(vc[i].x);
			int y = find(vc[i].y);

			if(x == y) res.push_back(vc[i].v);
			else Union(x, y);
		}
		//

		if(res.size() == 0) cout << "forest\n";
		else{
			for(int i = 0; i < res.size() ; ++i)
				cout << res[i] << (res.size()-1==i ? "\n" : " ");
		}
	}
	// fclose(stdout);
}