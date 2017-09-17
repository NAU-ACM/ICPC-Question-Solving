#include <iostream>

using namespace std;

int n, t, q, a[102001];
struct qwe {
	int counter, pos, pos1;
}  tree[300001];
int sz, now, ans, count[102001], pos[1000001];

void update(int x)
{
	for (int i = x / 2; i >= 1; i /= 2)
		if (tree[i * 2].counter < tree[i * 2 + 1].counter) {
			tree[i].counter = tree[i * 2].counter;
			tree[i].pos = tree[i * 2].pos;
			tree[i].pos1 = tree[i * 2].pos1;
		} else {
			tree[i].counter = tree[i * 2 + 1].counter;
			tree[i].pos = tree[i * 2 + 1].pos;
			tree[i].pos1 = tree[i * 2 + 1].pos1;
		}
}

int main() {
	cin >> n >> t >> q;
	sz = 1; while (sz < n) sz *= 2;
	for (int i = 1; i <= q; ++i) {
		cin >> a[i];
		a[i]++;
		count[a[i]]++;
	}
	for (int i = 1; i <= sz + sz; ++i)
		tree[i].counter = 10101011;
	/*for (int i = sz - 1; i >= 1; --i) {
		if (tree[i * 2].counter < tree[i * 2 + 1].counter) {
			tree[i].counter = tree[i * 2].counter;
			tree[i].pos = tree[i * 2].pos;
		} else {
			tree[i].counter = tree[i * 2 + 1].counter;
			tree[i].pos = tree[i * 2 + 1].pos;
		}
	}*/
	int k = 0;
	for (int i = 1; i <= q; ++i)
	{
		if (pos[a[i]] != 0) continue;
		if (k < n) {
			tree[++k + sz - 1].counter = --count[a[i]];
			tree[k + sz - 1].pos = a[i];
			tree[k + sz - 1].pos1 = k;
			if (tree[k + sz - 1].counter <= 0) tree[k + sz - 1].counter = 10101011;
			pos[a[i]] = k;
			ans++;
			update(k + sz - 1);
			continue;
		}
		now = tree[1].pos;
		int now1 = tree[1].pos1;
		//cout << now << ' ' << now1 << "asda\n";
		swap(pos[a[i]], pos[tree[1].pos]);
		tree[now1 + sz - 1].counter = --count[a[i]];
		tree[now1 + sz - 1].pos = a[i];
		if (tree[now1 + sz - 1].counter <= 0) tree[now1 + sz - 1].counter = 10101011;
		update(now1 + sz - 1);
		ans++;
	} 
	cout << ans;


}