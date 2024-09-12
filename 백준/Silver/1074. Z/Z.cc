#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int pow2(int N) {
	int num = 1;
	for (int i = 0; i < N; i++) {
		num *= 2;
	}

	return num;
}
int main() {
	fastio;
	int N, r, c;
	cin >> N >> r >> c;

	int ans = 0;
	while (N > 0) {
		N--;
		int half_size = pow2(N);
		int sector = 0;
		if (half_size <= r) {
			sector += 2;
			r -= half_size;
			
		}
		if (half_size <= c) {
			sector += 1;
			c -= half_size;
		}

		//cout << sector << '\n';
		ans += sector * half_size * half_size;
		//cout << ans << '\n';
	}

	cout << ans << '\n';
	return 0;
}