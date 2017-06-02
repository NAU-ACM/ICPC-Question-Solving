#include <vector>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int ar[50001], dfsRes[50001];
bool was[50001];

int dfs(int x){
    was[x] = true;
    int res = 0;
    if(ar[x] && !was[ar[x]])
        res += 1 + dfs(ar[x]);
    was[x] = false;
    return dfsRes[x] = res;
}

int main () {

    // freopen("output.txt", "w", stdout);

    int t, ct = 1, n, a , b, ans, val;
    cin >> t;
    while(t--){
        cin >> n;

        memset(ar, 0, sizeof n+1);
        memset(was, false, sizeof n+1);

        int mx = -1;
        for(int i = 1; i <= n; ++i){
            cin >> a >> b;
            ar[a] = b;
            dfsRes[i] = -1;
        }

        for(int i = 1; i <= n; ++i){
            if(dfsRes[i] == -1) val = dfs(i);
            else val = dfsRes[i];
            if(mx < val){
                mx = val;
                ans = i;
            }
        }

        printf("Case %d: %d\n", ct++, ans);

    }

    // fclose(stdout);

}