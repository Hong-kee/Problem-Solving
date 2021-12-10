#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int K, num, answer = 0; cin >> K;
	vector<int>numStore;

	while (K--) {
		cin >> num;
		if (num != 0) numStore.push_back(num);
		else numStore.pop_back();
	}

	for (int i = 0; i < numStore.size(); i++) answer += numStore[i];
	cout << answer;
}