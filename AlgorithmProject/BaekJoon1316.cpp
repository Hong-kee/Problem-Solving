#include <iostream>
#include <string>

using namespace std;

bool alphaCheck[26]; //���ĺ� ���� üũ

void init() { //�ʱ�ȭ
	for (int i = 0; i < 26; i++) {
		alphaCheck[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num, answer = 0;
	string groupWord = "";
	cin >> num;

	for (int i = 0; i < num; i++) {
		bool isCheck = true; //�´� �׷�üĿ����
		init();
		cin >> groupWord;
		//cccaaby
		for (int j = 0; j < groupWord.length(); j++) {
			if (!alphaCheck[groupWord[j] - 'a']) { //������ ���� �ܾ�?
				if (j == groupWord.length() - 1) break; //������ �ܾ� ó��
				if (groupWord[j] == groupWord[j + 1]) { // ���� �ܾ�� ����?
					continue;
				}
				else alphaCheck[groupWord[j] - 'a'] = true; // �ٸ��� üũ ó��
			}
			else { //���� �ܾ �� ���� ?
				isCheck = false; //�� ������ �ȵſ�
			}
		}
		if (isCheck) answer++; //�׷� üĿ�� += 1
	}
	cout << answer;
}