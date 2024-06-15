////2023-10-17
//
//#include <bits/stdc++.h>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//using namespace std;
//
//vector<vector<int>> connect;
//vector<bool> visited;
//
//void bfs(int start_v) {
//    // 큐를 생성하고 시작 노드를 큐에 추가
//    queue<int> q;
//    q.push(start_v);
//
//    // 시작 노드를 방문한 것으로 표시
//    visited[start_v] = true;
//
//    while (!q.empty()) {
//        // 큐에서 하나의 노드를 꺼내 출력
//        int vertex = q.front();
//        //cout << vertex << " ";
//        q.pop();
//
//        // 해당 노드의 인접한 노드들을 방문
//        for (int neighbor : connect[vertex]) {
//            if (!visited[neighbor]) {
//                // 방문하지 않은 노드를 큐에 추가하고 방문 표시
//                q.push(neighbor);
//                visited[neighbor] = true;
//            }
//        }
//    }
//}
//int main11724() {
//	fastio;
//	int V, E;
//
//	cin >> V >> E;
//
//	connect.resize(V+1);
//	visited.resize(V+1, false);
//
//	int v1, v2;
//	for (int i = 0; i < E; i++) {
//		cin >> v1 >> v2;
//		connect[v1].push_back(v2);
//		connect[v2].push_back(v1);
//	}
//
//    int start_v, ans = 0;
//    while (1) {    
//        start_v = -1;
//        for (int i = 1; i <= V; i++) {
//            if (!visited[i]) {
//                start_v = i;
//                break;
//            }
//        }
//
//        if (start_v != -1) {
//            bfs(start_v);
//            ans++;
//        }
//        else {
//            break;
//        }
//    }
//
//    cout << ans << '\n';
//
//    return 0;
//}