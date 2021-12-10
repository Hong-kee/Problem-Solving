#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long X, Y; cin >> X >> Y;//���� Ƚ��, �̱� ����

	long long lo = 1, hi = 1000000000, win = Y * 100 / X; //lo = �ּ� �� ��, hi = �ִ� �� ��, win = �·�
	
	while (lo <= hi) {
		long long mid = (lo + hi) / 2, winComp = (Y + mid) * 100 / (X + mid); //mid = �߰� ��, winComp = �߰� ���� �־��� �� �·�
		
		if (win < winComp) hi = mid - 1; //���� �·��� ���������� �ּ� �� ���� �̾Ƴ��� ���� hi�� ���
		else lo = mid + 1;//���� �ƴ϶�� lo�� ����
	}
	if (lo == 1000000001) cout << -1;//���� ó���� ���� ��� ������ �� �·��� �ö��� �ʾ����� -1 ���
	else cout << lo;
}