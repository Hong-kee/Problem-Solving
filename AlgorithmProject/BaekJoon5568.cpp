#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool check[10];
int n, k;
set<string>s;
vector<string> numberStore;

void dfs(int idx, int cnt, string number) {
	if (cnt == k) {
		s.insert(number);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			dfs(i, cnt + 1, number + numberStore[i]);
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		numberStore.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		check[i] = true;
		dfs(i, 1, numberStore[i]);
		check[i] = false;
	}

	cout << s.size();
}