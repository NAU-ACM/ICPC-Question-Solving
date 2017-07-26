#include <iostream>
#include <queue>
using namespace std;
char grid[11][11];
bool vis[11][11], done;
int n, ct = 1, ans = 0;
char letter, goal;

void BFS(int s1, int e1){

    queue<pair<int ,pair<int, int> > > q;

    q.push({0, {s1, e1}});

    int trace[4][2] = {{1,0}, {0,1}, {-1,0}, {0, -1}};
	done = false;	

    while(!q.empty()){

    	int x = q.front().second.first;
    	int y = q.front().second.second;
    	int len = q.front().first;
    	q.pop();

		for(int i = 0; i < 4; ++i){
			
			int nX = x + trace[i][0];
            int nY = y + trace[i][1];

            if (nX >= 0 && nY >= 0 && nX < n && nY < n && !vis[nX][nY]){
            	vis[nX][nY] = true;

            	if(grid[nX][nY] == '.');
            	else if(grid[nX][nY] == letter){
            		ans += len + 1;
					
					if(letter == goal) done = true, break;
					
					food++;
					
					while(!q.empty()) q.pop();

					memset(vis, false, sizeof vis);
					vis[nX][nY] = true;

					q.push({0 , {nX,nY}});
					break;
            	}
            	else continue;
            }
            q.push({len + 1, {nX, nY}});   
    	}
    }
}

void fin(){
	
}

int main (){

	while(cin >> n, n){
		int st1, st2;
		
		letter = 'B', totNum = 0;
		goal = 'A'+ n - 1;
		distRes = 0x3f3f3f3f;
		int letP[27][2]; // Letter Places; Keeps the data of letter coordinates, x-y

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j){
				cin >> grid[i][j];
				if(isAlpha(grid[i][j])){
					letP[grid[i][j] - '65'][0] = i;
					letP[grid[i][j] - '65'][1] = j; 
				}
			}

		BFS(letP[0][0], letP[0][1]);
		fin();

		if(done) 	printf("Case %d: %d %d\n", ct++, distRes, totNum);
		else 		printf("Case %d: Impossible\n", ct++);
	}

}