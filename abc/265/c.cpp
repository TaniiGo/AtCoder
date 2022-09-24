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



int main() {
	int H, W;
	cin >> H >> W;

	string map[H+1];
	rep1(i,H) {
		string s;
		cin >> s;
		map[i] = "a" + s;
	}
	ll cnt = 0;
	int x = 1, y = 1;
	while (cnt < H * W) {
		if (map[y][x] == 'U' && y != 1) y--;
		else if (map[y][x] == 'D' && y != H) y++;
		else if (map[y][x] == 'L' && x != 1) x--;
		else if (map[y][x] == 'R' && x != W) x++;
		else break;
		cnt++;
	}
	if (cnt == H * W) cout << -1 << endl;
	else printf("%d %d\n", y, x);
	return 0;
}
