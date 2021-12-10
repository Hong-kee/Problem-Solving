#include <iostream>
#include <string>
using namespace std;

int chessBoard[9][9]; //체스판
int dir[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };// 북을 기준으로 시계방향
int N, kingY, kingX, rockY, rockX;
string king, rock;

bool inBound(int y, int x) {
	return y >= 1 && y <= 8 && x >= 1 && x <= 8;
}


bool isOnRock(int direction) {
	if (rockY == kingY + dir[direction][0] && rockX == kingX + dir[direction][1]) return true;
	return false;
}

void setDirection(string toMove) {
	bool flag = true;
	if (toMove == "B") {
		if (inBound(kingY + dir[0][0], kingX + dir[0][1])) { //킹이 갈 수 있나요 ?
			if (isOnRock(0)) { // 갔는데 돌이 있나요 ?
				if (inBound(rockY + dir[0][0], rockX + dir[0][1])) { //돌은 갈 수 있나요 ?
					rockY += dir[0][0]; rockX += dir[0][1];
				}
				else flag = false;
			}
			if (flag) {
				kingY += dir[0][0]; kingX += dir[0][1];
			}
		}
	}
	else if (toMove == "RB") {
		if (inBound(kingY + dir[1][0], kingX + dir[1][1])) {
			if (isOnRock(1)) {
				if (inBound(rockY + dir[1][0], rockX + dir[1][1])) { //돌은 갈 수 있나요 ?
					rockY += dir[0][0]; rockX += dir[1][1];
				}
				else flag = false;
			}
			if (flag) {
				kingY += dir[1][0]; kingX += dir[1][1];
			}
		}
	}
	else if (toMove == "R") {
		if (inBound(kingY + dir[2][0], kingX + dir[2][1])) {
			if (isOnRock(2)) {
				if (inBound(rockY + dir[2][0], rockX + dir[2][1])) { //돌은 갈 수 있나요 ?
					rockY += dir[2][0]; rockX += dir[2][1];
				}
				else flag = false;
			}
			if (flag) {
				kingY += dir[2][0]; kingX += dir[2][1];
			}
		}
	}
	else if (toMove == "RT") {
		if (inBound(kingY + dir[3][0], kingX + dir[3][1])) {
			if (isOnRock(3)) {
				if (inBound(rockY + dir[3][0], rockX + dir[3][1])) { //돌은 갈 수 있나요 ?
					rockY += dir[3][0]; rockX += dir[3][1];
				}
				else flag = false;
			}
			if (flag) {
				kingY += dir[3][0]; kingX += dir[3][1];
			}
		}
	}
	else if (toMove == "T") {
		if (inBound(kingY + dir[4][0], kingX + dir[4][1])) {
			if (isOnRock(4)) {
				if (inBound(rockY + dir[4][0], rockX + dir[4][1])) { //돌은 갈 수 있나요 ?
					rockY += dir[4][0]; rockX += dir[4][1];
				}
				else flag = false;
			}
			if (flag) {
				kingY += dir[4][0]; kingX += dir[4][1];
			}
		}
	}
	else if (toMove == "LT") {
		if (inBound(kingY + dir[5][0], kingX + dir[5][1])) {
			if (isOnRock(5)) {
				if (inBound(rockY + dir[5][0], rockX + dir[5][1])) { //돌은 갈 수 있나요 ?
					rockY += dir[5][0]; rockX += dir[5][1];
				}
				else flag = false;
			}
			if (flag) {
				kingY += dir[5][0]; kingX += dir[5][1];
			}
		}
	}
	else if (toMove == "L") {
		if (inBound(kingY + dir[6][0], kingX + dir[6][1])) {
			if (isOnRock(6)) {
				if (inBound(rockY + dir[6][0], rockX + dir[6][1])) { //돌은 갈 수 있나요 ?
					rockY += dir[6][0]; rockX += dir[6][1];
				}
				else flag = false;
			}
			if (flag) {
				kingY += dir[6][0]; kingX += dir[6][1];
			}
		}
	}
	else {
		if (inBound(kingY + dir[7][0], kingX + dir[7][1])) {
			if (isOnRock(7)) {
				if (inBound(rockY + dir[7][0], rockX + dir[7][1])) { //돌은 갈 수 있나요 ?
					rockY += dir[7][0]; rockX += dir[7][1];
				}
				else flag = false;
			}
			if (flag) {
				kingY += dir[7][0]; kingX += dir[7][1];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> king >> rock >> N;
	//초기 위치 세팅
	kingY = king[1] - '0'; kingX = king[0] - 'A' + 1;
	rockY = rock[1] - '0'; rockX = rock[0] - 'A' + 1;

	while (N--) {
		string toMove; cin >> toMove;
		setDirection(toMove);
	}
	cout << (char)(kingX + 'A' - 1) << kingY << '\n';
	cout << (char)(rockX + 'A' - 1) << rockY << '\n';
}