#include <iostream>
#include <queue>
using namespace std;

/*
using heap sort
*/
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int answer, N, K; cin >> N >> K;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		pq.push(num);
	}
	while (K--) {
		answer = pq.top();
		pq.pop();
	}
	cout << answer;
}