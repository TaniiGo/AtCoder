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

void dfs(int cur, vector<string> &S, set<string> &T, int remain, string ans) {
	if (remain < 0) return ;

	if (cur == S.size()) {
		if (ans.size() >= 3 && !T.count(ans)) {
			cout << ans << endl;
			exit(0);
		}
		return ;
	}

	if (ans.size() > 0 && ans.back() != '_') {
		dfs(cur, S, T, remain, ans+"_");
	}
	else {
		dfs(cur+1, S, T, remain, ans + S[cur]);
		if (ans.size() > 0) dfs(cur, S, T, remain-1, ans+"_");
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> S(N);
	rep(i,N) cin >> S[i];
	sort(all(S));
	set<string> T;
	rep(i,M) {
		string t;
		cin >> t;
		T.insert(t);
	}
	int remain = 16; // 追加できるアンダーバー
	rep(i,N) remain -= S[i].size();
	remain -= N-1;

	do {
		dfs(0, S, T, remain, "");
	} while(next_permutation(all(S)));
	cout << -1 << endl;
	return 0;
}
