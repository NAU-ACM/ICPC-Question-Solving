#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n, arr[10021];
vector<int> vc;
map <int, int> used;
bool prime[10021];

int main() {
	int sz = 0;
	for (int i = 2; i * i <= 10000; ++i)
		if (!prime[i]){
			for (int j = i * i; j <= 10000; j += i) {
				prime[j] = true; 
			}
		}
	for (int i = 2; i <= 10000; ++i)
		if(!prime[i])
			vc.push_back(i);
	for (int i = 0; i < vc.size(); ++i) {
		int total = vc[i];
		used[total]++;
		for (int j = i + 1; j < vc.size(); ++j) {
			total += vc[j];
			used[total]++;
		}
	}
			
	while (cin >> n && n != 0)
		cout << used[n] << endl;
}