#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main (){
	int b, t;
	double f;
	vector<pair<double, double> > vc;
	cin >> b >> t >> f; 
	while(b--){
		double p;
		double s;
		cin >> p >> s;
		vc.push_back(make_pair(s,p));
	}
	sort(vc.begin(), vc.end());
	double solution = 0;
	int j = 0;
	for(int i = 0; ; ++i){
		if(i >= vc.size()){
			i = 0;
			j++;
		}
		double res = 0;
		res = vc[i].second * vc[i].first * (pow(f, j));
		solution += res;
		vc[i].first -= res;
		t--;
		if(t <= 0){
			cout << solution << endl;
			exit(0);
		}
	}
}
