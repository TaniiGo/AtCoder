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

const int di[] = {-1,-1,0,0,1,1};
const int dj[] = {-1,0,-1,1,0,1};

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i,n) cin >> x[i] >> y[i];
	vector<int> g[n];
	rep(si,n){
		int i = x[si];
		int j = y[si];
		rep(k,6) {
			int ni = i + di[k];
			int nj = j + dj[k];
			rep(sj,n) {
				if (x[sj] == ni && y[sj] == nj) {
					printf("{%d,%d} -> {%d,%d}\n", i,j,ni,nj);
					// cout << si << ' ' << sj << '\n';
					g[si].push_back(sj);
				}
			}
		}
	}

	// rep(i,n) {
	// 	rep(j,g[i].size()) printf("%d %d\n", i, g[i][j]);
	// }

	vector<int> cnt(n, 0);
	queue<int> q;
	rep(i,n) {
		if (cnt[i] == 0) {
			q.push(i);
			cnt[i] = 1;
		}
		else cnt[i]++;

		while (!q.empty()) {
			int pos = q.front();
			q.pop();
			for (int j = 0; j < g[pos].size(); j++) {
				int nex = g[pos][j];
				if (cnt[nex] == 0) {
					q.push(nex);
					cnt[nex] = 1;
				}
				else {
					cnt[nex]++;
				}
			}
		}
	}
	int max = 1;
	rep(i,n) chmax(max, cnt[i]);
	cout << max << endl;
	return 0;
}
