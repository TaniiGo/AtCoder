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
	string s;
	cin >> s;
	map<int, int> m;
	int max = 0;
	rep(i,n) {
		int w;
		cin >> w;
		if (s[i] == '1') {
			m[w]--;
			max++;
		}
		else {
			m[w]++;
		}
	}
	int ans = max;
	for (auto p : m) {
		max += p.second;
		chmax(ans, max);	
	}
	cout << ans << endl;
	return 0;
}
