// 2023-10-25

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIGITS 10
using namespace std;

int k;

vector<bool> updown;	// 왼쪽이 크면 1.
vector<bool> visited(DIGITS);
vector<int> ans;

vector<int> first_ans;
vector<int> last_ans;
bool isfirst = true;

//bool isQualified() {
//	bool isleft;
//	for (int i = 0; i < updown.size(); i++) {
//		isleft = updown[i] == '>' ? true : false;
//		
//		if (isleft != (ans[i] > ans[i + 1])) return false;
//	}
//
//	return true;
//}
void dfs(int idx) {

	if (ans.size() == k + 1) {


		//for (int elem : ans) {
		//	cout << elem << ' ';
		//}
		//cout << '\n';
		if (isfirst) {
			first_ans = ans;
			isfirst = false;
		}
		else {
			last_ans = ans;
		}
		
		return;
	}
	for (int i = 0; i <= 9; i++) {		
		if (!visited[i] && (updown[ans.size() - 1] == (ans.back() > i)) ) {			
			ans.push_back(i);
			visited[i] = true;
			dfs(i);
			ans.pop_back();
			visited[i] = false;
		}
	}

	return;
}

int main() {
	fastio;
	cin >> k;
	
	updown.resize(k);

	char c;
	for (int i = 0; i < k; i++) {
		cin >> c;
		updown[i] = (c == '>') ? true : false;
	}

	for (int i = 0; i <= 9; i++) {
		ans.clear();
		fill(visited.begin(), visited.end(), false);

		ans.push_back(i);
		visited[i] = true;
		dfs(i);
		
	}

	stringstream ss;
	for (auto it = last_ans.begin(); it != last_ans.end(); it++) {		
		ss << *it;
	}
	cout << ss.str() << '\n';

	stringstream sss;
	for (auto it = first_ans.begin(); it != first_ans.end(); it++) {
		sss << *it;
	}
	cout << sss.str() << '\n';

	//for (int elem : last_ans) {
	//	cout << elem << ' ';
	//}

	//cout << '\n';
	//for (int elem : first_ans) {
	//	cout << elem << ' ';
	//}
	//cout << '\n';
	


	return 0;
}