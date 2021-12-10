#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�̷� -> ������ �� ã��
	//�̷�,����,�ڸ��� ����
	int A, B, m, answer = 0; cin >> A >> B; cin >> m;
	vector<int> store;

	//�̷� -> 10����
	for (int i = 0; i < m; i++) {
		int number; cin >> number;
		answer += number * pow(A, m - 1 - i);
	}
	//10���� -> ����
	while (1) {
		if (answer / B == 0) {
			store.push_back(answer); break;
		}
		else {
			store.push_back(answer % B);
			answer /= B;
		}
	}
	for (int i = store.size() - 1; i >= 0; i--) cout << store[i] << ' ';
}