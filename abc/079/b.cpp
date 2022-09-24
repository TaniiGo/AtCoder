#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	int n;
	cin >> n;

	ll a[100];
	a[0] = 2;
	a[1] = 1;
	for (int i = 2; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	cout << a[n] << endl;
	return 0;
}
