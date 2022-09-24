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

	map<string, int> names;
	vector<string> last(n);
	vector<string> first(n);
	rep(i,n) {
		string a,b;
		cin >> a >> b;
		if (a == b) names[a]++;
		else {
			names[a]++;
			names[b]++;
		}
		last[i] = a;
		first[i] = b;
	}
	bool isok = true;
	rep(i,n) {
		if (names[last[i]] > 1 && names[first[i]] > 1) isok = false;
	}
	if (isok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
