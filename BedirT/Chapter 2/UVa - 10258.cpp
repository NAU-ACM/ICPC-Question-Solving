#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <sstream>
#include <algorithm>
#include <fstream>
// #define fin cin
// #define fout cout

using namespace std;

int main () {

//	ifstream fin;
//	ofstream fout;
//	fin.open("input.txt");
//	fout.open("output.txt");
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
		int ar[101][10][2]; // 100 Teams, 9 Questions, 1 Spot for penalty 1 for if solved
		int iftried[101];
		memset(ar, 0, sizeof(ar)); // 0 initialized
		memset(iftried, 0, sizeof(iftried));
		while(getline(cin , s)){
			if(s == "") break;
			
			istringstream ss(s);
			ss >> team >> prob >> time >> stat;
			//cout << stat << endl;
			iftried[team] = 1;
//			cout << team << endl;
			if(ar[team][prob][1] == 0){
				if(stat == 'I'){ // If incorrect
					ar[team][prob][0] += 20;
				} else if(stat == 'C'){ // If correct
					ar[team][prob][1] = 1;
					ar[team][prob][0] += time;
				} else; // Otherwise
			} // close if 
		} // close while -cin-
/*		for(int i = 1; i < 101; ++i){
			cout << iftried[i] << " ";
		}cout << endl;
*/		vector<pair<int,int> > vc;
		vector<int> nonSolved;
		for(int i = 9; i > 0; --i){
			vc.clear();

			for(int j = 1; j <= 100; ++j){
				bool flag  = false;
				int num = 0, penalty = 0;
				for(int k = 1; k <= 9; ++k) {
					if(ar[j][k][1] == 1){
					       	num++;
						penalty += ar[j][k][0];
						flag = true;
					}
				}
				if(!flag && iftried[j]){
					nonSolved.push_back(j);	
					iftried[j] = 0;
				}
				else if(num == i) vc.push_back(make_pair(penalty,j));
			}
			sort(vc.begin(), vc.end());
//			cout << "IM HERE\n";
			for(vector<pair<int,int> >::iterator it = vc.begin(); it != vc.end(); ++it){
				cout << (*it).second << " " << i << " " << (*it).first << endl;
			}
		} 
		for(int i = 0; i < nonSolved.size(); ++i) cout << nonSolved[i] << " 0 0" << endl;
		nonSolved.clear();
		if(t) cout << endl;

	} // close while -t-
//	fin.close();
//	fout.close();
}
