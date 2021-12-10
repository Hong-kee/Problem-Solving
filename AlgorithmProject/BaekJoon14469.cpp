#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cowsNum, answer = -1; cin >> cowsNum;
	vector<pair<int, int>> cowsInfo(cowsNum);

	for (int i = 0; i < cowsNum; i++) {
		cin >> cowsInfo[i].first >> cowsInfo[i].second;
	}
	sort(cowsInfo.begin(), cowsInfo.end());

	for (int i = 0; i < cowsInfo.size(); i++) {
		if (answer >= cowsInfo[i].first) answer += cowsInfo[i].second;
		else answer = cowsInfo[i].first + cowsInfo[i].second;
	}
	cout << answer;
}