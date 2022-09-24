#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	int n, w;
	cin >> n >> w;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	vector<bool> can(w + 1);
	rep(i,n) if (a[i] <= w) can[a[i]] = true;

	rep(i,n)rep(j,i) {
		int sum = a[i] + a[j];
		if (sum <= w) can[sum] = true;
	}

	rep(i,n)rep(j,i)rep(k,j) {
		int sum = a[i] + a[j] + a[k];
		if (sum <= w) can[sum] = true;
	}
	int ans = 0;
	rep(i,w+1) if (can[i] == true) ans += 1;
	cout << ans << endl;
	return 0;
}