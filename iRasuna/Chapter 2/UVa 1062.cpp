#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int _case = 1;
	
	while (cin >> s, s != "end") {
		int len = s.length();
		int arr[1005], dp[1005];
		int stack = 0;
		
		for (int i = 0; i < len; ++i) {
			arr[i] = s[i] - 'A';
		}
		
		for (int i = 0; i < len; ++i) {
			dp[i] = 1;
			
			for (int j = 0; j < i; ++j) {
				if (arr[j] < arr[i]) {
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
		}
		
		for (int i = 0; i < len; ++i) {
			stack = max(stack, dp[i]);
		}
		
		cout << "Case " << _case << ": " << stack << endl;
		_case++;
	}
	
	return 0;
}
