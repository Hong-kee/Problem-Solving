#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, answer = 0, temp; cin >> N; //카드 갯수, 정답
	int cards[100001];
	for (int i = 0; i < N; i++) {
		cin >> temp;
		cards[temp] = i;
	}
	for (int i = 0; i < N; i++) {
		if (cards[i] > cards[i + 1]) ++answer;
	}
	cout << answer;
}