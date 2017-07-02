/*
*	Really easy math q. Divide streets by the letters we allowed to use...
*/
#include <iostream>
#include <cmath>
using namespace std;

int main (){	
	int n, r, ct = 1;
	while(cin >> r >> n && r){
		r -= n; // getting rid of the "only digit" part
		if(r <= n*26) printf("Case %d: %d\n", ct++, (int)ceil((double)r/n));
		else printf("Case %d: impossible\n", ct++);
	}
}