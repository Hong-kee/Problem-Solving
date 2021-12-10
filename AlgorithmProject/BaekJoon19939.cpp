#include <iostream>
using namespace std;

int main() {
	int N, K, standard; cin >> N >> K;
	standard = K * (K + 1) / 2;
	
	if (N - standard < 0) cout << -1;
	else {
		if ((N - standard) % K == 0) cout << K - 1;
		else cout << K;
	}
}