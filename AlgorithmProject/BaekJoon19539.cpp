#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, totalModTwo = 0,totalHeight = 0; cin >> N;
	vector<int> modTwoTrees, modThreeTrees; //각 나무를 2로 나누었을 때, 3으로 나누었을 때
	
	for (int i = 0; i < N; i++) {
		int value; cin >> value;
		totalHeight += value;
		modTwoTrees.push_back(value / 2);
		modThreeTrees.push_back(value / 3);
	}
	//예외
	if (totalHeight % 3 != 0) {
		cout << "NO";
		return 0;
	}
	totalHeight /= 3;
	
	for (int i = 0; i < N; i++) totalModTwo += modTwoTrees[i];

	if (totalModTwo >= totalHeight) cout << "YES";
	else cout << "NO";

}