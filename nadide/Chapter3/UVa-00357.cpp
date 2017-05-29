#include <cstdio>
#include <cstring>
using namespace std;

int main () {
	int n,c[5]={1,5,10,25,50};
	while (scanf("%d", &n) == 1) {
		long long int dp[n+100];
		memset (dp, 0, sizeof dp);

		dp[0] = 1;
		for (int i=0; i<5; i++)
			for (int j=c[i]; j<=n; j++)
				if (dp[j-c[i]])
					dp[j] += dp[j-c[i]];
				if (dp[n] == 1)
					printf("There is only 1 way to produce %d cents change.\n", n);
				else
					printf ("There are %lld ways to produce %d cents change.\n", dp[n], n);
	}

}