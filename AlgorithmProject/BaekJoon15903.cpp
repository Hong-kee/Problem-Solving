#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//카드 갯수, 몇 번 합체하는지
	long long answer = 0;
	int n, m; cin >> n >> m;
	vector<long long> cards(n);

	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	while (m--) {
		sort(cards.begin(), cards.end());
		long long cardValue = cards[0] + cards[1];
		cards[0] = cards[1] = cardValue;
	}

	for (int i = 0; i < n; i++) answer += cards[i];
	cout << answer;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//카드 갯수, 몇 번 합체하는지
	long long answer = 0, cardValue;
	int n, m; cin >> n >> m;
	priority_queue<long long, vector<long long>, greater<long long>> cards;

	while (n--) {
		cin >> cardValue;
		cards.push(cardValue);
	}

	while (m--) {
		cardValue = cards.top(); cards.pop();
		cardValue += cards.top(); cards.pop();
		cards.push(cardValue); cards.push(cardValue);
	}

	while (!cards.empty()) {
		answer += cards.top();
		cards.pop();
	}
	cout << answer;
}