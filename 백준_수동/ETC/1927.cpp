// 2023-10-26

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;
	//vector<int> test;

	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		if (n) {
			pq.push(n);
		}
		else {
			if (pq.empty()) {
				cout << '0' << '\n';
				//test.push_back(0);
				continue;
			}
			//test.push_back(pq.top());
			cout << pq.top() << '\n'; // 현재 우선 순위 큐에서 가장 큰 원소를 출력
			pq.pop(); // 가장 큰 원소를 큐에서 제거
		}
	}

	//for (int elem : test) {
	//	cout << elem << " ";
	//}
	//cout << '\n';
	return 0;
}