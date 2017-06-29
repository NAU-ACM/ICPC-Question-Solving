// Closest Sum
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define INF 0x7FFFFFFF
int a[10001];

int main() {
	int n,m,q,x=1;
	cin >> n;
	while (n) {
		cout << "Case "<< x++ <<":" << endl;
		for (int i=0; i < n; i++)
			cin >> a[i];
		//sort(a, a+n);
		cin >> m;
		while (m--) {
			cin >> q;

			int diff=INF, sum=0;
			for (int i=0; i < n && diff; i++)
				for (int j=i+1; j < n && diff; j++) 
					if (abs(q-(a[i]+a[j])) < diff) {
						sum = a[i]+a[j];
						diff = abs(q-(a[i]+a[j]));
						if (diff == 0) break;
					}
			cout << "Closest sum to "<<q<<" is "<<sum<<"." << endl;
		}
		memset(a, 0, n);
		cin >> n;
	}
}