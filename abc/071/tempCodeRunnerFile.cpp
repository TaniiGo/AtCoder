#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
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

int main() {
	int n;
	cin >> n;
	map<ll, int> mp;
	rep(i,n) {
		int a;
		cin >> a;
		mp[a]++;
	}
	ll a = 0;
	ll b = 0;
	int cnt = 0;
	for (auto i = mp.rbegin(), e = mp.rend(); i != e; i++) {
		if (cnt >= 2) break;
		if (i->second >= 4) {
			if (cnt == 1) b = i->first;
			if (cnt == 0) a = i->first; b = i->first;
		}
		if (i->second >= 2) {
			if (cnt == 0) a = i->first;
			else if (cnt == 1) b = i->first;
			cnt++;
		}
	}
	if (cnt < 2) cout << 0 << endl;
	else cout << a * b << endl;
	return 0;
}
