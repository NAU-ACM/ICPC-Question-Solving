/*
	Question: UVa - 1262
	Related Topic: DS / Set-Map
	Author: BedirT
	Date: May 14, 2017
*/
#include <iostream>
#include <set>
#include <cstring>
#include <sstream>
using namespace std;
int main () {
	int t, k;
	string s; ostringstream hold;
	set<int> vc[6];
	int mp[6][150];
	cin >> t;
	while(t--){
		for(int i = 0; i < 6; ++i) vc[i].clear(); 
		memset(mp, 0, sizeof(mp));
		cin >> k;
		for(int i = 0; i < 12; ++i){
			cin >> s;
			if(i < 6){
				for(int j = 0; j < 5; ++j)
					mp[j][s[j]] = 1;
			}else{
				for(int j = 0; j < 5; ++j)
					if(mp[j%5][s[j]] == 1)
						vc[j%5].insert(s[j]);
			}
		}
		set<int>::iterator it, jt, kt, lt, mt;
		for(it = vc[0].begin() ; it != vc[0].end() ;++it){
			for(jt = vc[1].begin() ; jt != vc[1].end() ;++jt){
				for(kt = vc[2].begin() ; kt != vc[2].end() ;++kt){
					for(lt = vc[3].begin() ; lt != vc[3].end() ;++lt){
						for(mt = vc[4].begin() ; mt != vc[4].end() ;++mt){
							hold.str(string());
							hold << (char)*it << (char)*jt << (char)*kt << (char)*lt << (char)*mt;
							if(!(--k)) break;
						}if(!k) break;
					}if(!k) break;
				}if(!k) break;
			}if(!k) break;
		}
		if(k)cout << "NO\n";
		else cout << hold.str() << endl;
	}		
}