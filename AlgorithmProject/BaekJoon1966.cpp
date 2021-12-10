#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	deque<pair<int, int>> printerStatus; //프린터 세팅
	//테스트 케이스, 문서의 수, 원하는 정답 인덱스, 중요도, 정답
	int testCase, documentCnt, answerIdx, importance, answer = 1; cin >> testCase;

	while (testCase--) {
		printerStatus.clear(); answer = 1; //초기화
		cin >> documentCnt >> answerIdx;

		for (int i = 0; i < documentCnt; i++) {
			cin >> importance;
			printerStatus.push_back(make_pair(importance, i));
		}

		while (1) {
			bool flag = false;
			for (int i = 0; i < printerStatus.size(); i++) {
				if (printerStatus[0].first < printerStatus[i].first) { //중요도가 떨어진다면 ?
					printerStatus.push_back(make_pair(printerStatus[0].first, printerStatus[0].second));
					printerStatus.pop_front(); flag = true; break;
				}
			}
			if (!flag) { //가장 중요하다면 ?
				if (answerIdx == printerStatus[0].second) { //원하는 인덱스라면 ?
					cout << answer<<'\n';
					break;
				}
				printerStatus.pop_front(); answer++;
			}
		}
	}
}