#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int A[109];
	int max = 0;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (max < A[i]) max = A[i];
	}
	int index;
	for (int i = 1; i <= K; i++) {
		cin >> index;
		if (A[index] == max) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
