#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
	int n;
	cin >> n;

	set<string> strs;
	int max = -1;
	int index;
	rep(i,n) {
		string str;
		cin >> str;
		int score;
		cin >> score;
		if (strs.find(str) == strs.end()) {
			strs.insert(str);
			if (score > max) {
				max = score;
				index = i + 1;
			}
		}
	}
	cout << index << endl;
	return 0;
}