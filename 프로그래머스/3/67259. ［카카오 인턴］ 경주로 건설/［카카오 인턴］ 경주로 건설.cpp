#include <bits/stdc++.h>

using namespace std;

int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct NodeData {
    int x, y, dir, cost;
    bool operator>(const NodeData& other) const {
        return cost > other.cost;
    }
};

int solution(vector<vector<int>> board) {
    N = board.size();
    // dist[x][y][direction]
    int dist[25][25][4];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<4; k++) dist[i][j][k] = 1e9;

    priority_queue<NodeData, vector<NodeData>, greater<NodeData>> pq;

    // 시작점에서 오른쪽과 아래쪽으로 이동 가능한 경우 초기화
    for(int i=0; i<4; i++) {
        int nx = 0 + dx[i];
        int ny = 0 + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N && board[nx][ny] == 0) {
            dist[nx][ny][i] = 100;
            pq.push({nx, ny, i, 100});
        }
    }

    int answer = 1e9;
    while(!pq.empty()) {
        NodeData cur = pq.top(); pq.pop();

        if(cur.cost > dist[cur.x][cur.y][cur.dir]) continue;
        if(cur.x == N-1 && cur.y == N-1) {
            answer = min(answer, cur.cost);
            continue;
        }

        for(int i=0; i<4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] == 1) continue;

            // 같은 방향이면 100, 다른 방향(커브)이면 100 + 500
            int nextCost = cur.cost + 100;
            if(cur.dir != i) nextCost += 500;

            // 핵심: 해당 좌표에 해당 방향으로 온 적이 없거나, 더 저렴한 경우 갱신
            if(dist[nx][ny][i] >= nextCost) {
                dist[nx][ny][i] = nextCost;
                pq.push({nx, ny, i, nextCost});
            }
        }
    }

    return answer;
}