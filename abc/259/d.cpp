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

struct circle {
	int x;
	int y;
	int r;
};

int main() {
	int n;
	cin >> n;
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	vector<vector<int>> g(n);
	vector<circle> circles(n);
	rep(i,n) {
		circle a;
		cin >> a.x >> a.y >> a.r;
		circles[i] = a;
	}
	rep(i,n) {
		rep(j,n) {
			if (i == j) continue;
			int xdif = circles[i].x - circles[j].x;
			int ydif = circles[j].y - circles[j].y;
			double len = sqrt(xdif * xdif + ydif * ydif);
			if (len <= (double)(circles[i].r + circles[j].r)) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	bool isok = false;
	rep(i,n) {
		int dis = abs(sx - circles[i].x) + abs(sy - circles[i].y);
		if (dis == circles[i].r) {

		}
	}
}

/* 隣接する円をグラフにして格納していく
sx syが円上にある円から幅優先探索で調べる
調べる中でtx tyが円上にある円についたらtrue
つかなかったらfalse
*/