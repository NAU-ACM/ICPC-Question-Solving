#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	
	while (cin >> s) {
		string result = "";
		int len = s.length();
		int pos = 0;
		
		for (int i = 0; i < len; ++i) {
			if (s[i] == '[') {
				pos = 0;
			}
			else if (s[i] == ']') {
				pos = result.length();
			}
			else {
				result.insert(pos, 1, s[i]);
				pos++;
			}
		}
		
		cout << result << endl;
	}
	
	return 0;
}
