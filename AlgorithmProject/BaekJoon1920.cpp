#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N;
	vector<int>numberStore(N);

	for (int i = 0; i < N; i++) cin >> numberStore[i];
	sort(numberStore.begin(), numberStore.end());

	cin >> M; vector<int>targetStore(M);
	for (int i = 0; i < M; i++) cin >> targetStore[i];

	for (int i = 0; i < M; i++) {
		if (binary_search(numberStore.begin(), numberStore.end(), targetStore[i])) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}