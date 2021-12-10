#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	deque<pair<int, int>> printerStatus; //������ ����
	//�׽�Ʈ ���̽�, ������ ��, ���ϴ� ���� �ε���, �߿䵵, ����
	int testCase, documentCnt, answerIdx, importance, answer = 1; cin >> testCase;

	while (testCase--) {
		printerStatus.clear(); answer = 1; //�ʱ�ȭ
		cin >> documentCnt >> answerIdx;

		for (int i = 0; i < documentCnt; i++) {
			cin >> importance;
			printerStatus.push_back(make_pair(importance, i));
		}

		while (1) {
			bool flag = false;
			for (int i = 0; i < printerStatus.size(); i++) {
				if (printerStatus[0].first < printerStatus[i].first) { //�߿䵵�� �������ٸ� ?
					printerStatus.push_back(make_pair(printerStatus[0].first, printerStatus[0].second));
					printerStatus.pop_front(); flag = true; break;
				}
			}
			if (!flag) { //���� �߿��ϴٸ� ?
				if (answerIdx == printerStatus[0].second) { //���ϴ� �ε������ ?
					cout << answer<<'\n';
					break;
				}
				printerStatus.pop_front(); answer++;
			}
		}
	}
}