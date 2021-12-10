#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	long long answer = 0;
	vector<long long> pizzaBoxes[1001];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			long long boxHeight; cin >> boxHeight; pizzaBoxes[i].push_back(boxHeight);
		}
		pizzaBoxes[i].push_back(*max_element(pizzaBoxes[i].begin(), pizzaBoxes[i].end())); //가장 큰 높이 처리 (side)
	}

	for (int i = 0; i < m; i++) {
		long long maxHeight = -1;

		for (int j = 0; j < n; j++) {
			maxHeight = max(maxHeight, pizzaBoxes[j][i]); //가장 큰 높이 처리 (front)
		}
		pizzaBoxes[n].push_back(maxHeight);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pizzaBoxes[i][j] < pizzaBoxes[i][m] && pizzaBoxes[i][j] < pizzaBoxes[n][j]) answer += pizzaBoxes[i][j]; //side & front와 비교해서 작으면 누적
		}
	}
	cout << answer;
}