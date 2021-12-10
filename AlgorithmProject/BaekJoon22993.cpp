#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	long long junwonPower; //준원이 공격력
	bool survive = true; //생존?

	vector<long long> powerStore(N);

	for (int i = 0; i < N; i++) cin >> powerStore[i];

	if (N == 1) { //1일 때 무조건 생존
		cout << "Yes";
		return 0;
	}
	sort(powerStore.begin() + 1, powerStore.end()); //준원이 빼고 오름차순 정렬
	junwonPower = powerStore[0];

	for (int i = 1; i < N; i++) { 
		if (junwonPower > powerStore[i]) junwonPower += powerStore[i]; //준원이보다 공격력 낮으면 먹힘
		else {
			survive = false; //같거나 크면 비생존
			break;
		}
	}
	if (survive) cout << "Yes";
	else cout << "No";
}