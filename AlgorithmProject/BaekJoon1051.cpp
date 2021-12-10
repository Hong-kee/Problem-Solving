#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int rect[51][51];
int y, x, answer = 1, n = 0;

void findSize(int y, int x, int k) {
	if (rect[y][x] == rect[y][x + k] &&
		rect[y][x + k] == rect[y + k][x + k] &&
		rect[y + k][x + k] == rect[y + k][x] &&
		rect[y + k][x] == rect[y][x]) {
		answer = max(answer, (k + 1) * (k + 1));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> y >> x; 
	
	for (int i = 1; i <= y; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			rect[i][j + 1] = s[j] - '0';
		}
	}

	n = max(y, x); //Å« °ª

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			for (int k = 1; k < n; k++) {
				if (i + k > y || j + k > x) break;
				else findSize(i, j, k);
			}
		}
	}
	cout << answer;
}