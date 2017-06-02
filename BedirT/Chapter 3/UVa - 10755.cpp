#include <iostream>
#include <cstring>

using namespace std;
long long ar[21][21][21], d[21][21][21], sum;
int main (){
	
	int t, A, B, C;
	cin >> t;
	
	while(t--){
		cin >> A >> B >> C;
		memset(d, 0, sizeof d);

		for(int i = 1; i <= A; ++i)
			for(int j = 1; j <= B; ++j)
				for(int k = 1; k <= C; ++k){
					cin >> sum;
					sum += d[i][j-1][k] + d[i][j][k-1] + d[i-1][j][k];
					if(d[i][j-1][k] && d[i][j][k-1]) sum -= d[i][j-1][k-1];
					if(d[i-1][j][k] && d[i][j][k-1]) sum -= d[i-1][j][k-1];
					if(d[i][j-1][k] && d[i-1][j][k]) sum -= d[i-1][j-1][k];
					if(d[i][j-1][k] && d[i][j][k-1] && d[i-1][j][k])
						sum +=  d[i-1][j-1][k-1];
					d[i][j][k] = sum;
				}

		long long res = -99999999999;
		for(int i1 = 1; i1 <= A; ++i1)
			for(int i2 = i1; i2 <= A; ++i2)
				for(int j1 = 1; j1 <= B; ++j1)
					for(int j2 = j1; j2 <= B; ++j2)
						for(int k1 = 1; k1 <= C; ++k1)
							for(int k2 = k1; k2 <= C; ++k2){
								sum = d[i2][j2][k2];
								if (i1) sum -= d[i1-1][j2][k2];
								if (j1) sum -= d[i2][j1-1][k2];
								if (k1) sum -= d[i2][j2][k1-1];
								if (i1 && j1) sum += d[i1-1][j1-1][k2];
								if (j1 && k1) sum += d[i2][j1-1][k1-1];
								if (i1 && k1) sum += d[i1-1][j2][k1-1];
								if (i1 && j1 && k1) sum -= d[i1-1][j1-1][k1-1];
								res = max(res, sum);
							}

		cout << res << endl;
		if(t) cout << endl;
	}
}