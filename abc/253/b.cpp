#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	int x, y;
	int cnt = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			char c;
			cin >> c;
			if (c == 'o')
			{
				if (cnt)
				{
					cout << abs(j - x) + abs(i - y) << endl;
					return 0;
				}
				x = j;
				y = i;
				cnt++;
			}
		}
	}
	return 0;
}