#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int answer = 0, bookCnt, onceGet, cnt = 0; cin >> bookCnt >> onceGet;
	vector<int> distance(bookCnt);
	for (int i = 0; i < bookCnt; i++) {
		cin >> distance[i];
		if (distance[i] < 0) cnt++;
	}
	sort(distance.begin(), distance.end());

	//마이너스 거리 처리
	for (int i = 0; i < cnt; i += onceGet) {
		answer += abs(distance[i]) * 2;
	}
	//플러스 거리 처리
	for (int i = bookCnt - 1; i >= cnt; i -= onceGet) {
		answer += distance[i] * 2;
	}
	//가장 먼 곳은 마무리 지점으로
	answer -= max(abs(distance[0]), abs(distance[bookCnt - 1]));
	cout << answer;
}