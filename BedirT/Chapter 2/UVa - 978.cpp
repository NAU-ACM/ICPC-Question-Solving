#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main (){
	int t, k;
	cin >> t;
	while(t--){
		int a,b,g;
		cin >> a >> g >> b;
		vector<int> sG, sB;
		multiset<int> blue, green;
		multiset<int>::iterator bIt, gIt;
		for(int i = 0; i < g; ++i){
		       	cin >> k;
			green.insert(k);
		}
		for(int i = 0; i < b; ++i){
		       	cin >> k;	
			blue.insert(k);
		}
		while(blue.size() && green.size()){
//		cout << "CHECK\n";
			for(int i = 0; i < a && green.size() && blue.size() ; ++i){
				// FIGHT
				bIt = blue.end();
				gIt = green.end();
				bIt--; gIt--;
				if(*bIt > *gIt){
					sB.push_back(*bIt-*gIt);
					green.erase(gIt);
					blue.erase(bIt);
				}
				else if(*bIt < *gIt){
					sG.push_back(*gIt-*bIt);
					blue.erase(bIt);
					green.erase(gIt);
				}
				else{
					blue.erase(bIt);
					green.erase(gIt);
				}
			}
			for(int i = 0; i < sG.size(); ++i) green.insert(sG[i]);
			sG.clear();
			for(int i = 0; i < sB.size(); ++i) blue.insert(sB[i]);
			sB.clear();
		}
//		cout << "SAFE\n";
		if(!blue.size() && !green.size()) cout << "green and blue died" << endl;
		else if(!blue.size()){
			cout << "green wins" << endl;
			gIt = green.end() ;
			do{	
				gIt--;
				cout << *gIt << endl;
	                }while (gIt != green.begin());
		}else{
			cout << "blue wins" << endl;
			bIt = blue.end() ;
			do{	
				bIt--;
				cout << *bIt << endl;
	                }while (bIt != blue.begin());
	
		}
		blue.clear();
		green.clear();
		if(t) cout << endl;
	}	
}
