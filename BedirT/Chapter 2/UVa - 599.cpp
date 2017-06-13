#include <iostream>
#include <vector>
#include <set>
// #include <fstream>
// #define fin cin
// #define fout cout
using namespace std;

int res[30];
int size[30];
int root(int i) {
	while(res[i] != i){
		res[i] = res[res[i]];
		i = res[i];
	}
	return i;
}
void Union(int a, int b) {
	int r1 = root(a);
	int r2 = root(b);
	// cout << r1 << " | " << r2 << endl;
	if(r1 == r2) return;
	else if(size[r1] < size[r2]){
		res[r1] = res[r2];	
		size[r2] += size[r1];
	}else{
		res[r2] = res[r1];
		size[r1] += size[r2];
	}
}

int main () {

	// ifstream fin;
	// ofstream fout;
	// fin.open("input.txt");
	// fout.open("output.txt");

	int t;
	cin >> t;
	while(t--){
		string s;
		set<int> nodes;
		for(int i = 0; i < 30; ++i){
			res[i] = i;
			size[i] = 1;
		}
		while(1){
			cin >> s;
			if(s[0] == '*') break;
			Union(s[1]-65,s[3]-65);
		}
		cin >> s;
		for(int i = 0; i < s.size(); i+=2){
			// cout << s[i] << " | res= " << size[s[i]-65] << endl;
			nodes.insert(res[s[i]-65]);		
		}
		int acorn = 0, tree = 0;
		for(set<int>::iterator it = nodes.begin(); it != nodes.end() ; ++it){
			// cout << *it << " ";
			if(size[*it] == 1){
				acorn++;
			}
			else{
				tree++;
			}
		}
		cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s)." << endl;
	}
	// fin.close();
	// fout.close();
}
