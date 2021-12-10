#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, answer = 0, maxHeight = -1; cin >> N;
	vector<pair<int, int>> sticks(N);

	for (int i = 0; i < N; i++) cin >> sticks[i].first >> sticks[i].second; //x, y�Է�
	for (int i = 0; i < N; i++) maxHeight = max(maxHeight, sticks[i].second); //���� ū �� ã��
	sort(sticks.begin(), sticks.end()); //��ġ�� ���� �������� ����

	int y = sticks[0].second, x = sticks[0].first; //�ʱ갪 ����

	for (int i = 1; i < N; i++) { //���ʺ��� ������
		if (y < sticks[i].second) {
			answer += (sticks[i].first - x) * y;
			y = sticks[i].second;
			x = sticks[i].first;
		}
	}
	
	y = sticks[N - 1].second, x = sticks[N - 1].first;
	for (int i = sticks.size() - 2; i >= 0; i--) { //������ ������
		if (y <= sticks[i].second) {
			answer += (x - sticks[i].first) * y;
			y = sticks[i].second;
			x = sticks[i].first;
		}
	}
	cout << answer + maxHeight;
}