#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s, answer; cin >> s;
	int cnt = 0, cntA = 0, cntB = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '.') { // .�� ���Դ�?
			if (cnt % 2 != 0) { //�ٵ� X�� ������ Ȧ��?
				cout << -1; //����
				return 0;
			}
			else {
				cntA = cnt / 4; // AAAA�� ����
				cntB = ((cnt %= 4)) / 2; //BB�� ����
				for (int i = 0; i < cntA; i++) {
					answer.append("AAAA");
				}
				for (int i = 0; i < cntB; i++) {
					answer.append("BB");
				}
				answer += '.';
				cnt = 0;
			}
		}
		else cnt++; // .�� �ƴ϶��?
	}

	//������ ó��
	if (cnt % 2 != 0) {
		cout << -1; return 0;
	}
	cntA = cnt / 4;
	cntB = ((cnt %= 4))/2;
	for (int i = 0; i < cntA; i++) {
		answer.append("AAAA");
	}
	for (int i = 0; i < cntB; i++) {
		answer.append("BB");
	}
	cout << answer;
}