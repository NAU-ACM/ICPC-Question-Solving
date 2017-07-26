// Lotto
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int K, a[15]; 

	cin >> K;
	while (K) {
		for (int i=0; i<K; ++i)
			cin >> a[i];

		for (int i=0; i<K; ++i)
			for (int j=i+1; j<K; ++j)
			 	for (int k=j+1; k<K; ++k)
			 		for (int l=k+1; l<K; ++l)
			 			for (int m=l+1; m<K; ++m)
			 				for (int n=m+1; n<K; ++n)
			 					printf("%d %d %d %d %d %d\n",a[i], a[j], a[k], a[l], a[m], a[n]);
		cin >> K;
		if (K) cout << endl;
	}
}