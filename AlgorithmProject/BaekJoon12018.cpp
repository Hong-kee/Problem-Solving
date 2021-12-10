#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int subjectCnt, getMileage, answer = 0; cin >> subjectCnt >> getMileage;
	vector<int> needPoint;

	while (subjectCnt--) {
		int people, canJoin; cin >> people >> canJoin;
		vector<int> curPoint(people);

		for (int i = 0; i < people; i++) cin >> curPoint[i];
		sort(curPoint.begin(), curPoint.end(), greater<>());

		if (canJoin > curPoint.size()) needPoint.push_back(1);
		else needPoint.push_back(curPoint[canJoin - 1]);
	}	
	sort(needPoint.begin(), needPoint.end());

	for (int i = 0; i < needPoint.size(); i++) {
		if (getMileage - needPoint[i] >= 0) {
			answer++;
			getMileage -= needPoint[i];
		}
		else break;
	}
	cout << answer;
}