#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> have(k);
	rep(i,k) cin >> have[i];

	vector<vector<ll>> a(n, vector<ll>(2));
	rep(i,n)rep(j,2) cin >> a[i][j];

	vector<double> r(n);

	rep(i,n) {
		r[i] = 1e18;
		rep(j,k) {
			ll xdif;
			ll ydif;
			xdif = a[i][0] - a[have[j]-1][0];
			ydif = a[i][1] - a[have[j]-1][1];
			double dist = sqrt(xdif * xdif + ydif * ydif);
			r[i] = min(r[i], dist);
		}
	}
	double ans = 0.0;
	rep(i,n) ans = max(r[i], ans);
	printf("%.12lf\n", ans);
	return 0;
}
