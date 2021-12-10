#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int L, R, answer = 0; cin >> L >> R;
	string strL = to_string(L), strR = to_string(R);
	
	//길이 다르면 0 -> 예외 처리
	if (strL.length() != strR.length()) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < strL.length(); i++) {
		if (strL[i] == '8' && strL[i] == strR[i]) answer++;
		if (strL[i] != strR[i]) break;
	}
	cout << answer;
}