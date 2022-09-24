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
	string s;
	cin >> n >> s;

	vector<int> w(n);
	rep(i,n) cin >> w[i];

	map<int, vector<int>> mp;
	rep(i,n) mp[w[i]].push_back(i);

	int now = 0;
	rep(i,n) if (s[i] == '1') now++;
	int ans = now;

	for (auto p : mp) {
		for (auto i : p.second) {
			if (s[i] == '1') now--;
			else now++;
		}
		chmax(ans, now);
	}
	cout << ans << endl;
	return 0;
}
