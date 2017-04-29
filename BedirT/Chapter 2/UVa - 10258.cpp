#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <sstream>
#include <algorithm>
#include <fstream>
#define fin cin
#define fout cout

using namespace std;

int main () {

	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int t;
	string s;	
	cin >> t;
	// cout << t << endl;
	getline(cin , s);
	// cout << s << endl;
	getline(cin , s);
	// cout << s << endl;	
	while(t--){
		// cout << "IN\n";
		int team, prob, time;
		char stat;
		int ar[101][10][3]; // 100 Teams, 9 Questions, 1 Spot for penalty 1 for if solved
		memset(ar, 0, sizeof(ar)); // 0 initialized
		while(getline(cin , s)){
			if(s == "") break;
			
			istringstream ss(s);
			ss >> team >>  prob >> time >> stat;
			//cout << stat << endl;
			if(ar[team][prob][1] == 0){
				if(stat == 'I'){ // If incorrect
					ar[team][prob][0] += 20;
					ar[team][prob][2] = 1;
				} else if(stat == 'C'){ // If correct
					ar[team][prob][1] = 1;
					ar[team][prob][0] += time;
					ar[team][prob][2] = 1;
				} else{
					ar[team][prob][2] = 1;
				} // Otherwise
			} // close if 
		} // close while -cin-
		vector<pair<int,int> > vc;
		for(int i = 9; i >= 0; --i){
			vc.clear();
			for(int j = 1; j <= 100; ++j){
				bool flag  = false;
				int num = 0, penalty = 0;
				for(int k = 1; k <= 9; ++k) {
					if(ar[j][k][1] == 1){
					       	num++;
						penalty += ar[j][k][0];
					}
					if(ar[j][k][2] == 1){
						flag = true;
					}
				}
				if(i == 0 && num == 0 && flag) vc.push_back(make_pair(0,j));
				else if(num == i) vc.push_back(make_pair(penalty,j));
			}
			sort(vc.begin(), vc.end());
//			cout << "IM HERE\n";
			for(vector<pair<int,int> >::iterator it = vc.begin(); it != vc.end(); ++it){
				cout << (*it).second << " " << i << " " << (*it).first << endl;
			}
		} if(t) cout << endl;

	} // close while -t-
	fin.close();
	fout.close();
}
