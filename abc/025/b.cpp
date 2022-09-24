#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	int ans = 0;
	rep(i,n) {
		string s;
		cin >> s;
		int m;
		cin >> m;
		if (m < a) m = a;
		if (m > b) m = b;
		if (s == "West") {
			ans -= m;
		}
		else if (s == "East") {
			ans += m;
		}
	}
	if (ans == 0) cout << 0 << endl;
	if (ans < 0) cout << "West " << abs(ans) << endl;
	if (ans > 0) cout << "East " << ans << endl;

	return 0;
}
