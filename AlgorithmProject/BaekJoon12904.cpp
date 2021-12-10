#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s1, s2; cin >> s1 >> s2;
	
	while (s1.length() != s2.length()) {
		if (s2.back() == 'A') s2.pop_back();
		else {
			s2.pop_back();
			reverse(s2.begin(), s2.end());
		}
	}
	
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i]) {
			cout << 0; return 0;
		}
	}
	cout << 1;
}