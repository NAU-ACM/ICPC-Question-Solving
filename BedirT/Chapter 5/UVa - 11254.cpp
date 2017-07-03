#include <iostream>
#include <cstring>
#define pow9 1000000000
using namespace std;

int main (){
	int n;
	long d[100001];
	d[0] = 0;
	for(int i = 1; d[i] <= pow9; ++i){
		d[i] = d[i-1] + i;
	}

	while(cin >> n && n != -1){
		
	
	}
}