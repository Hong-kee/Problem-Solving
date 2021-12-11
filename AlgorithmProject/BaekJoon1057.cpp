#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int answer = 0, N, jimin, hansu; cin >> N >> jimin >> hansu;

	while (jimin != hansu) {
		if (jimin % 2 == 0) jimin /= 2;
		else jimin = (jimin + 1) / 2;

		if (hansu % 2 == 0) hansu /= 2;
		else hansu = (hansu + 1) / 2;

		++answer;
	}
	if (answer == 0) answer = 1;
	cout << answer;
}