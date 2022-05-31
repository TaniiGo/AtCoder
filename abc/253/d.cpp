#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	ll n, a, b;
	cin >> n >> a >> b;

	ll sum_n = (1 + n) * n / 2;
	ll sum_a = ((a + n/a * a) * (n/a)) / 2;
	ll sum_b = ((b + n/b * b) * (n/b)) / 2;
	ll ab_lcm = lcm(a, b);
	ll sum_ab = ((ab_lcm + n/ab_lcm * ab_lcm) * (n/ab_lcm)) / 2;
	ll ans = sum_n - sum_a - sum_b + sum_ab;
	cout << ans << endl;
	return 0;
}
