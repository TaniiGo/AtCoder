#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	vector<bool> a(10);
	string s;
	cin >> s;

	rep(i,9) {
		a[s[i] - '0'] = true;
	}
	rep(i,10) {
		if (a[i] == false) cout << i << endl;
	}
	return 0;
}
