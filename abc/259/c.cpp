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
	string s, t;
	cin >> s >> t;
	int s_len, t_len;
	bool isok = true;

	s_len = s.length();
	t_len = t.length();
	// sの長さがtより長く根本的に合わせられない時
	if (s_len > t_len) {
		cout << "No" << endl;
		return 0;
	}

	int i = 0;
	int j = 0;
	while (i < s_len && j < t_len) {
		int cnts = 0;
		int cntt = 0;
		char c = s[i];
		while (s[i] == c && i < s_len) {
			i++;
			cnts++;
		}
		if (c != t[j]) {
			isok = false;
			break;
		}
		while (c == t[j] && j < t_len) {
			j++;
			cntt++;
		}
		if (cnts > cntt) {
			isok = false;
			break;
		}
		if (cnts == 1 && cntt >= 2) {
			isok = false;
			break;
		}
	}
	if (i != s_len || j != t_len) isok = false; 

	if (isok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
