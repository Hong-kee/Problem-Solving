#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K, answer = 0; cin >> N >> K;
	vector<int> heightDiff(N-1), height(N);

	for (int i = 0; i < N; i++) cin >> height[i];
	for (int i = 0; i < N - 1; i++) heightDiff[i] = height[i + 1] - height[i];
	sort(heightDiff.begin(), heightDiff.end());
	for (int i = 0; i < N - K; i++) answer += heightDiff[i];
	cout << answer;
}