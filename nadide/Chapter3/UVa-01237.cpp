// Expert Enough
#include <iostream>
using namespace std;

struct car{
	int l,h;
	string m;
} d[10001];

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i; i < n; i++)
			cin >> d[i].m >> d[i].l >> d[i].h;

		int q; cin >> q;
		while (q--) {
			int p; cin >> p;

			int maker = -1;
			for (int i=0; i < n; i++) 
				if (d[i].l <= p && p <= d[i].h)
					if (maker == -1) 
						maker = i;
					else {
						maker = -1;
						break;
					}

			if (maker == -1)
				cout << "UNDETERMINED" << endl;
			else
				cout << d[maker].m << endl;
		}
	}
}