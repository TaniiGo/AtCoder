#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i <= (n); i++)
#define all(a) begin(a), end(a)
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

ll modpow(ll a, ll b, ll m) {
	ll p = a;
	ll ans = 1;
	rep(i,32) {
		if ((b & (0x01 << i)) != 0) {
			ans *= p;
			ans %= m;
		}
		p *= p;
		p %= m;
	}
	return (ans);
}

ll pow(ll a, ll b) {
	ll p = a;
	ll ans = 1;
	rep(i,32) {
		if ((b & (0x01 << i)) != 0) {
			ans *= p;
		}
		p *= p;
	}
	return (ans);
}

ll Division(ll a, ll b, ll m) {
	return ((a * modpow(b, m - 2, m)) % m);
}



int main() {
	ll N, M, K;
	cin >> N >> M >> K;
	vector<pll> A; // {cost, A}
	rep(i,N) {
		ll a;
		cin >> a;
		A.emplace_back(0, a);
	}

	ll ans = 0;
	sort(all(A));

	// 上位のビットから立たせることができるか見ていくぞ
	for (ll i = 31; i >= 0; i--) {
		vector<pll> B; // {cost, A}
		ll lowerAll = (1LL << i) - 1;
		for (auto [c, a] : A) {
			if ((a & (1LL << i)) != 0) {
				// すでにそのbitが立ってる時
				B.emplace_back(c, a);
			}
			else {
				// そのbitを立たすために必要なコスト
				a &= lowerAll;
				ll cost = (1LL << i) - a + c;
				// 調整したってことは目標としてたbit以外0
				// そのbitはもういらないから0を代入
				a = 0;
				B.emplace_back(cost, a);
			}
		}
		// k要素取った時にM以下か
		bool ok = true;
		sort(all(B));

		if (B.size() < K) ok = false;
		else {
			ll totalCost = 0;
			rep(j,K) totalCost += B[j].first;
			if (totalCost > M) ok = false;
		}

		if (ok) {
			swap(A, B);
			ans += (1LL << i);
		}
	}
	cout << ans << endl;	
	return 0;
}
