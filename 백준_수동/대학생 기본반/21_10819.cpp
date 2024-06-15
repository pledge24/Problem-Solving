//// 2023-10-22
//
//#include <bits/stdc++.h>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//using namespace std;
//
//int N, ans = -1;
//vector<int> v;
//vector<bool> visited;
//vector<int> vv;
//
//void getGap() {
//	int sum = 0;
//	for (int i = 0; i < N - 1; i++) {
//		sum += abs(v[vv[i]] - v[vv[i + 1]]);
//	}
//
//	ans = ans < sum ? sum : ans;
//}
//
//void dfs(int idx) {
//	if (vv.size() == N) {
//		//for (int elem : vv) {
//		//	cout << elem << " ";
//		//}
//		//cout << '\n';
//		getGap();
//		return;
//	}
//
//	for (int i = 0; i < N; i++) {
//		if (!visited[i]) {
//			visited[i] = true;
//			vv.push_back(i);
//			dfs(i);
//			visited[i] = false;
//			vv.pop_back();
//		}
//	}
//
//	return;
//}
//
//int main() {
//	fastio;
//	
//	cin >> N;
//	
//	v.resize(N);
//	visited.resize(N, false);
//	for (int i = 0; i < N; i++) {
//		cin >> v[i];
//	}
//
//	for (int i = 0; i < N; i++) {
//		vv.clear();
//		fill(visited.begin(), visited.end(), false);
//
//		vv.push_back(i);
//		visited[i] = true;
//		dfs(i);
//	}
//
//	cout << ans << '\n';
//
//	return 0;
//
//}