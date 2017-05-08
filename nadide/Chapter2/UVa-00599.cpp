#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(int v[26][26], int was[], int nodes[], int size, int x) {
	was[nodes[x]] = 1;
	for (int i=0; i < size; i++) {
		if (v[nodes[x]][nodes[i]] && !was[i])
			dfs(v, was, nodes, size, i);
	}
}

int main ()
{
	int t; cin >> t;
	while (t--) {
		int v[26][26]={0};
		string s; cin>>s;
		while (s[0] != '*') {
			v[s[1]-'A'][s[3]-'A'] = 1;
			v[s[3]-'A'][s[1]-'A'] = 1;
			cin >> s;
		}
		cin >> s;

		int size=s.length()/2+1, nodes[size];
		for (int i=0; i<s.length(); i+=2)
			nodes[i/2] = s[i]-'A';

		// Adjacency Matrix
		// cout << "  ";
		// for (int i=0; i<size; i++)
		// 	cout << char(nodes[i]+'A') << " ";
		// cout << endl;
		// for (int i=0; i < size; i++) {
		// 	cout << char(nodes[i]+'A') << " ";
		// 	for (int j=0; j < size; j++)
		// 		cout << v[nodes[i]][nodes[j]] << " ";
		// 	cout << endl;
		// }


		int was[26]={0}, tree=0, acorn=0;
		for (int i=0; i < size; i++)
			if (!was[nodes[i]]) {
				was[nodes[i]] = 1;
				bool dot = true;
				for (int j=0; j < size; j++)
					if (v[nodes[i]][nodes[j]] && !was[j]) {
						dfs(v, was, nodes, size, j);
						dot = false;
					}
				(dot) ? acorn++ : tree++;
			}
		cout << "There are "<<(tree)<<" tree(s) and "<<(acorn)<<" acorn(s)." << endl;
	}
	
}