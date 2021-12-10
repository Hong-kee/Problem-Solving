#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int len, cntB = 0, cntR = 0; cin >> len; //길이, 쪼갠 B의 갯수, 쪼갠 R의 갯수
	string problemList = ""; cin >> problemList; //주어진 문자열 

	if (problemList.length() == 1) { //예외처리 (1이면 Out of Index)
		cout << 1;
		return 0;
	}

	//쪼개진 갯수 계산
	for (int i = 0; i < problemList.length() - 1; i++) {
		if (problemList[i] == problemList[i + 1]) continue;
		if (problemList[i] == 'B') ++cntB;
		else ++cntR;
	}

	//문자열 맨 뒤에 남은 것 처리
	if (problemList[problemList.length() - 1] != problemList[problemList.length() - 2] && problemList[problemList.length() - 1] == 'B'
		|| problemList[problemList.length() - 1] == problemList[problemList.length() - 2] && problemList[problemList.length() - 1] == 'B') ++cntB;
	else if (problemList[problemList.length() - 1] != problemList[problemList.length() - 2] && problemList[problemList.length() - 1] == 'R'
		|| problemList[problemList.length() - 1] == problemList[problemList.length() - 2] && problemList[problemList.length() - 1] == 'R') ++cntR;

	cout << 1 + min(cntB, cntR);
}