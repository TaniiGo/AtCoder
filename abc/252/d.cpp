#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

ll dp[200005][4];

int main() {
	int n;
	cin >> n;

	map<int, int> cnt;
	rep(i, n) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	vector<int> c;
	for (auto p : cnt) c.push_back(p.second);
	int m = c.size();

	dp[0][0] = 1;
	rep(i, m) {
		rep(j, 4) {
			dp[i+1][j] = dp[i][j];
			if(j) dp[i+1][j] += dp[i][j-1] * c[i];
		}
	}
	cout << dp[m][3] << endl;
	return 0;
}
