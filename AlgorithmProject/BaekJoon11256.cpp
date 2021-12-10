#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCase; cin >> testCase;

	while (testCase--) {
		int answer = 1, candyAmount, boxAmount, r, c; cin >> candyAmount >> boxAmount;
		vector<int> boxStore(boxAmount);

		for (int i = 0; i < boxAmount; i++) {
			cin >> r >> c;
			boxStore[i] = r * c;
		}
		sort(boxStore.rbegin(), boxStore.rend()); //상자가 큰 것 -> 작은 것 순으로 정렬

		for (int i = 0; i < boxStore.size(); i++) {
			if (candyAmount - boxStore[i] > 0) { //만일 다 못 담았다면 ?
				candyAmount -= boxStore[i];
				answer++;
			}
			else break; //다 담았으면 탈출
		}
		cout << answer << '\n';
	}
}