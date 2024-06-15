#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool inRange(int x) {
	return 1 <= x;
}

int main() {
	fastio;
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	
	vector<map<vector<int>, int>> ans(k + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		vector<int> temp_v(k + 1);
		temp_v[v[i]]++;
		ans[v[i]][temp_v]++;
	}
	//for (int i = 1; i <= k; i++) {
	//	cout << ans[i].size() << ' ';
	//}
	//cout << '\n';

	for (int i = 1; i <= k; i++) {
		
		for (int j = 0; j < v.size(); j++) {
			int elem = v[j];
			if (inRange(i - elem)) {
				map<vector<int>, int> temp_map = ans[i - elem];
				for (auto iter = temp_map.begin(); iter != temp_map.end(); iter++) {	
					vector<int> X = iter->first;
					for (int s : X) {
						if(s)
							cout << s << ' ';
					}
					cout << '\n';
					X[j]++;
					ans[i][X]++;
				}

			}
		}
		for (int i = 1; i <= k; i++) {
			cout << ans[i].size() << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= k; i++) {
		cout << ans[i].size() << ' ';
	}
	cout << '\n';
	
	return 0;
}