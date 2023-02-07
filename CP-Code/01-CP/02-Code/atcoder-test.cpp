#include <iostream>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
int main() {
	int n, m;
	cin >> n >> m;
	dsu d(n);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		if (d.same(u, v)) ans++;
		d.merge(u, v);
	}
	cout << ans << '\n';
}