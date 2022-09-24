#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	int r, c;
	cin >> r >> c;

	vector<vector<int>> a(2, vector<int>(2));
	rep(i,2)rep(j,2) cin >> a[i][j];
	int ans;
	ans = a[r-1][c-1];
	cout << ans << endl;
	return 0;
}
