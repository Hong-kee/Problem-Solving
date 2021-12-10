#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	long long answer = 0;
	priority_queue<long long, vector<long long>, greater<long long>> cards;

	while (N--) {
		long long card; cin >> card;
		cards.push(card);
	}

	while (cards.size() != 1) {
		long long cardValue = cards.top(); cards.pop();
		cardValue += cards.top(); cards.pop();
		answer += cardValue;
		cards.push(cardValue);
	}
	cout << answer;
}