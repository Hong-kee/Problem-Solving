#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int triangle[502][502];
	int h, answer = -1; cin >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}

	//모서리 세팅
	for (int i = 1; i < h; i++) {
		triangle[i][0] += triangle[i - 1][0];
		triangle[i][i] += triangle[i - 1][i - 1];
	}

	//중간 값들 처리
	for (int i = 2; i < h; i++) {
		for (int j = 1; j < i; j++) {
			triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
		}
	}
	for (int i = 0; i < h; i++) answer = max(triangle[h - 1][i], answer);

	cout << answer;
}