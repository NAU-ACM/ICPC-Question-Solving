#include <iostream>
#include <vector>
#include <fstream>
#define inf 0xfffffff
using namespace std;
int cost, n;
char age, dir, a, b;
vector<pair<int, int> > city[2][26]; // 2 dimension : 1 for first graph one for the other
int d[2][26]; // 2D again for same reason
char s[2]; // 2 size again for same reason

void addToGraph(int x, int y){
    city[x][y].push_back(make_pair(cost, b - 65));
    if(dir == 'B') // If the graph is bidirectional
        city[x][b - 65].push_back(make_pair(cost, y));
}

void fordBellman(int x){ // Ford Bellman
    
    for(int i = 0; i < 26 ; ++i) d[x][i] = inf;

    d[x][s[x] - 65] = 0;

    vector<pair<int,int> >::iterator it;
    for(int i = 0; i < 25; ++i)
        for(int j = 0; j < 26; ++j)
            for(it = city[x][j].begin(); it != city[x][j].end() ; ++it){
                int k = (*it).first; // cost
                int dest = (*it).second; // destination city
                d[x][dest] = min(d[x][dest], d[x][j] + k);
            }
}

int main(){
    
    // freopen("out.txt", "w" , stdout);
    while(cin >> n && n){

        for(int i = 0; i < 26; ++i)
            city[0][i].clear(), city[1][i].clear();

        for(int i = 0; i < n; ++i){
            cin >> age >> dir >> a >> b >> cost;
            if(age == 'Y') addToGraph(0, a - 65);
            if(age == 'M') addToGraph(1, a - 65);
        }
        
        cin >> s[0] >> s[1]; // start, end

        fordBellman(0);
        fordBellman(1);

        vector<char> res;
        int resNum = inf;
        for(int i = 0; i < 26; ++i){
            if(d[0][i] != inf && d[1][i] != inf){
                if(d[0][i] + d[1][i] < resNum){
                    res.clear();
                    res.push_back((char)(i+65));
                    resNum = d[0][i] + d[1][i];
                }
                else if(d[0][i] + d[1][i] == resNum)
                    res.push_back((char)(i+65));
            }
        }

        if(res.size()){
            cout << resNum << " ";
            for(int i = 0; i < res.size() ; ++i)
                cout << res[i] << (i != res.size()-1 ? " " : "\n") ;
        } 
        else cout << "You will never meet.\n";
    }
    // fclose(stdout);
}