/*
	Question: UVa - 11389
	Related Topic: Sorting
	Author: BedirT
	Date: May 25, 2017
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
// #define debugE true

using namespace std;
int main (){
	#ifdef debugE
		freopen("output.txt", "w", stdout);
	#endif
	int n, d, r;
	int morning[101], evening[101];
	cin >> n >> d >> r;
	while(n != 0 && d != 0 && r != 0){
		memset(morning, 0, sizeof(morning));
		memset(evening, 0, sizeof(evening));
		for(int i = 0; i < n; ++i) cin >> morning[i];
		for(int i = 0; i < n; ++i) cin >> evening[i];
		sort(morning, morning+n);
		reverse(morning, morning+n);
		sort(evening, evening+n);
		int tot = 0;
		for(int i = 0; i < n; ++i){
			if(morning[i] + evening[i] > d)
				tot += (morning[i] + evening[i] - d);
		}
		cout << tot*r << endl;
		cin >> n >> d >> r;
	}
	#ifdef debugE
		fclose(stdout);
	#endif
}