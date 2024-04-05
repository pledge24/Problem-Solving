// 2023-09-21

#include <iostream>
#include <vector>

#define MAXN 101

using namespace std;

bool networks[MAXN][MAXN] = { false };
bool visited[MAXN] = { false };

int computers, connects;

void transmit_warm(int idx) {

	for (int i = 1; i <= computers; i++) {
		if (idx == i) continue;

		if (networks[idx][i] && !visited[i] ) {
			visited[i] = true;
			transmit_warm(i);
		}
	}
}

int main2606(void) {

	cin >> computers >> connects;

	int src, dst;
	for (int i = 0; i < connects; i++) {
		cin >> src >> dst;
		networks[src][dst] = true;
		networks[dst][src] = true;
	}

	visited[1] = true;
	transmit_warm(1);

	int cnt = 0;
	for (int i = 2; i <= computers; i++) {
		if (visited[i]) {
			cnt++;
			//cout << i << " ";
		}
	}
	//cout << '\n';

	cout << cnt << '\n';

	return 0;
}