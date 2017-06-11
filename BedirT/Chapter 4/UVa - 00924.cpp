#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <fstream>
#define max(x, y) x > y ? x : y
using namespace std;

void BFS(vector<vector<int> > ways, int strt){
	queue<int> holder;
	int line[10001], pos[10001];
	memset(line, -1, sizeof line);
    memset(pos, 0, sizeof pos);

	int maxDaily = 0, THEday, day = 0;

    line[strt] = 0;

    holder.push(strt);
    
    while (!holder.empty()) {
        
        int u = holder.front(), curr = 0;
        holder.pop();
        
        for (int i = 0; i < ways[u].size() ; ++i) {
            int v = ways[u][i];
            if (line[v] == -1) {
                line[v] = line[u] + 1;
                pos[line[u]]++;
                holder.push(v);
            }
        }

        if(pos[line[u]] > maxDaily)
            maxDaily = pos[line[u]], THEday = line[u] + 1;
    }

    if (ways[strt].size() == 0) cout << 0 << endl;
    else cout << maxDaily << " " << THEday << endl;
}

int main (){

    // freopen("write.txt", "w", stdout);

	int n, t;
    cin >> n;

	vector<vector<int> > vc;

	for(int i = 0, a, b; i < n; ++i){
		cin >> a;
        vector<int> temp; temp.clear();
		while(a--){
			cin >> b;
			temp.push_back(b);
		}
        vc.push_back(temp);
	}

	cin >> t;
	while(t--){
		int source; 
		cin >> source;
		BFS(vc, source);
	}

    // fclose(stdout);

}