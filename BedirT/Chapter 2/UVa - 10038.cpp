#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int vc[3001];
int main () {
	int n, a, b;
	while(cin >> n){
		cin >> a;
		for(int i = 1; i < n ; ++i){
			cin >> b;
			vc[abs(b-a)] = 1;
			a = b;
		} 
		bool flag = true;
		for(int i = 1; i < n ; ++i){
			if(!vc[i]){
				flag = false;
				break;
			}
		}
		if(flag) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
		memset(vc, 0, sizeof(vc));
	}
}
