#include <iostream>
#include <string>
using namespace std;

int numArr[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testCase, A, B, answer = 0; cin >> testCase;

	for (int i = 0; i < 1000001; i++) {
		string number = to_string(i);
		int cnt = 0;
		for (int j = 0; j < number.length(); j++) {
			if (number[j] == '0') cnt++;
		}
		numArr[i] = cnt;
	}
	while (testCase--) {
		answer = 0;
		cin >> A >> B;
		for (int i = A; i <= B; i++) answer += numArr[i];
		cout << answer << '\n';
	}
}