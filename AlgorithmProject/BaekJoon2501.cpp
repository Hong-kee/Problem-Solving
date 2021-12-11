#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int answer, N, K; cin >> N >> K;
	vector<int> v;
	
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) v.push_back(i);
	}
	if (v.size() < K) answer = 0;
	else answer = v[K - 1];
	cout << answer;
}