#include <iostream>
#include <cmath>
#include <cstring>
// #include <fstream>
// #define fin cin
// #define fout cout
using namespace std;
int tree[1000001];

int RMQ(int L, int R){
    int ans = 1;
    while(L <= R){
        if(L % 2 == 1) ans *= tree[L];
        if(R % 2 == 0) ans *= tree[R];
        L = (L+1)/2;
        R = (R-1)/2;
    }   
    return ans;
}

void update(int x){
    for (int i = x; i >= 1; i /= 2)
        tree[i] *= -1;
}

int sign(int i){
	if(i < 0) return -1;
	else if(i > 0) return 1;
	else return 0;
}

int main () {
    
	// ifstream fin;
	// ofstream fout;
	// fin.open("input.txt");
	// fout.open("output.txt");

    int n, sz = 1, res, k, a, b, jj;
    char op;
    
    while(cin >> n >> k){
	    while (n > sz) sz *= 2;
	    for(int i = 0; i < 2*sz ; ++i) tree[i] = 1;
	    for(int i = sz; i <= sz+n-1; ++i){
	    	cin >> jj;
	    	tree[i] = sign(jj);
	    }
	    for(int i = sz-1; i >= 1; --i)
	    	tree[i] = sign(tree[2*i]) * sign(tree[2*i+1]);
	   		
   		// for (int i = 1; i <= sz+n-1; ++i) {
   	 //    	cout << tree[i] << " " ;
	   	// }cout << endl << endl;

	    while(k--){
	    	cin >> op >> a >> b;
	    	if(op == 'C'){
	    		if(sign(tree[sz+a-1])==sign(b));
	    		else{
	    			tree[sz+a-1] = sign(b);
    				for(int i = sz-1; i >= 1; --i)
	    				tree[i] = sign(tree[2*i]) * sign(tree[2*i+1]);
	    		}
	    	}
			else{
				int res = RMQ(a+sz-1 , b+sz-1);
				// cout << res << endl;
				if(res > 0) cout << "+";
				else if(res < 0) cout << "-";
				else cout << "0";
			} 
	    }
	    cout << endl;
    }
 //    fin.close();
	// fout.close();
}
