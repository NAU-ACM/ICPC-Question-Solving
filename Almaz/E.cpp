#include <iostream>

using namespace std;

int n, Budget, H, W, Cost, total, ans, x;

int main() {
	cin >> n >> Budget >> H >> W;
	ans = 10000000;
	for (int i = 1; i <= H; ++i) {
		cin >> Cost;
		total = Cost * n;
		for (int j = 1; j <= W; ++j) {
			cin >> x;
			if (x > n)
				ans = min(ans, total);
		}
	}
	if (ans > Budget)
		cout << "stay home";
	else cout << ans;
}