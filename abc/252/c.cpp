#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;

	cin >> n;
	string slot[109];

	for (int i = 0; i < n; i++) {
		cin >> slot[i];
	}

	int ans = 1001001;
	int time;
	for (int x = 0; x < 10; x++) {
		int cnt[9];
		for (int i = 0; i < 10; i++) cnt[i] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				if (slot[i][j] == ('0' + x)) cnt[j]++;
			}
		}
		time = 0;
		for (int i = 0; i < 10; i++) {
			time = max(time, i + 10 * (cnt[i] - 1));
		}
		ans = min(ans, time);
	}
	cout << ans << endl;
	return 0;
}
