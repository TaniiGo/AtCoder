#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	vector<int> masu(4);
	int p = 0;

	int n;
	cin >> n;
	rep(i,n) {
		masu[0] = 1;
		int a;
		cin >> a;
		for (int j = 3; j >= 0; j--) {
			if (masu[j] == 1) {
				masu[j] = 0;
				if ((j + a) > 3) p++;
				else masu[j + a] = 1;
			}
		}
	}
	cout << p << endl;
	return 0;
}
