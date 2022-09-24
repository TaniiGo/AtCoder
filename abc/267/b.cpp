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
	string s;
	cin >> s;
	vector<bool> retu(7);
	rep(i,10) {
		if (s[0] == '1') retu[3] = true;
		if (s[1] == '1') retu[2] = true;
		if (s[2] == '1') retu[4] = true;
		if (s[3] == '1') retu[1] = true;
		if (s[4] == '1') retu[3] = true;
		if (s[5] == '1') retu[5] = true;
		if (s[6] == '1') retu[0] = true;
		if (s[7] == '1') retu[2] = true;
		if (s[8] == '1') retu[4] = true;
		if (s[9] == '1') retu[6] = true;
	}
	if (s[0] == '1') {
		cout << "No" << endl;
		return 0;
	}
	bool tati = false;
	int dist = 0;
	rep(i,7) {
		if (retu[i]) tati = true;
		if (retu[i] == false && tati) dist++;
		if (tati && dist && retu[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
