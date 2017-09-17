#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

const int prime = 31;

int dp[1001][1001];
int mx = 0;
int hashof(string str) {
	int hash = 0;
	for (int i = 0; i < str.size(); ++i) {
		hash = (hash + (str[i]-31))*prime;
	}
	return hash;
}
int main (){
	int t;
	string s, name, str;
	vector<int> mp[1001];
	vector<string> names;
	vector<string> answer;	
	cin >> t;
	while(t--){
		cin >> name; cin.ignore(100,'\n');
		names.push_back(name);
		while(getline(cin , s)){
			if(s == "")continue;
			str = "";
			if (s == "***END***") break;
			int k = 0, r = s.size()-1;
			while (s[k++] == ' ');
			while (s[r--] == ' ');
			for (int i = k; i <= r; ++i){
				if(str[str.size()-1] == ' ' && s[i] == ' ') continue;
				str+=s[i];
			}
			mp[names.size()-1].push_back(hashof(str));
		}
	}
	std::vector<int> vc;

	while(getline(cin , s)){
		if(s == "")continue;
		str = "";
		if (s == "***END***") break;
		int k = 0, r = s.size()-1;
		while (s[k++] == ' ');
		while (s[r--] == ' ');
		for (int i = k; i <= r; ++i){
			if(str[str.size()-1] == ' ' && s[i] == ' ') continue;
			str+=s[i];
		}
		vc.push_back(hashof(str));
	}
	for (int i = 0; i < names.size(); ++i) {
		int _mx = 0; 
		for (int j = 0; j < mp[i].size(); ++j) {
			for (int k = 0; k < vc.size() ; ++k){
				int inc = 0;
				while (j+inc < mp[i].size() && k+inc < vc.size() && mp[i][j+inc] == vc[k+inc])
					inc++;
				_mx = max(inc, _mx);
			}
		}
			if (_mx > mx) {
				mx = _mx;
				answer.clear();
				answer.push_back(names[i]);
			}
			else
			if (_mx == mx) {
				answer.push_back(names[i]);
			}
		
				
	}
	cout << mx;
	if (mx > 0) {
		for (int i = 0; i < answer.size(); ++i)
			cout << " " << answer[i];
	}
	cout << endl;
}
