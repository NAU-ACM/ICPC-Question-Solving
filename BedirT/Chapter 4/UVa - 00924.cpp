#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define max(x, y) x > y ? x : y
using namespace std;

void BFS(vector<vector<int> > ways, int strt){
	queue<int> holder;
	int line[1001];
	memset(line, -1, sizeof line);

	int maxDaily = 0, THEday, day = 0;

    line[strt] = 0;

    holder.push(strt);
    
    while (!holder.empty()) {
        
        int u = holder.front();
        holder.pop();
        
        for (int i = 0; i < ways[u].size() ; ++i) {
            int v = ways[u][i];
            if (line[v] == -1) {
                // cout << v << " ";
                line[v] = line[u] + 1;
                holder.push(v);
            }
        }
        day++;
        if(maxDaily < holder.size()){
        	maxDaily = holder.size();
        	THEday = day;
        }
    }
    if (ways[strt].size() == 0) cout << 0 << endl;
    else cout << maxDaily << " " << THEday << endl;
}

int main (){

	int n, t;
	cin >> n;

	vector<vector<int> > vc(n);

	for(int i = 0, a, b; i < n; ++i){
		cin >> a;
		while(a--){
			cin >> b;
			vc[i].push_back(b);
		}
	}

	cin >> t;
	while(t--){
		int source; 
		cin >> source;
		BFS(vc, source);
	}

}