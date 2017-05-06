#include <iostream>
using namespace std;
struct {
	int l, h;
	string name;
}cars[100001];

int main (){
	int t, n, a, b, q, ask; string s;	
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; ++i){
			cin >> cars[i].name >> cars[i].l >> cars[i].h;
		}
		cin >> q;
		while(q--){
			cin >> ask;
			int point = 0;
			for(int i = 0; i < n; ++i){
				if(cars[i].l <= ask && ask <= cars[i].h){
					point++; s = cars[i].name;
					if(point > 1) break;
				}
			}
			if(point == 1) cout << s << endl;
			else cout << "UNDETERMINED" << endl;
		}
		if(t) cout << endl;
	}
}
