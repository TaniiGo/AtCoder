#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i <= (n); i++)
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
	int n, m;
	cin >> n >> m;

	vector<bool> isac(n+1);
	vector<int> numWA(n+1);
	rep(i,n+1) isac[i] = false;
	int wa = 0;
	int ac = 0;

	rep(i,m) {
		int p;
		string s;
		cin >> p >> s;

		if (isac[p] == true) continue;
		if (s[0] == 'A') isac[p] = true;
		else numWA[p]++;
	}
	rep1(i,n) {
		if (isac[i] == true) {
			ac++;
			wa += numWA[i];
		}
	}
	printf("%d %d\n", ac, wa);
	return 0;
}
