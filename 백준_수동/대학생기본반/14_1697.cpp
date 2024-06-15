//2023-10-24

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

#define JUMP 0 
#define FORWARD 1
#define BACKWARD 2 

using namespace std;

int N, K;

void bfs() {
	
	queue<pair<int, int>> q;
	map<int, bool> visited;
	q.push(make_pair(N, 0));

	if (N >= K) {
		cout << abs(K - N) << '\n';
		return;
	}
	
	int min_hops = 1000000;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		int pos = p.first;
		int hops = p.second;
		for (int i = 0; i < 3; i++) {
			int temp = pos;
			switch (i)
			{
			case JUMP:
				if(temp < K)
					temp *= 2;
				break;
			case FORWARD:
				temp++;
				break;
			case BACKWARD:
				temp--;
				break;
			}

			////cout << pos << " " << hops << '\n';
			//if (temp == K) {
			//	cout << hops + 1 << '\n';
			//	return;
			//}
			//cout << visited[pos] << '\n';
			if (!visited[temp] && min_hops > (hops+1)) {
			   
				if (temp < K) {
					//cout << temp << " " << hops << '\n';
					visited[temp] = true;
					q.push(make_pair(temp, hops + 1));
				}
				else {
					//cout << temp << " XXXXXXXX " << hops << '\n';
					int over_hops = abs(temp - K) + hops + 1;
					min_hops = min_hops > over_hops ? over_hops : min_hops;
				}
				
			}
			
		}
	}

	cout << min_hops << '\n';
	return;
}


int main() {
	fastio;	
	cin >> N >> K;
	
	bfs();

	return 0;
}