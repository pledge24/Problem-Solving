// 2023-10-18

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> ans;
vector<int> test;

bool check = false;

bool isCorrect() {
	int sum = 0;
	for (int elem : ans) {
		sum += elem;
	}

	return sum == 100;
}

void dfs(int idx, int cnt) {
	if (cnt == 7) {
		if (!check && isCorrect()) {
			sort(ans.begin(), ans.end());
			for (int elem : ans) {
				cout << elem << '\n';
			}
			check = true;
		}		
		return;
	}

	for (int i = idx + 1; i < 9; i++) {
		ans.push_back(test[i]);
		dfs(i, cnt + 1);
		ans.pop_back();
	}
}

int main() {
	fastio;

	int h;
	for (int i = 0; i < 9; i++) {
		cin >> h;
		test.push_back(h);
	}

	for (int i = 0; i < 9; i++) {
		ans.clear();
		ans.push_back(test[i]);
		dfs(i, 1);
	}
	
	return 0;
}