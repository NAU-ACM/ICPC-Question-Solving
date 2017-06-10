#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#define maxN 1001
#define max(x, y) x > y ? x : y
using namespace std;

int find(int x, int * parent) {
	if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

bool detectCycle(int ar[][2], int * parent, int i){ 
	int x = find(ar[i][0], parent);
	int y = find(ar[i][1], parent);
	if(x == y) return true;
	parent[y] = x;
	return false;
}

int main (){

	// freopen("out.txt", "w", stdout);
	
	int ar[maxN][2], parent[maxN], S, P;
	int t; cin >> t;
	while(t--){

		cin >> S >> P;
		vector<pair<double, pair<int, int> > > vc;
		pair<int, int> nodes[P+1];
		vc.clear();

		for(int i = 0; i < P; ++i){
			int a, b;
			cin >> a >> b;
			nodes[i] = make_pair(a, b);
		}

		for(int i = 0; i < P; ++i){
			for(int j = i+1; j < P; ++j){
				pair<int, int> a = nodes[i], b = nodes[j];
				double num2 = b.second - a.second;
				double num1 = b.first - a.first;
				double w = sqrt(num1*num1 + num2*num2);
				vc.push_back(make_pair(w ,make_pair(i, j)));
			}
		}

		for(int i = 0; i < P; ++i) parent[i] = i;

		sort(vc.begin(), vc.end());

		int edges = 0;
		double D = .0;

		for(int i = 0, pos = 0; i < vc.size() && edges != P-S; ++i){
			ar[pos][0] = vc[i].second.first;
			ar[pos++][1] = vc[i].second.second;
			if(!detectCycle(ar, parent, pos-1)){
				D = max(D, vc[i].first);
				edges++;
			}
			else pos--;
		}

		printf("%.2lf\n", D);

	}
	// fclose(stdout);
}
