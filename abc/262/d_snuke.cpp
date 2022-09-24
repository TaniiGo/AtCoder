#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  ll mod = 998244353;
  ll ans = 0;
  for (int m = 1; m <= n; m++) {
    vector dp(m+1, vector<ll>(m));
    dp[0][0] = 1;
    rep(i,n) {
      for (int j = m-1; j >= 0; --j) {
        rep(k,m) {
          dp[j+1][(k+a[i])%m] += dp[j][k] % mod;
		  printf("i: %d, dp[%d][%d] = %lld\n", i, j+1, (k+a[i])%m, dp[j+1][(k+a[i])%m]);
        }
		cout << endl;
      }
    }
    ans += dp[m][0] % mod;
  }
  cout << ans % mod << endl;
  return 0;
}