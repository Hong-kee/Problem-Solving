#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;//������ ��, ��緹�� ��
	vector<long long> lectures(N);

	long long lo = 0, hi = 0;

	for (int i = 0; i < N; i++) { //lo = �Է� �� �� �ִ�, hi = ��� ���� ������ ��
		cin >> lectures[i];
		hi += lectures[i];
		lo = max(lo, lectures[i]);
	}

	long long mid, bluerays, lectureLen = 0;
	
	while (lo <= hi) {
		bluerays = 0, lectureLen = 0; 
		long long mid = (lo + hi) / 2;

		for (int i = 0; i < N; i++) {
			if (lectureLen + lectures[i] > mid) { //���� ���� ���� ���̸� �Ѿ�� ?
				++bluerays; //��緹�� �߰�
				lectureLen = 0; //���� �ʱ�ȭ
			}
			lectureLen += lectures[i];
		}
		if (lectureLen != 0) ++bluerays; //������ ����ó��
		if (bluerays <= M) hi = mid - 1; //���� �Է� ��緹�� ���� �� ���ų� ������ �ð��� �ٿ��� ��緹�� ���� �÷�����
		else lo = mid + 1;//�ƴ϶�� �ð� �ø���
	}
	cout << lo;
}