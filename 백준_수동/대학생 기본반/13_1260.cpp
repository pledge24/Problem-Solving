// 2023-10-21

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<vector<bool>> graph;
vector<bool> visited;

vector<int> order_dfs;
vector<int> order_bfs;
int N, M, V;

void dfs(int idx) {

	for (int i = 1; i <= N; i++) {
		if (graph[idx][i] && !visited[i]) {
			
			order_dfs.push_back(i);
			//cout << order_dfs.size() << '\n';
			visited[i] = true;
			dfs(i);
		}
		
	}
	return;
}

void bfs(int idx) {

	// 큐를 생성하고 시작 노드를 큐에 추가
	queue<int> q;
	q.push(idx);
	order_bfs.push_back(idx);
	visited[idx] = true;

	while (!q.empty()) {
		// 큐에서 하나의 노드를 꺼내 출력
		int curr_pos = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (graph[curr_pos][i] && !visited[i]) {
				//cout << i << '\n';
				q.push(i);
				order_bfs.push_back(i);				
				visited[i] = true;
			}

		}

	}
	
	return;
}

int main() {
	fastio;
	
	cin >> N >> M >> V;

	graph.resize(N + 1, vector<bool>(N + 1));
	visited.resize(N + 1, false);

	int v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		graph[v1][v2] = true;
		graph[v2][v1] = true;
	}

	// print test
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		cout << graph[i][j] << " ";
	//	}
	//	cout << '\n';
	//}
	//cout << "proceed" << '\n';


	order_dfs.push_back(V);
	visited[V] = true;
	dfs(V);
	for (int elem : order_dfs) {
		cout << elem << " ";
	}
	cout << '\n';

	for (int i = 0; i < visited.size(); i++) {
		visited[i] = false;
	}

	bfs(V);


	for (int elem : order_bfs) {
		cout << elem << " ";
	}
	cout << '\n';
}