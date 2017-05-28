/*
	Question: UVa - 12210
	Related Topic: -
	Author: BedirT
	Date: May 27, 2017
*/
#include <iostream>
using namespace std;
int main (){
	int k, a , b, ct= 1;
	while(cin >> a >> b && a+b != 0){
		printf("Case %d: ", ct++);
		int mn = 99999;
		for(int i = 0; i < a; ++i){
			cin >> k;
			mn = min(k, mn);
		}
		for(int j = 0; j < b; ++j){
			cin >> k;
		}
		if(b - a >= 0) cout << "0" << endl;
		else{
			cout << a-b << " " << mn << endl;	
		}
	}
}
