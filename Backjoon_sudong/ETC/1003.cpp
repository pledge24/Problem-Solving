// 2023-09-21

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> getNumOfOI(int N) {
	vector<pair<int, int>> OIcounter;
	OIcounter.push_back(make_pair(1, 0));
	OIcounter.push_back(make_pair(0, 1));

	pair<int, int> p1, p2;
	for (int i = 2; i <= N; i++) {
		p1 = OIcounter[i - 1];
		p2 = OIcounter[i - 2];
		OIcounter.push_back(make_pair(p1.first + p2.first, p1.second + p2.second));
	}

	return OIcounter[N];
}

int main(void) {

	int T;

	cin >> T;

	int N;
	for (int i = 0; i < T; i++) {
		cin >> N;
		pair<int, int> ans = getNumOfOI(N);
		printf("%d %d\n", ans.first, ans.second);
	}

	return 0;
}