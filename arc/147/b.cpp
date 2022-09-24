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
	vector<pair<int, char>> v;
	vector<string> s;
	// indexの偶奇とPiの不一致度を取る
	int unmatch = 0;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		if (i % 2 == a % 2) {
			v.emplace_back(a, 'o');
		}
		else {
			unmatch++;
			v.emplace_back(a, 'x');
		}
	}
	// x を全部左に寄せる
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-2; j++) {
			if (v[j].second == 'o' && v[j+2].second == 'x') {
				swap(v[j], v[j+2]);
				s.emplace_back("B " + to_string(j+1));
				cnt++;
			}
		}
	}
	// 不一致をなくす
	for (int i = 0; i < unmatch; i+=2) {
		swap(v[i], v[i+1]);
		s.emplace_back("A " + to_string(i+1));
		cnt++;
	}
	// 昇順にする
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-2; j++) {
			if (v[j].first > v[j+2].first) {
				swap(v[j], v[j+2]);
				s.emplace_back("B " + to_string(j+1));
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	rep(i,cnt) cout << s[i] << endl;
	return 0;
}
