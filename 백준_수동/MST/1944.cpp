#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4

using namespace std;

struct posData{
    int x;
    int y;
    int cnt = 0;
};

struct edgeData{
    int node1;
    int node2;
    int weight;
};

struct cmp
{
    bool operator()(const edgeData& a, const edgeData& b){
        return a.weight > b.weight;
    }
};

int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

int N, M;

vector<int> root;
// 왜 bfs 파라미터로 넣으면 안되는가
priority_queue<edgeData, vector<edgeData>, cmp> pq;

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

int bfs(vector<vector<char>> matrix, vector<posData> vtxPosList, int vtxNo){  
    int keys = 0;
    posData startPosData = vtxPosList[vtxNo];
    vector<vector<bool>> visited(N, vector<bool>(N));
    queue<posData> q;

    q.push(startPosData);
    visited[startPosData.x][startPosData.y] = true;
    matrix[startPosData.x][startPosData.y] = '1';

    while(!q.empty()){
        posData curPos = q.front(); q.pop();

        for(int i = 0; i < DIR; i++){
            int nx = curPos.x + dx[i];
            int ny = curPos.y + dy[i];
            int nextCnt = curPos.cnt + 1;

            if(inRange(nx, ny) && matrix[nx][ny] != '1' && !visited[nx][ny]){
                
                if(matrix[nx][ny] == 'K'){

                    for(int idx = 0; idx < vtxPosList.size(); idx++){
                        if(vtxPosList[idx].x == nx && vtxPosList[idx].y == ny){
                            pq.push({vtxNo, idx, nextCnt});
                            break;
                        }
                    }
                    
                    keys++; 
                }       

                q.push({nx, ny, nextCnt});
                visited[nx][ny] = true;
                matrix[nx][ny] = '1';
            }
        }
    }

    return keys;
}

int find(int x) {
    if (root[x] == x) {
        return x;
    } else {
        return find(root[x]);
    }
}

void union_set(int x, int y){

    x = find(x);
    y = find(y);

    if(x < y){
        root[y] = x;
    }
    else{
        root[x] = y;
    }
}

int kruscal_algorithm(priority_queue<edgeData, vector<edgeData>, cmp> pq){
    int edge_sum = 0;

    while(!pq.empty()){
        edgeData cur_edge = pq.top(); pq.pop();

        if (find(cur_edge.node1) != find(cur_edge.node2)){
            union_set(cur_edge.node1, cur_edge.node2);
            edge_sum += cur_edge.weight;
        }

    }

    return edge_sum;
}

int main() {
	fastio;
    cin >> N >> M;

    vector<vector<char>> matrix(N, vector<char>(N));
    vector<posData> vtxPosList(M+1);

    string str;
    int keyNo = 1;
    // input data in matrix
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < N; j++){
            matrix[i][j] = str[j];
            if(str[j] == 'S'){
                vtxPosList[0] = {i, j};
            }
            else if(str[j] == 'K'){
                vtxPosList[keyNo++] = {i, j};
            }
        }
    }

    int foundKeys = bfs(matrix, vtxPosList, 0);

    if(foundKeys != M){
        cout << -1 << '\n';
        return 0;
    }

    for(int i = 1; i < vtxPosList.size(); i++){
        bfs(matrix, vtxPosList, i);
    }

    root.resize(vtxPosList.size());
    for(int i = 0; i < vtxPosList.size(); i++){
        root[i] = i;
    }
 
    // while(!pq.empty()){
    //     edgeData ed = pq.top(); pq.pop();
    //     cout << "ed is " << ed.node1 << " " << ed.node2 << " " << ed.weight << '\n';
    // }

    int ans = kruscal_algorithm(pq);

    cout << ans << '\n';
}

// 의문점 1. 중복되어 이동하는 경로가 항상 없는가?
// 의문점 2. 최소 경로의 합은 항상 전체 경로의 최소인가?