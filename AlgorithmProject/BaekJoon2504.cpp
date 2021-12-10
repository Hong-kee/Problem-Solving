#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string bracket; cin >> bracket;
	stack<char> s;
	int answer = 0, standardAnswer = 1;
	bool flag = false;

	for (int i = 0; i < bracket.length(); i++) {
		if (bracket[i] == '(') {
			standardAnswer *= 2;
			s.push('(');
		}
		else if (bracket[i] == '[') {
			standardAnswer *= 3;
			s.push('[');
		}
		else if (bracket[i] == ')' && (s.empty() || s.top() != '(')) {
			flag = true; break;
		}
		else if (bracket[i] == ']' && (s.empty() || s.top() != '[')) {
			flag = true; break;
		}
		else if (bracket[i] == ')') {
			if (bracket[i - 1] == '(') answer += standardAnswer;
			s.pop(); standardAnswer /= 2;
		}
		else if (bracket[i] == ']') {
			if (bracket[i - 1] == '[') answer += standardAnswer;
			s.pop(); standardAnswer /= 3;
		}
	}
	if (flag || !s.empty()) cout << 0;
	else cout << answer;
}