#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
// #include <fstream>
// #define fin cin
// #define fout cout
using namespace std;

int main (){
	// ifstream fin;
	// ofstream fout;
	// fin.open("input.txt");
	// fout.open("output.txt");

	int t, k;
	while(1){
		cin >> t;
		vector<int> vc;
		vc.clear();
		if(!t) break;
		for(int i = 0; i < t; ++i){
			cin >> k; vc.push_back(k);	
		}
		int tot = 0;
		while(vc.size() > 1){
			sort(vc.begin(), vc.end());
			tot += vc[0] + vc[1];
			vc.push_back(vc[0] + vc[1]);
			vc.erase(vc.begin(), vc.begin()+2);
		}
		cout << tot << endl;
	}
	// fin.close();
	// fout.close();

}
