// Interval Product
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
char *tree;
int h;

char sign(int x) {
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}

void build(int n) {
	for(h=1; h<n; h*=2);
	tree = (char*)malloc(sizeof(char*)*(2*h));
	memset (tree, 1, sizeof(tree));
	
	for (int i=h; i <= h+n-1; i++) { //leaves
		int x; cin >> x;
		tree[i] = sign(x);
	}
	for (int i=h-1; i > 0; i--)  //others
		tree[i] = sign(tree[2*i]) * sign(tree[2*i+1]);
}

char product(int l, int r) {
	char ans = 1;
	while(l <= r){
        if(l % 2 == 1) ans *= tree[l];
        if(r % 2 == 0) ans *= tree[r];
        l = (l+1)/2;
        r = (r-1)/2;
    }   
    return ans;
}

void change(int x, int y) {
	if (sign(tree[h+x-1] == sign(y))) return;
	
	tree[h+x-1] = sign(y);
	for (int i=(h+x-1)/2; i > 0; i/=2)
		tree[i] = sign(tree[2*i]) * sign(tree[2*i+1]);
}

int main() {
	int n, k;
	char c; int x,y;

	while (cin >> n >> k) {
		build (n);

		while (k--) {
			cin >> c >> x >> y;
			if (c == 'C') { 
				change(x,y);
			}
			else {
				char ans = product(h+x-1, h+y-1); // range of leaves
				if(ans > 0) cout << "+";
				else if(ans < 0) cout << "-";
				else cout << "0";
			}
		}
		cout << endl;
	}

}