#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string switchStatus; cin >> switchStatus;
	int answer = 0; bool allNo = false;

	while (!allNo) { //��� N�� �ƴϸ� ��� ������
		for (int i = 0; i < switchStatus.length(); i++) {
			if (i == switchStatus.length() - 1 && switchStatus[i] == 'N') {//�������� N�̸� ?
				allNo = true; //��!
				break;
			}

			if (switchStatus[i] == 'Y') { //i��°�� Y�� ?
				for (int j = i; j < switchStatus.length(); j += (i + 1)) {
					if (switchStatus[j] == 'Y') switchStatus[j] = 'N';
					else switchStatus[j] = 'Y';
				}
				++answer;
				break;
			}
		}
	}
	cout << answer;
}