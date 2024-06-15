//// 2023-10-22
//
//#include <bits/stdc++.h>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//using namespace std;
//
//int main() {
//	fastio;
//	int N;
//	cin >> N;
//	vector<int> A(N);
//	vector<int> B(N);
//
//	for (int i = 0; i < N; i++) {
//		cin >> A[i];
//	}
//
//	for (int i = 0; i < N; i++) {
//		cin >> B[i];
//	}
//
//	sort(A.begin(), A.end());
//	sort(B.begin(), B.end(), greater<>());
//
//	//for (int i = 0; i < N; i++) {
//	//	cout << A[i] << ' ';
//	//}
//	//cout << '\n';
//
//	//for (int i = 0; i < N; i++) {
//	//	cout << B[i] << ' ';
//	//}
//	//cout << '\n';
//
//	int sum = 0;
//	for (int i = 0; i < N; i++) {
//		sum += A[i] * B[i];
//	}
//	
//
//	cout << sum << '\n';
//}