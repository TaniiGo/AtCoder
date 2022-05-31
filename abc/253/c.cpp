#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll q;
	cin >> q;

	map<ll, ll> s;
	for (ll i = 0; i < q; i++) {
		ll o;
		cin >> o;
		if (o == 1) {
			ll x;
			cin >> x;
			s[x]++;
		}
		else if (o == 2) {
			ll x, num;
			cin >> x >> num;
			ll cnt = min(s[x], num);
			s[x] -= cnt;
			if (s[x] == 0) s.erase(x);
		}
		else if (o == 3) {
			ll min = s.begin()->first;
			ll max = s.rbegin()->first;
			cout << max - min << endl;
		}
	}
	return 0;
}