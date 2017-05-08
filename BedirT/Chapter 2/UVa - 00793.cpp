#include <iostream>
#include <cstdio>
using namespace std;

int res[10005];
int size[10005];

int root(int i){
	while(res[i] != i){
		res[i] = res[res[i]];
		i = res[i];
	}
	return i;
}
void Union(int a, int b){
	int r1 = root(a);
	int r2 = root(b);	
	if(r1 == r2) return;
	else if(size[r1] < size[r2]){
		res[r1] = res[r2];
		size[r2] += size[r1];
	}else{
		res[r2] = res[r1];
		size[r1] += size[r2];
	}
}
bool find(int a, int b){
	if(root(a) == root(b)) return true;
	else return false;
}

int main () {
	int t, n, a, b;
	char q;
	cin >> t;
	string s;
	while(t--){	
		scanf("\n%d\n",&n);
		int plus = 0, minus = 0;
		for(int i = 0; i <= n ; ++i){
			res[i] = i;
			size[i] = 1;
		}
            

		while(1){
			if(!getline(cin,s) || s.empty()) break;
			sscanf(s.c_str(),"%c %d %d",&q,&a,&b);
			if (q == 'c') Union(a, b);
			else if(find(a, b)) plus++;
			else minus++;	
		}
		
		cout << plus << "," << minus << endl;
		if(t) cout << endl;
	}
}
