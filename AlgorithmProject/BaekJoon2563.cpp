#include <iostream>
using namespace std;

int plain[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCase, y, x, answer = 0; cin >> testCase;

	while (testCase--) {
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				plain[j][i]++;
			}
		}
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (plain[i][j] >= 1) answer++;
		}
	}
	cout << answer;
}