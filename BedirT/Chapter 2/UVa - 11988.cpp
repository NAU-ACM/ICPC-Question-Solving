#include<iostream>
#include<list>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int main () {
	string s;
	list<char> str;
	while(cin >> s){
		str.clear();
		list<char>::iterator it = str.begin();
		for(int i = 0; i < s.size() ; ++i){
			// cout << str << endl;
			if(s[i] == '['){
				it = str.begin(); 
			} else if(s[i] == ']'){
				it = str.end();
			} else{
				str.insert(it ,s[i]);
			}
		}
		for(it = str.begin() ; it != str.end(); ++it) cout << *it;
		cout << endl;
	}

}
