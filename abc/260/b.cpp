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
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	vector<bool> passed(n);
	rep(i,n) passed[i] = false;
	vector<pair<int,int>> math(n);
	vector<pair<int,int>> eng(n);
	vector<pair<int,int>> sum(n);
	rep(i,n) {
		int x;
		cin >> x;
		math[i] = make_pair(-x, i);
		sum[i] = make_pair(-x, i);
	}
	rep(i,n) {
		int x;
		cin >> x;
		eng[i] = make_pair(-x, i);
		sum[i].first += -x;
	}
	sort(all(math));
	sort(all(eng));
	sort(all(sum));
	int i = 0;
	while (x) {
		passed[math[i].second] = true;
		x--;
		i++;
	}
	i = 0;
	while (y) {
		if (!passed[eng[i].second]) {
			passed[eng[i].second] = true;
			y--;
		}
		i++;
	}
	i = 0;
	while (z) {
		if (!passed[sum[i].second]) {
			passed[sum[i].second] = true;
			z--;
		}
		i++;		
	}
	rep(i,n) if (passed[i]) cout << i+1 << endl;
	return 0;
}
