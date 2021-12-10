#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int testCase; cin >> testCase;
	vector<int>numberStore;

	while (testCase--) {
		for (int i = 0; i < 10; i++) {
			int n; cin >> n;
			numberStore.push_back(n);
		}
		sort(numberStore.begin(), numberStore.end());
		cout << numberStore[7] << '\n';
		numberStore.clear();
	}
}