#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	int n, x;
	cin >> n >> x;
	char ans = ((x-1) / n) + 'A';

	cout << ans << endl;
	return 0;
}
