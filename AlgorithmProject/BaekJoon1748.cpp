#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int standardNumber[10] = { 0, 9, 9 + 2 * 90, 9 + 2 * 90 + 3 * 900, 9 + 2 * 90 + 3 * 900 + 4 * 9000, 9 + 2 * 90 + 3 * 900 + 4 * 9000 + 5 * 90000,
	9 + 2 * 90 + 3 * 990 + 4 * 9990 + 5 * 99990 + 6 * 900000, 9 + 2 * 90 + 3 * 900 + 4 * 9000 + 5 * 90000 + 6 * 900000 + 7 * 9000000,
	9 + 2 * 90 + 3 * 900 + 4 * 9000 + 5 * 90000 + 6 * 900000 + 7 * 9000000 + 8 * 90000000,
	9 + 2 * 90 + 3 * 900 + 4 * 9000 + 5 * 90000 + 6 * 900000 + 7 * 9000000 + 8 * 90000000 + 9};

	int answer = 0, number; cin >> number;

	if ((int)log10(number) == 0) answer += number;
	else if ((int)log10(number) == 9) answer += standardNumber[9];
	else answer += standardNumber[(int)log10(number)] + ((int)log10(number) + 1) * (number - pow(10, (int)log10(number))) + ((int)log10(number) + 1);
	cout << answer;
}
