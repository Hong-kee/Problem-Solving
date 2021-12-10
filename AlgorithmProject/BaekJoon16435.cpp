#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, L; cin >> N >> L;
	vector<int> fruits(N);
	
	for (int i = 0; i < N; i++) cin >> fruits[i];
	sort(fruits.begin(), fruits.end());

	for (int i = 0; i < N; i++) {
		if (fruits[i] <= L) L++;
		else break;
	}
	cout << L;
}