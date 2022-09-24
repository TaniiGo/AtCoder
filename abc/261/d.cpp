#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i <= (n); i++)
#define all(a) begin(a), end(a)
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

ll modpow(ll a, ll b, ll m) {
	ll p = a;
	ll ans = 1;
	rep(i,32) {
		if ((b & (0x01 << i)) != 0) {
			ans *= p;
			ans %= m;
		}
		p *= p;
		p %= m;
	}
	return (ans);
}

ll pow(ll a, ll b) {
	ll p = a;
	ll ans = 1;
	rep(i,32) {
		if ((b & (0x01 << i)) != 0) {
			ans *= p;
		}
		p *= p;
	}
	return (ans);
}

ll Division(ll a, ll b, ll m) {
	return ((a * modpow(b, m - 2, m)) % m);
}

struct V {
	int x, y;
	V(int x=0, int y=0): x(x), y(y) {}
	V operator-(const V &a) const {
		return V(x-a.x, y-a.y);
	}
	int cross(const V &a) const {
		return x*a.y - y*a.x;
	}
	int ccw(const V &a) const {
		int area = cross(a);
		if (area > 0) return +1; // ccw
		if (area < 0) return -1; // cw
		return 0; // collinear
	}
};


int main() {
	int N, M;
	cin >> N >> M;
	vector<int> x(N+1);
	rep1(i,N) cin >> x[i];
	vector<ll> b(N+9);

	// map<int, int> b;
	rep(i,M) {
		int c, y;
		cin >> c >> y;
		b[c] += y;
	}
	
	const ll INF = 1e18;
	vector dp(N+1, vector<ll> (N+1, -INF));
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			// 裏
			dp[i][0] = max(dp[i][0], dp[i-1][j]);
			// 表
			if (j) dp[i][j] = dp[i-1][j-1] + x[i] + b[j];
		}
	}
	ll max = 0;
	for (int i = 0; i <= N; i++) chmax(max, dp[N][i]);
	cout << max << endl;
	return 0;
}
