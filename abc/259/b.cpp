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
#define PI 3.1415926535897932384626433

int main() {
	double a, b, d;
	cin >> a >> b >> d;

	double x, y, rd;
	rd = d * M_PI / (double)180.0;
	x = a * cos(rd) - b * sin(rd);
	y = a * sin(rd) + b * cos(rd);
	printf("%.12lf %.12lf\n", x, y);
	return 0;
}
