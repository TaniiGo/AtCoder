#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	vector<vector<int>> b(k);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i % k].push_back(a[i]);
	}

	for (int i = 0; i < k; i++) {
		sort(b[i].rbegin(), b[i].rend());
	}

	sort(a.begin(), a.end());

	vector<int> na;
	for (int i = 0; i < n; i++) {
		na.push_back(b[i % k].back());
		b[i % k].pop_back();
	}
	
	if (a == na) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
