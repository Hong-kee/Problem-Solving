#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int num, N, M; cin >> N;
	
	vector<int> cards(N);
	for (int i = 0; i < N; i++) cin >> cards[i];
	sort(cards.begin(), cards.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num; cout << upper_bound(cards.begin(), cards.end(), num) - lower_bound(cards.begin(), cards.end(), num) << ' ';
	}
}