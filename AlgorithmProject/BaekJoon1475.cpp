#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int usingNumber[10] = { 0, };
	bool sixOrNine = false; //처음엔 6
	int answer = 0;
	string number = ""; cin >> number;

	for (int i = 0; i < number.length(); i++) {
		if (number[i] == '6' || number[i] == '9') {
			if (!sixOrNine) {
				usingNumber[6]++;
				sixOrNine = true; //9로 바꾸기
			}
			else {
				usingNumber[9]++;
				sixOrNine = false; //6으로 바꾸기
			}
		}
		else {
			usingNumber[number[i] - '0']++;
		}
	}
	for (int i = 0; i < 10; i++) answer = max(answer, usingNumber[i]);
	cout << answer;
}