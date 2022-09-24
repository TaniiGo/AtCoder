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
	vector<int> cnt(n+1);
	for (int x = 1; x <= 100; x++) {
		for (int y = 1; y <= 100; y++) {
			for (int z = 1; z <= 100; z++) {
				int output = (x+y+z) * (x+y+z) - ((x*y)+(y*z)+(z*x));
				cnt[output]++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << cnt[i] << endl;
	return 0;
}
