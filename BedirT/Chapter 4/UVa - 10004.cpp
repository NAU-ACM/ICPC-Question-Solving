#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<vector<int> > ways;

int colored[201];
int n, m, a, b;

bool paint(int x, int c, int parent){

    if(colored[x] == -1){
        colored[x] = (c+1) % 2;
    }
    if(ways[x].size() > 0){
        int myColor = colored[x];
        for (vector<int>::iterator i = ways[x].begin(); i != ways[x].end(); ++i) {
            if(colored[*i] == -1){
                if(parent != *i && !paint(*i, myColor, x)){
                    return false;
                }
            }
            else if(colored[*i] == myColor){
                return false;
            }
        }
    }
    return true;
}

int main(){

    // freopen("out.txt", "w", stdout);
    while(cin >> n && n != 0){
        cin >> m;
        ways.clear(); ways.resize(n);
        for (int i = 0 ; i < m ; ++i) {
            cin >> a >> b;
            ways[a].push_back(b);
            ways[b].push_back(a);
        }
        
        memset(colored, -1, sizeof colored);
        
        if(paint(0, 1, -1)) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
    // fclose(stdout);
}