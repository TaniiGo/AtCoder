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
	const ll MOD = 998244353;
	int N;
	cin >> N;
	vector<int> a(N+1);
	rep1(i,N) cin >> a[i];

	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		vector dp(N+1, vector(i+1, vector<ll> (i)));
		dp[0][0][0] = 1;
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k <= i; k++) {
				for (int l = 0; l < i; l++) {
					// a[j]を選ばない
					dp[j][k][l] += dp[j-1][k][l] % MOD;
					printf("dp %d %d %d = %d\n", j, k, l, dp[j][k][l]);
					// a[j]を選ぶ
					if (k < i) {
						// 前の余のところからa[j]足した余のところ、さらに一個選んだから[k+1]のところに足す
						dp[j][k+1][(l+a[j])%i] += dp[j-1][k][l] % MOD;
						printf("dp %d %d %d = %d\n", j, k+1, (l+a[j])%i, dp[j][k+1][(l+a[j])%i]);
					}
				}
			}
		}
		cout << dp[N][i][0] << endl;
		ans += dp[N][i][0] % MOD;
	}
	cout << ans % MOD << endl;
	return 0;
}
