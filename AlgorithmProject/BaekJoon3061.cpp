#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int testCase; cin >> testCase;

	while (testCase--) {
		int num, answer = 0; cin >> num;
		vector<int> ladder(num);

		for (int i = 0; i < num; i++) cin >> ladder[i];

		for (int i = 0; i < num; i++) { //Bubble Sort로 오름차순 카운트 체크
			for (int j = i + 1; j < num; j++) {
				if (ladder[i] > ladder[j]) { 
					swap(ladder[i], ladder[j]);
					++answer;
				}
			}
		}
		cout << answer << '\n';
	}
}