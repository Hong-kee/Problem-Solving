#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testCase; cin >> testCase;

	while (testCase--) {
		int N; cin >> N;
		long long answer = 0;
		vector<long long> stocks(N);

		for (int i = 0; i < N; i++) {
			cin >> stocks[i];
		}
		
		//���� �ֽ� ����, ó�� ���� ��
		long long cnt = 0, maxStock = stocks.back();
		for (int i = stocks.size() - 2; i >= 0; i--) {
			//���� ���� �� ũ�ٸ� �ֽ� ����
			if (maxStock > stocks[i]) {
				cnt++; answer -= stocks[i];
			}
			//�� ū ���� ������ ū �� ����
			else if (maxStock < stocks[i]) {
				answer += cnt * maxStock;
				cnt = 0; maxStock = stocks[i];
			}
		}
		//����� �� �Ȱ� ������ ó��
		if (cnt > 0) answer += cnt * maxStock;
		cout << answer << '\n';
	}
}