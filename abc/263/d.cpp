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
	int N;
	ll L, R;
	cin >> N >> L >> R;
	vector<ll> a(N+1);
	rep1(i,N) cin >> a[i];
	// 頭からの累積和
	vector<ll> b(N+1);
	rep1(i,N) {
		b[i] = a[i] + b[i-1];
		// printf("%d, %lld\n", i, b[i]);
	}
	ll sum = b[N];
	ll min = b[N];
	int x = 1;
	int X = 0;
	while (x <= N) {
		sum -= a[x] - L;
		// printf("min: %lld, sum: %lld\n", min, sum);
		if (chmin(min,sum)) X = x;
		x++;
	}
	for (int i = 1; i <= X; i++) {
		a[i] = L;
	}
	// ケツからの累積和
	a.push_back(0);
	reverse(all(a));
	vector<ll> c(N+1);
	rep1(i,N) {
		c[i] = a[i] + c[i-1];
		// printf("%d, %lld\n", i, c[i]);
	}
	sum = c[N];
	min = c[N];
	int y = 1;
	while (y <= N) {
		sum -= a[y] - R;
		chmin(min,sum);
		y++;
	}
	cout << min << endl;
	return 0;
}
