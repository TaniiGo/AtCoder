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
	ll N, P, Q, R;
	cin >> N >> P >> Q >> R;

	vector<ll> A(N+1);
	rep1(i, N) cin >> A[i];
	vector<ll> S(N+1);
	S[0] = 0;
	for (int i = 1; i <= N; i++) {
		S[i] = S[i - 1] + A[i];
	}

	bool ok = false;
	for (int x = 0; x <= (N - 3); x++) {
		if (ok == true) break;
		auto Sy = lower_bound(all(S), S[x] + P);
		if (Sy != end(S) && *Sy == S[x] + P) {
			auto Sz = lower_bound(all(S), *Sy + Q);
			if (Sz != end(S) && *Sz == *Sy + Q) {
				auto Sw = lower_bound(all(S), *Sz + R);
				if (Sw != end(S) && *Sw == *Sz + R) ok = true;
			}
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
