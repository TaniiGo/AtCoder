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
	cin >> N;
	vector<ll> x(N+2);
	vector<ll> y(N+2);
	vector<ll> r(N+2);
	cin >> x[0] >> y[0];
	cin >> x[N+1] >> y[N+1];
	r[0] = 0;
	r[N+1] = 0;
	rep1(i,N) cin >> x[i] >> y[i] >> r[i];
	vector g(N+2, vector<int> (N+2));
	for (int i = 0; i < N+1; i++) {
		for (int j = i+1; j < N+2; j++) {
			if (i == 0 && j == N+1) continue;
			ll dist = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
			// 二つの円が交わるか接する条件
			if ((r[i]-r[j])*(r[i]-r[j]) <= dist && dist <= (r[i]+r[j])*(r[i]+r[j])) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	vector<bool> ok(N+2);
	queue<int> q;
	q.push(0);
	ok[0] = true;

	while (!q.empty()) {
		int pos = q.front();
		q.pop();
		for (int i = 0; i < g[pos].size(); i++) {
			int nex = g[pos][i];
			if (!ok[nex]) {
				ok[nex] = true;
				q.push(nex);
			}
		}
	}
	if (ok[N+1]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
