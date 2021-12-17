#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
규칙성 찾아서 queue에 push, 한 자릿수 씩 늘려가기
*/
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N = 0, answer = 9; cin >> N;
	queue<string> numberStore;
	
	//Exception
	if (N <= 10) {
		cout << N;
		return 0;
	}

	//Init Setting
	for (int i = 0; i < 10; i++) numberStore.push(to_string(i));

	while (!numberStore.empty()) {
		for (int i = 0; i < numberStore.size(); i++) {
			char backNumber = numberStore.front().back();
			string number = numberStore.front();

			numberStore.pop();

			for (int i = 0; i < 10; i++) {
				char extendNumber = i + '0';
				
				if (backNumber <= extendNumber) break;
				else {
					answer++;
					if (answer == N) {
						cout << number + extendNumber;
						return 0;
					}
					numberStore.push(number + extendNumber);
				}
			}
		}
	}
	cout << -1;
}