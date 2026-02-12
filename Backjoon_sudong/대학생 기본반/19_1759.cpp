// 2023-10-22

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int L, C;
vector<char> v;
vector<bool> visited;
vector<int> vv;


bool isQulified() {
	map<char, int> mother_char{ {'a', 1},{'e', 1} ,{'i', 1}, {'o', 1} ,{'u', 1} };

	int cnt = 0;
	for (int elem : vv) {
		mother_char[v[elem]]++;

		if (mother_char[v[elem]] > 1) cnt++;
	}

	return cnt >= 1 && vv.size() - cnt >= 2;
}

void countAns() {
	if (isQulified()) {
		for (int elem : vv) {
			cout << v[elem];
		}
		cout << '\n';
	}
}

void dfs(int idx) {
	if (vv.size() == L) {
		/*for (int elem : vv) {
			cout << elem << " ";
		}
		cout << '\n';*/
		countAns();
		return;
	}

	for (int i = idx; i < C; i++) {
		if (!visited[i]) {
			visited[i] = true;
			vv.push_back(i);
			dfs(i);
			visited[i] = false;
			vv.pop_back();
		}
	}

	return;
}

int main() {
	fastio;
	
	cin >> L >> C;
	
	v.resize(C);
	visited.resize(C, false);
	for (int i = 0; i < C; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < C; i++) {
		vv.clear();
		fill(visited.begin(), visited.end(), false);

		vv.push_back(i);
		visited[i] = true;
		dfs(i);
	}

	//cout << ans << '\n';

	return 0;

}