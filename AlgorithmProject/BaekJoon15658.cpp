#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minAnswer = 1000000001;
int maxAnswer = -1000000001;

vector<int> numberStore, selectOper;
int operStore[4]; // +, -, *, /

void calculate() {
	int tempAnswer = numberStore[0];
	for (int i = 1; i < numberStore.size(); i++) {
		if (selectOper[i - 1] == 0) tempAnswer += numberStore[i];
		else if (selectOper[i - 1] == 1) tempAnswer -= numberStore[i];
		else if (selectOper[i - 1] == 2) tempAnswer *= numberStore[i];
		else  tempAnswer /= numberStore[i];
	}
	//최솟값, 최댓값 세팅
	minAnswer = min(minAnswer, tempAnswer);
	maxAnswer = max(maxAnswer, tempAnswer);
}

void pushOperator(int cnt) {
	if (cnt == numberStore.size() - 1) { //만일 숫자 -1 개의 연산자가 선택됐다면 ?
		calculate();
		return;
	}
	for (int i = 0; i < 4; i++) { //연산자 선택
		if (operStore[i] > 0) {
			operStore[i]--;
			selectOper.push_back(i);
			pushOperator(cnt + 1);
			selectOper.pop_back();
			operStore[i]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		numberStore.push_back(num);
	}
	for (int i = 0; i < 4; i++) cin >> operStore[i];
	
	pushOperator(0);
	cout << maxAnswer << '\n' << minAnswer;
}
