#include <iostream>
using namespace std;

int balloonsHeight[1000002];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int balloonsNum, answer = 0; cin >> balloonsNum;

	for (int i = 0; i < balloonsNum; i++) {
		int balloonHeight; cin >> balloonHeight;
		if (balloonsHeight[balloonHeight + 1] == 0) {
			balloonsHeight[balloonHeight]++;
			answer++;
		}
		else {
			balloonsHeight[balloonHeight + 1]--;
			balloonsHeight[balloonHeight]++;
		}
	}
	cout << answer;
}