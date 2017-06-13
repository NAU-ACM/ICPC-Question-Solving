#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#define maxN 5001
#define INF 0xfffffff
using namespace std;
vector<string> ar[maxN][maxN];
int d[maxN];
string start, finish, a, b, k;
int n, cur;
map<string, int> exist;

int main () {

	// freopen("out.txt", "w", stdout);

	while(cin >> n && n){
		cin >> start >> finish;
		exist[start] = 1;
		exist[finish] = 2;
		int cur = 3, cur2 = 0;

		for(int i = 0; i < n; ++i){
			cin >> a >> b >> k;
			if(!exist[a]) exist[a] = cur, cur++;
			if(!exist[b]) exist[b] = cur, cur++;
			ar[exist[a]][exist[b]].push_back(k);
			ar[exist[b]][exist[a]].push_back(k);
			// cout << exist[a] << " " << exist[b] << " " << k << endl;
		}
 
		// DJIKSTRA /////////////////
		bool visited[maxN];
	    for(int i = 1; i < cur; ++i) d[i] = INF, visited[i] = false;
	    int s = 2;
	    d[s] = 0;
	    char letter[2001] = {};
	    letter[s] = 'A';
	    for(int ct = 1; ct < cur ; ++ct){
	        for(int i = 1; i < cur; ++i){
	        	// cout << ar[s][i].size() << endl;
	            if(ar[s][i].size()) for(int j = 0; j < ar[s][i].size(); ++j){
	            	if(d[i] >= d[s] + ar[s][i][j].size() && letter[s] != ar[s][i][j][0]){
	            		// cout << ct << " " << i << " " << d[s] + ar[s][i][j].size() << endl;
		                d[i] = d[s] + ar[s][i][j].size();
		                letter[i] = ar[s][i][j][0];
	            	}
	            }
	 		}
	            
	        visited[s] = true;

	        int mn = INF;
	        for(int i = 1; i < cur; ++i)
	            if(mn > d[i] && !visited[i])
	                mn = d[i], s = i;
	    }                            
	    ///////////////////////////////

	    if(d[1] != INF) cout << d[1] << endl;
	    else cout << "impossivel\n";

	    for(int i = 0; i < cur; ++i) for(int j = 0; j < cur; ++j) ar[i][j].clear();
	    exist.clear();
	}
	// fclose(stdout);

}