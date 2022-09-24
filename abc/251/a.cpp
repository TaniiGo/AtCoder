#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s;
	cin >> s;
	int len = s.length();

	for (int i = 0; i < (6 / len); i++)
	{
		cout << s;
	}
	cout << endl;
	return 0;
}
