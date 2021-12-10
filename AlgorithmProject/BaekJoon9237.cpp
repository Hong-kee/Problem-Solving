#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, days = 0; cin >> N;
	vector<int> trees(N);
	
	for (int i = 0; i < N; i++) cin >> trees[i];
	sort(trees.begin(), trees.end(), greater<>());

	for (int i = 0; i < N; i++) days = max(days, trees[i] + i + 1);
	cout << days + 1;
}