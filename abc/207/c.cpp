#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

int main() {
	int n;
	cin >> n;
	vector<vector<double>> m(n);
	rep(i,n) {
		int t;
		double l, r;
		cin >> t >> l >> r;
		if (t == 2) r -= 0.1;
		else if (t == 3) l += 0.1;
		else if (t == 4) {
			l += 0.1;
			r -= 0.1;
		}
		m[i].push_back(l);
		m[i].push_back(r);
	}
	int ans = 0;
	rep(i,n) {
		for (int j = i + 1; j < n; j++) {
			if (m[i][0] <= m[j][1] && m[j][0] <= m[i][1])
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
