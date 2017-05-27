#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	
	while (cin >> n) {
		bool isJolly = true;
		bool check[n] = { 0 };
		int arr[n];
		
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			if (i > 0) {
				check[abs(arr[i]-arr[i-1])] = true;
			}
		}
		
		for (int i = 1; i < n; ++i) {
			if (!check[i]){
				isJolly = false;
				break;
			}
		}
		
		cout << ((isJolly) ? "Jolly\n" : "Not jolly\n");
	}
	
	return 0;
}
