#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	int h, w, r, c;
	cin >> h >> w >> r >> c;

	int ans = 0;

	if (r != 1) ans++;
	if (r != h) ans++;
	if (c != 1) ans++;
	if (c != w) ans++;
	cout << ans << endl;
	return 0;
}