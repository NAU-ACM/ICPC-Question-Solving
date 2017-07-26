// Citizen Attention
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define INF 0x7fffffff
struct population {int idx,val;} pop[5];

int distXY(int x, int y) {
	return abs(x%5-y%5) + abs(x/5-y/5);
}

int dist(int x, int i, int j, int k, int l, int m) {
	int mn = distXY(x, i);
	mn = min(mn, distXY(x, j));
	mn = min(mn, distXY(x, k));
	mn = min(mn, distXY(x, l));
	mn = min(mn, distXY(x, m));
	return mn;
}

int main() {
	int x,y,z, mnArr[5];

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i=0; i < n; ++i) { 
			cin >> x >> y >> z;
			pop[i].idx = x*5+y, pop[i].val = z;
		}

		int mnDis = INF;
		for (int i=0; i < 25; i++)
			for (int j=i+1; j < 25; j++)
				for (int k=j+1; k < 25; k++)
					for (int l=k+1; l < 25; l++)
						for (int m=l+1; m < 25; m++) {
							int total = 0;
							for (int ii=0; ii < n; ii++) 
								total += dist(pop[ii].idx, i,j,k,l,m) * pop[ii].val;
							if (total < mnDis) {
								mnDis = total;
								mnArr[0]=i, mnArr[1]=j, mnArr[2]=k, mnArr[3]=l, mnArr[4]=m;
							}
						}
		cout << mnArr[0] <<" "<< mnArr[1] <<" "<< mnArr[2] <<" "<< mnArr[3] <<" "<< mnArr[4] << endl;	
	}
}