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
	vector<int> h(3);
	vector<int> w(3);
	rep(i,3) cin >> h[i];
	rep(i,3) cin >> w[i];
	ll ans = 0;
	rep1(i,28)rep1(j,28)rep1(k,28)rep1(l,28) {
		int a, b, c, d, e;
		a = h[0] - i - j;
		b = h[1] - k - l;
		c = w[0] - i - k;
		d = w[1] - j - l;
		e = h[2] - c - d;
		if (a <= 0 || b <= 0 || c <= 0 || d <= 0 || e <= 0) continue;
		if (h[0] != i + j + a) continue;
		if (h[1] != k + l + b) continue;
		if (h[2] != c + d + e) continue;
		if (w[0] != i + k + c) continue;
		if (w[1] != j + l + d) continue;
		if (w[2] != a + b + e) continue;
		ans++;
	}
	cout << ans << '\n';
	return 0;
}
