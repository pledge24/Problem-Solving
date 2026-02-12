// 2023-10-22

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int N;
	cin >> N;
	vector<pair<int, int>> meetings;

	int start, end;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		meetings.push_back(make_pair(start, end));
	}

	sort(meetings.begin(), meetings.end());

	//cout << '\n';
	//// print
	//for (pair<int, int> elem : meetings) {
	//	cout << elem.first << " " << elem.second << '\n';
	//}

	pair<int, int> last_meeting;
	last_meeting = meetings[0];
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		
		if (last_meeting.second > meetings[i].second) {
			last_meeting = meetings[i];
			//cout << meetings[i].first << " " << meetings[i].second << '\n';
		}
		else if (last_meeting.second <= meetings[i].first) {
			last_meeting = meetings[i];
			//cout << meetings[i].first << " " << meetings[i].second << '\n';
			cnt++;
		}
	}

	//for (pair<int, int> elem : ans) {
	//	cout << elem.first << " " << elem.second << '\n';
	//}
	cout << cnt << '\n';

	return 0;

}