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
		sort(boxStore.rbegin(), boxStore.rend()); //���ڰ� ū �� -> ���� �� ������ ����

		for (int i = 0; i < boxStore.size(); i++) {
			if (candyAmount - boxStore[i] > 0) { //���� �� �� ��Ҵٸ� ?
				candyAmount -= boxStore[i];
				answer++;
			}
			else break; //�� ������� Ż��
		}
		cout << answer << '\n';
	}
}