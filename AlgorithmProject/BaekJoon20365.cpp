#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int len, cntB = 0, cntR = 0; cin >> len; //����, �ɰ� B�� ����, �ɰ� R�� ����
	string problemList = ""; cin >> problemList; //�־��� ���ڿ� 

	if (problemList.length() == 1) { //����ó�� (1�̸� Out of Index)
		cout << 1;
		return 0;
	}

	//�ɰ��� ���� ���
	for (int i = 0; i < problemList.length() - 1; i++) {
		if (problemList[i] == problemList[i + 1]) continue;
		if (problemList[i] == 'B') ++cntB;
		else ++cntR;
	}

	//���ڿ� �� �ڿ� ���� �� ó��
	if (problemList[problemList.length() - 1] != problemList[problemList.length() - 2] && problemList[problemList.length() - 1] == 'B'
		|| problemList[problemList.length() - 1] == problemList[problemList.length() - 2] && problemList[problemList.length() - 1] == 'B') ++cntB;
	else if (problemList[problemList.length() - 1] != problemList[problemList.length() - 2] && problemList[problemList.length() - 1] == 'R'
		|| problemList[problemList.length() - 1] == problemList[problemList.length() - 2] && problemList[problemList.length() - 1] == 'R') ++cntR;

	cout << 1 + min(cntB, cntR);
}