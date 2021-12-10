#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	long long junwonPower; //�ؿ��� ���ݷ�
	bool survive = true; //����?

	vector<long long> powerStore(N);

	for (int i = 0; i < N; i++) cin >> powerStore[i];

	if (N == 1) { //1�� �� ������ ����
		cout << "Yes";
		return 0;
	}
	sort(powerStore.begin() + 1, powerStore.end()); //�ؿ��� ���� �������� ����
	junwonPower = powerStore[0];

	for (int i = 1; i < N; i++) { 
		if (junwonPower > powerStore[i]) junwonPower += powerStore[i]; //�ؿ��̺��� ���ݷ� ������ ����
		else {
			survive = false; //���ų� ũ�� �����
			break;
		}
	}
	if (survive) cout << "Yes";
	else cout << "No";
}