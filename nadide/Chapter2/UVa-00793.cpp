#include <iostream>
#include <sstream>
#include <string>
using namespace std; 

int root(int* ar, int x) {
	while (ar[x] != x)
		x = ar[x];
	return x;
}

void unionn (int* ar, int a, int b) {
	int rA = root(ar, a);
	int rB = root(ar, b);
	ar[rA] = rB;
}

bool find (int* ar, int a, int b) {
	if (root(ar,a) == root(ar,b))
		return true;
	else
		return false;
}

int main ()
{
	int t; cin >> t;

	string s;
	getline(cin, s);
	while (t--) {
		int n; cin >> n;
		getline(cin, s);
		
		int ar[10005]; 
		for (int i=0; i<n; i++) ar[i]=i;
		int succes=0, fail=0;

		getline(cin, s);
		do {
			char c; int x,y;
			stringstream ss(s);
			ss >> c >> x >> y;

			if (c == 'c') 
				unionn (ar,x,y);
			else 
				find(ar,x,y) ? ++succes : ++fail ;

			getline(cin, s);
		} while(!s.empty());
		cout << succes <<","<< fail << endl;
		if(t) cout << endl;
	}

}