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
	int H, W;
	cin >> H >> W;

	vector<vector<int>> img1(H*2, vector<int> (W*2));
	vector<vector<int>> img2(H*2, vector<int> (W*2));
	vector<vector<int>> ans(H*2, vector<int> (W*2));

	for (int i = 0; i < H*2; i+=2) {
		for (int j = 0; j < W*2; j+=2) {
			int p;
			cin >> p;
			img1[i][j] = p;
			img1[i+1][j] = p;
			img1[i][j+1] = p;
			img1[i+1][j+1] = p;
		}
	}
	for (int i = 0; i < H*2; i+=2) {
		for (int j = 0; j < W*2; j+=2) {
			int p;
			cin >> p;
			img2[i][j] = p;
			img2[i+1][j] = p;
			img2[i][j+1] = p;
			img2[i+1][j+1] = p;
		}
	}
	rep(i,H*2-1)rep(j,W*2-1) {
		cout << (img1[i+1][j+1] + img2[i][j]) / 2;
		if (j != W*2-2) cout << " ";
		else cout << endl;
	}
	return 0;
}
