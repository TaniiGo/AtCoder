#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	ll x, a, d, n;
	cin >> x >> a >> d >> n;

	if (d == 0) {
		cout << abs(a - x) << endl;
		return 0;
	}
	if (d < 0)
	{
		a = a + d * (n - 1);
		d = -d;
	}
	ll last = a + d * (n - 1);
	if (x < a)
	{
		cout << abs(x - a) << endl;
		return 0;
	}
	if (x > last)
	{
		cout << abs(last - x) << endl;
		return 0;
	}
	ll dist = x - a;
	ll i = dist / d;
	ll ans = min(abs(x - (a + d * (i))), abs(x - (a + d * (i + 1))));
	cout << ans << endl;
	return 0;
}
