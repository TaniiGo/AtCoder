#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define all(a) begin(a), end(a)
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T &b)
{
	if (a < b)
	{
		a = b; // aをbで更新
		return true;
	}
	return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T &b)
{
	if (a > b)
	{
		a = b; // aをbで更新
		return true;
	}
	return false;
}

ll modpow(ll a, ll b, ll m)
{
	ll p = a;
	ll ans = 1;
	for (ll i = 0; i < 32; i++)
	{
		if ((b & (1LL << i)) != 0)
		{
			ans *= p;
			ans %= m;
		}
		p *= p;
		p %= m;
	}
	return (ans);
}

ll pow(ll a, ll b)
{
	ll p = a;
	ll ans = 1;
	for (ll i = 0; i < 60; i++)
	{
		if ((b & (1ll << i)) != 0)
		{
			ans *= p;
		}
		p *= p;
	}
	return (ans);
}

ll Division(ll a, ll b, ll m)
{
	return ((a * modpow(b, m - 2, m)) % m);
}

int main()
{
	int N, M;
	cin >> N >> M;
	ll mod = 998244353;

	vector<pll> d(3);
	rep(i,3) {
		cin >> d[i].first >> d[i].second;
	}
	set<pll> st;
	rep(i,M) {
		ll x, y;
		cin >> x >> y;
		st.emplace(x, y);
	}

	map<pll, ll> dp;
	dp[pll(0,0)] = 1;
	rep1(i,N) {
		map<pll, ll> p;
		swap(dp, p);
		for (auto [x, cnt] : p) {
			rep(j,3) {
				pll nx = x;
				nx.first += d[j].first;
				nx.second += d[j].second;
				if (st.count(nx)) continue;
				dp[nx] += cnt;
				dp[nx] %= mod;
			}
		}
	}
	ll ans = 0;
	for (auto [x,cnt] : dp) {
      ans += cnt;
      ans %= mod;
    }
	cout << ans << endl;
	return 0;
}

