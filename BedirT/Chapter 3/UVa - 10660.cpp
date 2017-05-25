/*
	Question: UVa - 10660
	Related Topic: Math
	Author: BedirT
	Date: May 25, 2017
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int cityVal[25], minDist;

int distanceYY(int target, int a){
	int targetX = target % 5 , targetY = target / 5;
	int checkX = a % 5 , checkY = a / 5;
	return abs(targetX - checkX) + abs(targetY - checkY);
}

int distance(int target, int a, int b, int c, int d, int e){
	int mn = distanceYY(target, a);
	mn = min(mn , distanceYY(target, b));
	mn = min(mn , distanceYY(target, c));
	mn = min(mn , distanceYY(target, d));
	mn = min(mn , distanceYY(target, e));
	return mn;
}

void solve(){
	int o1 = 0, o2 = 1, o3 = 2, o4 = 3, o5 = 4;
	for(int i = 0; i < 21; ++i){
		for(int j = i+1; j < 22; ++j){
			for(int k = j+1; k < 23; ++k){
				for(int ii = k+1; ii < 24; ++ii){
					for(int jj = ii+1; jj < 25; ++jj){
						int totalDist = 0;
						for(int eachCity = 0; eachCity < 25; ++eachCity)
							totalDist += distance(eachCity, i, j, k, ii, jj) * cityVal[eachCity];
						if(totalDist < minDist){
							minDist = totalDist;
							o1 = i, o2 = j, o3 = k, o4 = ii, o5 = jj;
						}
					}	
				}		
			}		
		}		
	}
	cout << o1 << " " << o2 << " " << o3 << " " << o4 << " " << o5 << endl;
}

int main () {
	int t, pollNum, x, y;
	cin >> t;
	while(t--){
		cin >> pollNum;
		memset(cityVal, 0, sizeof(cityVal));
		for(int i = 0; i < pollNum; ++i)
			cin >> x >> y >> cityVal[5 * x + y];
		minDist = 0xfffffff;
		solve();
	}
}