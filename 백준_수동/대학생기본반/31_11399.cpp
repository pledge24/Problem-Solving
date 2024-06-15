// 2023-10-22

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int N;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int sum = 0;
	int s = 0;
	for (int i = 0; i < N; i++){
		sum += s + v[i];
		s += v[i];
		//cout << sum << '\n';
	}

	//cout << "ss" << '\n';
	cout << sum << '\n';

	return 0;
}