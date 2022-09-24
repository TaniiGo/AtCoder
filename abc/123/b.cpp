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
	vector<int> num;
	int ans = 0;

	rep(i,5) {
		int n;
		cin >> n;
		if (n % 10 != 0) num.push_back(n);
		else ans += n;
	}
	int min = 100;
	rep(i,num.size()) {
		chmin(min, num[i] % 10);
	}
	rep(i,num.size()) {
		if (min == num[i] % 10) {
			ans += num[i];
			min = 100;
		}
		else {
			int div = num[i] / 10;
			ans += 10 * (div + 1);
		}
	}
	cout << ans << endl;
	return 0;
}
