#include <iostream>

using namespace std;

int n, m, ans, x, y;
bool used[100][100];
char a[100][100];

void dfs (int x, int y) {
	//cerr << x << ' ' << y << endl;
	if (a[x][y] == 'G') ans++, a[x][y] = '.';
	if (used[x][y] == true || a[x][y] == '#' || 
		a[x][y + 1] == 'T' || a[x][y - 1] == 'T' || 
		a[x + 1][y] == 'T' || a[x - 1][y] == 'T')
		return;
	used[x][y] = true;
	dfs(x, y + 1);
	dfs(x, y - 1);
	dfs(x + 1, y);
	dfs(x - 1, y);
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'P') { x = i, y = j; }
		}
	dfs(x, y);
	cout << ans;

}