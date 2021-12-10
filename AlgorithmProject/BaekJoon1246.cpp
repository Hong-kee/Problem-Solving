#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, M, price = 0, answer = 0; cin >> N >> M;
	vector<int> payCost(M);

	for (int i = 0; i < M; i++) cin >> payCost[i];
	sort(payCost.begin(), payCost.end());

	for (int i = 0; i < M; i++) {
		if (payCost.size() - i < N && answer < payCost[i] * (payCost.size() - i)) {
			price = payCost[i]; answer = payCost[i] * (payCost.size() - i);
		}
		else if (payCost.size() - i >= N && answer < payCost[i] * (payCost.size() - i)) {
			price = payCost[i]; answer = payCost[i] * N;
		}
	}
	cout << price << ' ' << answer;
}