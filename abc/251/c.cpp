#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;

	map<string, ll> a;

	ll max = -1;
	ll index;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		ll score;
		cin >> score;
		if (score > max) {
			auto itr = a.find(str);
			if (itr != a.end()) continue;
			max = score;
			index = i;
		}
		a[str] = score;
	}
	cout << index << endl;
	return 0;
}
