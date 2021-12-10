#include <iostream>
#include <string>

using namespace std;

bool checkSelf[10001]; //셀프 넘버 체크

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);

	for (int i = 1; i <= 10000; i++) {
		string s = to_string(i);
		int selfNumber = stoi(s);
		
		for (int j = 0; j < s.length(); j++) {
			selfNumber += s[j] - '0';
		}

		if (selfNumber <= 10000) checkSelf[selfNumber] = true;
	}

	for (int i = 1; i < 10001; i++) {
		if (!checkSelf[i]) cout << i << '\n';
	}
}