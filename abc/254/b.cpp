#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	int n;
	cin >> n;

	vector<vector<int>> a(n);

	rep (i, n) {
		a[i] = vector<int>(i + 1);
		a[i][0] = a[i][i] = 1;
		for (int j = 1; j < i; j++) {
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}

		rep (j, i + 1) cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}