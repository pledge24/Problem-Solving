//#include <bits/stdc++.h>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//using namespace std;
//
//int T, n;
//
//struct node {
//	bool active = false;
//	vector<int> link;
//};
//
//void func1() {
//	cin >> n;
//	
//	// input 
//	vector<long long> v(n);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//
//	sort(v.begin(), v.end());
//
//	//for (long long elem : v) {
//	//	cout << elem << " ";
//	//}
//	//cout << '\n';
//
//	node connected[10][10];
//
//	for (long long elem : v) {
//		string s = to_string(elem);
//		if (s.length() == 1) {
//			connected[0][s[0]].active = true;
//			continue;
//		}
//		for (int i = 0; i < s.length() - 1; i++) {
//			
//			if (!connected[i][s[i]].active) {
//				connected[i][s[i]].active = true;
//				connected[i][s[i]].link.push_back(s[i + 1] - '0');
//			}
//	}
//
//	//for (int i = 0; i < v.size() - 1; i++) {
//	//	int exp1 = log10(v[i]);
//	//	for (int j = i + 1; j < v.size(); j++) {
//	//		
//	//		int exp_gap = log10(v[j]) - exp1;
//	//		long long num2 = v[j] / pow(10, exp_gap);
//	//		//cout << exp1 << "s" << exp_gap << '\n';
//	//		//cout << v[i] << " " << num2 << '\n';
//	//		if (v[i] == num2) {
//	//			cout << "NO" << '\n';
//	//			return;
//	//		}
//	//	}
//	//}
//
//	//cout << "YES" << '\n';
//	return;
//}
//int main() {
//	fastio;
//	
//	cin >> T;
//
//	for (int i = 0; i < T; i++) {
//		func1();
//	}
//	//cout << (int)log10(100) << '\n';
//}