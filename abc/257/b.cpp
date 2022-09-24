#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	int n, k, q;
	cin >> n >> k >> q;

	vector<int> masu(n+1);
	rep(i,k) {
		int a;
		cin >> a;
		masu[a]++;
	}
	rep(i,q) {
		int l;
		cin >> l;
		if (l == n) continue;
		int cnt = 0;
		int k;
		for (int j = 1; j < n; j++) {
			if (masu[j] == 1) cnt++;
			if (cnt == l) {
				k = j;
				break;
			}
		}
		if (masu[k+1] == 1) continue;
		if (masu[k+1] == 0) {
			masu[k+1] = 1;
			masu[k] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (masu[i] == 1) cout << i << ' ';
	}
	cout << endl;
	return 0;
}
