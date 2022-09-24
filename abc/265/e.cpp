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
	vector<pair<ll, ll>> a(3);
	rep(i,3) cin >> a[i].first >> a[i].second;
	
	set<pair<ll, ll>> st;
	rep(i,M) {
		ll x, y;
		cin >> x >> y;
		st.emplace(x, y);
	}

	ll c = 0;
	ll mod = 998244353;
	map<pair<ll,ll>, ll> dp;
	dp[pair<ll,ll>(0,0)] = 1;
	rep(i,N) {
		map<pair<ll,ll>, ll> p;
		swap(dp, p);
		// ll c = 0;
		for (auto [x, cnt] : p) {
			rep(j,3) {
				pair<ll, ll> nx = x;
				nx.first += a[j].first;
				nx.second += a[j].second;
				if (st.count(nx)) continue;
				dp[nx] += (cnt % mod);
				dp[nx] = dp[nx] % mod;
				printf("c: %lld, i: %d, x: %lld, y: %lld, cnt=%lld\n", c, i, nx.first, nx.second, dp[nx]);
				c++;
			}
		}
	}
	ll ans = 0;
	for (auto s : dp) {
		ans += (s.second % mod);
		ans = ans % mod;
	}
	cout << ans << endl;
	cout << pow(3, 10) << endl;
	return 0;
}
