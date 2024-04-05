//// 2023-10-22
//
//#include <bits/stdc++.h>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//using namespace std;
//
//int main() {
//	fastio;
//	int N, M;
//	cin >> N >> M;
//
//	map<string, int> note;
//	vector<string> ans;
//	string name;
//	
//	for (int i = 0; i < N + M; i++) {
//		cin >> name;
//		note[name]++;
//
//		if (note[name] > 1) {
//			ans.push_back(name);
//			//cout << name << '\n';
//		}
//	}
//
//	sort(ans.begin(), ans.end());
//
//	cout << ans.size() << '\n';
//	for (string s : ans) {
//		cout << s << '\n';
//	}
//	
//}