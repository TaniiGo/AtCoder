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
	int N;
	cin >> N;
	int max = -1;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		int num = i;
		while (num != 0) {
			int m = num % 2;
			if (m == 0) cnt++;
			num /= 2;
		}
		if (chmax(max, cnt)) ans = i;
	}
	cout << ans << endl;
	return 0;
}
