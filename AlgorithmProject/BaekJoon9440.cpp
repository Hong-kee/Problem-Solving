#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1) {
		deque<int> dq1, dq2, dq3;
		int num; cin >> num;
		if (num == 0) return 0;

		for (int i = 0; i < num; i++) {
			int a; cin >> a;
			dq1.push_back(a);
		}
		sort(dq1.begin(), dq1.end());
		bool flag = true; int idx = 0;
		for (int i = 0; i < dq1.size(); i++) {
			if (dq1[i] == 0) {
				if (flag) {
					dq2.push_back(0);
					flag = false;
				}
				else {
					dq3.push_back(0);
					flag = true;
				}
			}
			else {
				idx = i;
				break;
			}
		}
		dq2.push_front(dq1[idx]); dq3.push_front(dq1[idx + 1]);
		for (int i = idx + 2; i < dq1.size(); i++) {
			if (dq2.size() < dq3.size()) {
				dq2.push_back(dq1[i]);
				flag = false;
			}
			else if (dq2.size() > dq3.size()){
				dq3.push_back(dq1[i]);
				flag = true;
			}
			else {
				bool check = true;
				for (int j = 0; j < dq2.size(); j++) {
					if (dq2[j] < dq3[j]) {
						dq2.push_back(dq1[i]);
						check = false;
						break;
					}
				}
				if (check) dq3.push_back(dq1[i]);
			}
		}
		string s1, s2;

		for (int i = 0; i < dq2.size(); i++) {
			s1 += (dq2[i] + '0');
		}
		for (int i = 0; i < dq3.size(); i++) {
			s2 += (dq3[i] + '0');
		}
		cout << stoi(s1) + stoi(s2) << '\n';
	}
}