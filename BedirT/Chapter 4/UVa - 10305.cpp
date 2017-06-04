#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
bool visited[150];
vector<vector<int> > way;
vector<int> vc;

void topological_sort(int x){
    for(int i = 0; i < way[x].size(); ++i)
        if(!visited[way[x][i]])
        	topological_sort(way[x][i]);
	visited[x] = true;        
    vc.insert(vc.begin(), x+1);
}

int main (){
	int m, a, b, n;

	// freopen("output.txt", "w", stdout);
	while(cin >> n >> m && n != 0){
		
		way.clear();
		way.resize(n);
		vc.clear();
		memset(visited, false, sizeof visited);

		for(int i = 0; i < m; ++i){
			cin >> a >> b;
			way[a-1].push_back(b-1);
		}

		for(int i = 0; i < n; ++i){
			if(!visited[i])
				topological_sort(i);
		}

		cout << vc[0];
		for (int i = 0; i < vc.size(); i++)
			cout << " " << vc[i];
		cout << endl;
	}
	// fclose(stdout);
}