#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ESM[3] = { 1,1,1 };
	int answer = 1, E, S, M;

	cin >> E >> S >> M;

	while (1) {
		if (ESM[0] == E && ESM[1] == S && ESM[2] == M) {
			cout << answer; break;
		}
		ESM[0]++; ESM[1]++; ESM[2]++;
		if (ESM[0] == 16) ESM[0] = 1;
		if (ESM[1] == 29) ESM[1] = 1;
		if (ESM[2] == 20) ESM[2] = 1;
		answer++;
	}
}