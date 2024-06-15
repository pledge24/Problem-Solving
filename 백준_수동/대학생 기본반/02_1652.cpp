#include <iostream>
#include <vector>

#define DIRECTIONS 4

using namespace std;

int main1652(void) {

	int N;

	cin >> N;

	vector<vector<bool>> room(N, std::vector<bool>(N));
	
	// input
	char c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c;
			room[i][j] = (c == '.') ? true : false;
		}
	}

	int cnt_rows = 0, cnt_cols = 0;
	for (int i = 0; i < N; i++) {
		
		int streak = 0;
		for (int j = 0; j < N; j++) {
			if (room[i][j]) streak++;
			else { 
				if (streak >= 2) cnt_rows++;
				streak = 0;
			}

		}
		if (streak >= 2) cnt_rows++;
	}

	for (int i = 0; i < N; i++) {

		int streak = 0;
		for (int j = 0; j < N; j++) {
			if (room[j][i]) streak++;
			else {
				if (streak >= 2) cnt_cols++;
				streak = 0;
			}

		}
		if (streak >= 2) cnt_cols++;
	}

	cout << cnt_rows << " " << cnt_cols << '\n';

	return 0;
}