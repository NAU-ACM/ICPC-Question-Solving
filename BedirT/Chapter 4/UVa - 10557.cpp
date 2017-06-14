#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#define INF 0xfffffff
#define maxN 101
using namespace std;
bool visited[maxN];
int t, n, e, m;
int energy[maxN], d[maxN];
vector<int> ar[maxN];

bool dfs(int x){
    visited[x] = true;
    for(int i = 0; i < ar[x].size(); ++i){
        int cur = ar[x][i];
        if(cur == n - 1) return true;
        if(!visited[cur] && dfs(cur)) return true;
    }
    return false;
}

int main () {
    
    // freopen("out.txt", "w", stdout);
    while(cin >> n && n != -1){

        for(int i = 1; i <= n; ++i){
            scanf("%d %d", &energy[i], &t);
            ar[i].clear();
            energy[i] *= -1;
            while(t--){
                cin >> e;
                ar[i].push_back(e);
            }
            d[i] = INF;
        }

        d[1] = -100;
        
        int counter = n-1, i , j, cur;
        
        for(int i = 0; i < n-1; ++i)
            for(int j = 1; j <= n; ++j)
                for(int k = 0; k < ar[j].size(); ++k){
                    int cur = ar[j][k];
                    if(d[j] + energy[cur] < 0) // WHY??
                        d[cur] = min(d[cur], d[j] + energy[cur]);
                }

        if(d[n] <= 0) goto win;
        for(int i = 1; i <= n; ++i)
            for(int j = 0; j < ar[i].size(); ++j){
                int cur = ar[i][j];
                if(d[i] + energy[cur] < 0 && d[i] + energy[cur] < d[cur]){
                    memset(visited, 0, sizeof(visited));
                    if(dfs(i)) goto win;
                }
            }
        goto lose;     
        
        lose: cout << "hopeless\n"; continue;
        win: cout << "winnable\n"; continue;
    }
    // fclose(stdout);
}