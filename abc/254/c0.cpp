#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	rep(i,n) cin >> a[i];

	rep(r,k) {
		vector<int> b;

		for (int i = r; i < n; i += k) {
			b.push_back(a[i]);
		}
		sort(b.begin(), b.end());
		
		for (int i = r; i < n; i += k) {
			a[i] = b[i / k];
		}
	}
	vector<int> tmp = a;
	sort(tmp.begin(), tmp.end());
	if (a == tmp) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
