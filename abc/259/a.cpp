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
	int n, m, x, t, d;
	cin >> n >> m >> x >> t >> d;

	vector<int> tall(n+1);
	int cnt = 1;
	for (int i = n; i >= 0; i--) {
		tall[i] = t;
		if (i < x) {
			tall[i] = t - d * cnt;
			cnt++;
		}
	}
	cout << tall[m] << endl;
	return 0;
}
