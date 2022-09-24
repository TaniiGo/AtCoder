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
	int h1, w1;
	cin >> h1 >> w1;
	vector m1(h1, vector<ll> (w1));
	rep(i,h1)rep(j,w1) cin >> m1[i][j];
	int h2, w2;
	cin >> h2 >> w2;
	vector m2(h2, vector<ll> (w2));
	rep(i,h2)rep(j,w2) cin >> m2[i][j];

	// bit全探索2回
	//行
	for (ll i = 0; i < (1LL << h1); i++) {
		for (ll j = 0; j < (1LL << w1); j++) {
			int tmp[10][10];
			int r = 0;
			bool lenok = false;
			for (int k = 0; k < h1; k++) {
				if ((i & (1LL << k)) != 0LL) {
					int c = 0;
					for (int l = 0; l < w1; l++) {
						if ((j & (1LL << l)) != 0LL) {
							tmp[r][c] = m1[k][l];
							c++;
						}
					}
					if (c == w2) lenok = true;
					r++;
				}
			}
			if (r == h2 && lenok) {
				bool ok = true;
				rep(y,h2)rep(x,w2) {
					if (tmp[y][x] != m2[y][x]) ok = false;
				}
				if (ok) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
