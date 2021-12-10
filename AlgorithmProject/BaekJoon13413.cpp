#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int testCase; cin >> testCase;

	while (testCase--) {
		int s1B = 0, s2B = 0, answer, len;
		cin >> len;
		string s1, s2; cin >> s1 >> s2;

		for (int i = 0; i < len; i++) {
			if (s1[i] != s2[i]) {
				if (s1[i] == 'B') s1B++;
				else s2B++;
			}
		}

		if (s1B == 0 || s1B == len) answer = s1B;
		else answer = abs(s1B - s2B) + min(s1B, s2B);

		cout << answer << '\n';
	}
}