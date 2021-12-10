#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int answer = 0, N; cin >> N;
	deque<int> items(N);

	for (int i = 0; i < N; i++) cin >> items[i];
	sort(items.begin(), items.end(), greater<>());

	while (items.size() >= 3) {
		answer += items[0] + items[1];
		items.pop_front(); items.pop_front(); items.pop_front();
	}
	if (items.size() > 0) {
		for (int i = 0; i < items.size(); i++) answer += items[i];
	}
	cout << answer;
}