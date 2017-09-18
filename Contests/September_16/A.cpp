#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int N, L, W, k, size, opt;
double total;
multiset<int> v;
multiset<int>::iterator it, it2;

int main() {
	cin >> N;
	cin >> L >> W;
	for (int i = 1; i <= N; ++i) {
		cin >> k;
 		v.insert(k);
	}
	total = 0;
	size = L / ((N - 4) / 2 + 1);
	//cout << size << endl;
	for(int i = 0; i < 2; ++i){
		it = v.lower_bound(0);
		if (i == 0) total += *it; else total += sqrt((*it) * (*it) + W * W);
		v.erase(it);
	}
	for(int i = 0; i < 2; ++i){
		it = v.upper_bound(L);
		it--;
		//cout << *it << ' ' << sqrt((L - *it) * (L - *it) + W * W) << endl;
		if (i == 0) total += L - *it; else total += sqrt((L - *it) * (L - *it) + W * W);
		v.erase(it);
	}
	// cout << total << endl;
	N -= 4;
	int tmp = size;
	for (int i = 1; i <= N/2; ++i) {
			
			/// Left Side
			it = v.lower_bound(size);
			it2 = v.upper_bound(size);
			it2--;
			//cout << *it  << " " << *it2 << endl;
			if(abs(size - *it2) > abs(size - *it)){
				opt = abs(size - *it);
				v.erase(it);
			} else{
				opt = abs(size - *it2);
				v.erase(it2);
			}
			total += opt; 
			////

			/// Right Side
			it = v.lower_bound(size);
			it2 = v.upper_bound(size);
			it2--;
			//cout << *it  << " " << *it2 << endl;
			if(abs(size - *it2) > abs(size - *it)){
				opt = abs(size - *it);
				v.erase(it);
			} else{
				opt = abs(size - *it2);
				v.erase(it2);
			}
			total += sqrt(opt * opt + W * W);
			////

			size += tmp;
	}
	printf("%.8lf", total);

}