#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main () {
	int n; cin >> n;
	while (n) {
		map<vector<int>,int> m;
		while (n--) {
			vector<int> v(5);
			cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
			sort(v.begin(), v.end());
			m[v]++;
		}

		int max = 0, nMax = 0;
		for (map<vector<int>,int>::iterator i = m.begin(); i != m.end(); ++i)
		{
			if (i->second > max) 
				max = i->second, nMax = 0;
			if (i->second == max)
				nMax += max;
		}
		cout << nMax << endl;
		cin >> n;
	}
} 