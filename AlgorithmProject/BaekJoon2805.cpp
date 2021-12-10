#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; long long M; cin >> N >> M; //������ ��, ���������ϴ� ������ ����
	vector<long long> treeStore(N);//�������� ����

	for (int i = 0; i < N; i++) cin >> treeStore[i];
	sort(treeStore.begin(), treeStore.end());

	long long answer = 0, lo = 0, hi = treeStore[N - 1]; //lo = ���� 0, hi = ���� ���� ����

	while (lo <= hi) {
		answer = 0;
		long long mid = (lo + hi) / 2; //�߰� �� ���

		for (int i = 0; i < N; i++) {
			if (mid > treeStore[i]) continue;
			answer += treeStore[i] - mid;
		}
		if (answer >= M) lo = mid + 1; //���� �ڸ� �������� ������ ���� ���������� �ϴ� ������ ���̺��� ũ�ų� ������ ���� ���� ������ �Ѵ�.
		else if (answer < M) hi = mid - 1;// �ƴ϶�� �ְ� ���� ����� �Ѵ�.
	}
	cout << hi;
}