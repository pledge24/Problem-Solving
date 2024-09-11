#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct edge_data {
    int node;
    int cost;
};

// Prim 알고리즘을 사용한 최소 비용 계산
long long prim_algorithm(int N, vector<int>& well_costs, vector<vector<int>>& pipe_costs) {
    vector<bool> inMST(N + 1, false);  // MST에 포함 여부
    vector<int> min_cost(N + 1, INT_MAX);  // 최소 비용 배열
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 가상의 우물 노드에서 시작한다고 가정
    for (int i = 1; i <= N; i++) {
        pq.push({well_costs[i], i});  // 우물 설치 비용을 우선순위 큐에 삽입
    }

    long long total_cost = 0;
    int added_edges = 0;

    while (!pq.empty() && added_edges < N) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (inMST[node]) continue;  // 이미 MST에 포함된 노드는 무시
        inMST[node] = true;  // MST에 포함
        total_cost += cost;
        added_edges++;

        // 해당 노드와 연결된 다른 농장들을 확인
        for (int i = 1; i <= N; i++) {
            if (!inMST[i] && pipe_costs[node][i] < min_cost[i]) {
                min_cost[i] = pipe_costs[node][i];
                pq.push({pipe_costs[node][i], i});
            }
        }
    }

    return total_cost;
}

int main() {
    int N;
    cin >> N;

    vector<int> well_costs(N + 1);
    vector<vector<int>> pipe_costs(N + 1, vector<int>(N + 1));

    // 우물 설치 비용 입력
    for (int i = 1; i <= N; i++) {
        cin >> well_costs[i];
    }

    // 농장 간 물 공급 비용 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> pipe_costs[i][j];
        }
    }

    // Prim 알고리즘을 사용하여 최소 비용 계산
    long long result = prim_algorithm(N, well_costs, pipe_costs);
    cout << result << endl;

    return 0;
}
