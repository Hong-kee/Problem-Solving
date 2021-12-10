#include <iostream>
#include <vector>
using namespace std;

vector<int>callNumber(25);
int board[5][5];

bool checkBingo() {
	int cntBingo = 0, cnt = 0;
	//가로
	for (int i = 0; i < 5; i++) {
		cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (board[i][j] == -1) {
				cnt++;
			}
		}
		if (cnt == 5) cntBingo++;
	}

	//세로
	for (int i = 0; i < 5; i++) {
		cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (board[j][i] == -1) {
				cnt++;
			}
		}
		if (cnt == 5) cntBingo++;
	}

	//대각선
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (board[i][i] == -1) cnt++;
	}
	if (cnt == 5) cntBingo++;


	//대각선
	cnt = 0;
	for (int i = 4; i >= 0; i--) {
		if (board[4 - i][i] == -1) cnt++;
	}
	if (cnt == 5) cntBingo++;
	
	//result
	if (cntBingo >= 3) return true;
	return false;
}

void checkBoard(int number) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (board[i][j] == number) {
				board[i][j] = -1;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < 25; i++) {
		cin >> callNumber[i];
	}
	for (int i = 0; i < 25; i++) {
		checkBoard(callNumber[i]);
		if (checkBingo()) {
			cout << i + 1; 
			return 0;
		}
	}
}