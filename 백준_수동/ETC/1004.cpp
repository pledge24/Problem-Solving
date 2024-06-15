// 2023-09-21

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isIncluded(int x1, int y1, int cx, int cy, int r) {
	return sqrt(pow(abs(x1 - cx), 2) + pow(abs(y1 - cy), 2)) < r;
}

int main(void) {

	int T; 

	cin >> T;

	int x1, y1, x2, y2, N;
	for (int i = 0; i < T; i++) {

		cin >> x1 >> y1 >> x2 >> y2 >> N;
				
		int cx, cy, r, cnt = 0;
		for (int j = 0; j < N; j++) {
			cin >> cx >> cy >> r;
			if (isIncluded(x1, y1, cx, cy, r) ^ isIncluded(x2, y2, cx, cy, r)) cnt++;
		}

		cout << cnt << '\n';
		
		
	}
	

	return 0;
}