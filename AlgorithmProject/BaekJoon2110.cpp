#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, C; cin >> N >> C;

	vector<int> house(N);
	for (int i = 0; i < N; i++) cin >> house[i];
	sort(house.begin(), house.end());

	//lo = �ּ� �Ÿ��� 1, hi = �ִ� �Ÿ��� �� �� - ó�� ��, dist = ������ �Ÿ�
	int lo = 1, hi = house[N - 1] - house[0], dist = 0;

	while (lo <= hi) {
		int mid = (lo + hi) / 2, router = 1, start = house[0];
		
		for (int i = 1; i < N; i++) {
			dist = house[i] - start; //�Ÿ��� �����Ѵ�.
			if (mid <= dist) { //���� ������ �Ÿ��� ���� �Ÿ����� ũ�ų� ������
				router++;//������ ��ġ
				start = house[i];//��ġ�� ���� ��������
			}
		}
		if (router >= C) lo = mid + 1;//���� �����⸦ ��ġ�� ���� �־��� �����⺸�� ���ų� ������ ���� �Ÿ��� ����
		else hi = mid - 1;//�ݴ�� ���� �Ÿ��� ����
	}
	cout << hi;
}