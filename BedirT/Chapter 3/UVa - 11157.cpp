/*
	Question: UVa - 11157
	Related Topic: Greedy
	Author: BedirT
	Date: May 27, 2017
*/
#include <iostream>
#include <vector>
using namespace std;
int main (){
	vector<int> vc;
	int t, d, n, value, ct = 1;
	char type, trash;
	cin >> t;
	while(t--){
		cin >> n >> d;
		vc.push_back(0); vc.push_back(0);
		for(int i = 0; i < n; ++i){
			cin >> type >> trash >> value;
			vc.push_back(value);
			if(type == 'B')
				vc.push_back(value);
		}
		vc.push_back(d); vc.push_back(d);
		int mx = 0;
		for(int i = 2; i < vc.size(); ++i)
			mx = max(mx, vc[i] - vc[i-2]);
		vc.clear();
		printf("Case %d: %d\n",ct++, mx);
	}
}
