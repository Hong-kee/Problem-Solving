#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K, N; cin >> K >> N;//������ ����, �ʿ��� ����
	vector<long long> lineStore(K);

	for (int i = 0; i < K; i++) cin >> lineStore[i];
	sort(lineStore.begin(), lineStore.end());

	long long answer = 0, lo = 1, hi = lineStore[K - 1];

	while (lo <= hi) {
		answer = 0;
		long long mid = (lo + hi) / 2;

		for (int i = 0; i < K; i++) answer += lineStore[i] / mid; //������ ����ġ�� �ڸ���
		if (answer >= N) lo = mid + 1; //���� �ڸ� ������ ������ ���ų� ������ �ڸ��� ���� �ø���
		else hi = mid - 1;//�ݴ��� ��� �ڸ��� ���� ���̱�
	}
	cout << hi;
}