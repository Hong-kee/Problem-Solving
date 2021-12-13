#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int num, N, M; cin >> N >> M;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		cin >> num; pq.push(num);
	}
	for (int i = 0; i < M; i++) {
		cin >> num; pq.push(num);
	}
	while (!pq.empty()) { cout << pq.top() << ' '; pq.pop(); }
}