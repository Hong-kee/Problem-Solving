#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, answer; cin >> N;
	vector<int> lengthStore(N);
	
	for (int i = 0; i < N; i++) cin >> lengthStore[i];
	sort(lengthStore.begin(), lengthStore.end(), greater<>());

	for (int i = 0; i < lengthStore.size(); i++) {
		if (i + 2 >= lengthStore.size()) break;
		if (lengthStore[i] >= lengthStore[i + 1] + lengthStore[i + 2]) continue;
		for (int j = i + 1; j < lengthStore.size(); j++) {
			if (lengthStore[i] >= lengthStore[j] + lengthStore[j + 1]) continue;
			for (int k = j + 1; k < lengthStore.size(); k++) {
				if (lengthStore[i] < lengthStore[j] + lengthStore[k]) {
					answer = lengthStore[i] + lengthStore[j] + lengthStore[k];
					cout << answer;
					return 0;
				}
				else break;
			}
		}
	}
	cout << -1;
}