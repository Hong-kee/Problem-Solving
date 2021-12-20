#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	priority_queue<int, vector<int>, greater<>> pq;
	int size, N; cin >> N;
	size = N * N;

	for (int i = 0; i < size; i++) {
		int num; cin >> num;

		if (pq.size() >= N && pq.top() < num) pq.pop();
		else if (pq.size() >= N && pq.top() >= num) continue;
		pq.push(num);
	}
	cout << pq.top();
}