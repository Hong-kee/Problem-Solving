#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int testCase; cin >> testCase;
	
	while (testCase--) {
		int wordsCnt; cin >> wordsCnt;
		deque<char> wordsStore(wordsCnt), answerStore;
		for (int i = 0; i < wordsCnt; i++) cin >> wordsStore[i];		
		for (int i = 0; i < wordsCnt; i++) {
			if (answerStore.empty()){
				answerStore.push_back(wordsStore[i]); continue;
			}
			if (answerStore[0] >= wordsStore[i]) answerStore.push_front(wordsStore[i]);
			else answerStore.push_back(wordsStore[i]);
		}
		for (int i = 0; i < wordsCnt; i++) cout << answerStore[i];
		cout << '\n';
	}
}