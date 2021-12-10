#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int answer = 987654321, studentsNum; cin >> studentsNum;
	vector<int> studentsInfo(studentsNum * 2);

	for (int i = 0; i < studentsNum * 2; i++) cin >> studentsInfo[i];
	sort(studentsInfo.begin(), studentsInfo.end());

	for (int i = 0; i < studentsInfo.size() / 2; i++) answer = min(answer, studentsInfo[i] + studentsInfo[studentsInfo.size() - i - 1]);
	cout << answer;
	
}