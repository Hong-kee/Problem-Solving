#include <iostream>
#include <string>

using namespace std;

bool alphaCheck[26]; //알파벳 연속 체크

void init() { //초기화
	for (int i = 0; i < 26; i++) {
		alphaCheck[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num, answer = 0;
	string groupWord = "";
	cin >> num;

	for (int i = 0; i < num; i++) {
		bool isCheck = true; //맞는 그룹체커인지
		init();
		cin >> groupWord;
		//cccaaby
		for (int j = 0; j < groupWord.length(); j++) {
			if (!alphaCheck[groupWord[j] - 'a']) { //나오지 않은 단어?
				if (j == groupWord.length() - 1) break; //마지막 단어 처리
				if (groupWord[j] == groupWord[j + 1]) { // 다음 단어랑 같아?
					continue;
				}
				else alphaCheck[groupWord[j] - 'a'] = true; // 다르면 체크 처리
			}
			else { //나온 단어가 또 나와 ?
				isCheck = false; //또 나오면 안돼요
			}
		}
		if (isCheck) answer++; //그룹 체커면 += 1
	}
	cout << answer;
}