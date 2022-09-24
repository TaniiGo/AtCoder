#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	int n;
	cin >> n;

	set<int> prices;
	rep(i,n) {
		int x;
		cin >> x;
		prices.insert(x);
	}
	auto itr = prices.end();
	itr--;
	itr--;
	cout << *itr << endl;
	return 0;
}
