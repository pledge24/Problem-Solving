#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXN 1'000'000'000
using namespace std;

struct pos_data_1916
{
    int pos;
    int distance;
};

int main() {
	fastio;
    int n, m; cin >> n >> m;

    vector<vector<int>> matrix;
    vector<int> shortest_path;
 
    matrix.resize(n+1, vector<int>(n+1, MAXN));
    shortest_path.resize(n+1);
  
    // input data
    int src, dst, w;
    for(int i = 0; i < m; i++){
        cin >> src >> dst >> w;
        // 출발지와 목적지가 같다면 작은값만 저장.
        matrix[src][dst] = min(matrix[src][dst], w);
    }

    int start, end; 
    cin >> start >> end;

    shortest_path = matrix[start];
    
    queue<pos_data_1916> q;

    // 시작 지점에서 각 정점까지의 거리를 q에 저장.
    for(int i = 1; i <= n; i++){
        q.push({i, shortest_path[i]});
    }

    while(!q.empty()){
        pos_data_1916 cur_pos = q.front(); q.pop();

        for(int i = 1; i <= n; i++){
            // start~cur_pos + cur_pos~i 까지의 거리가 저장된 start~i보다 짧다면,
            // 해당 거리를 shortest_path에 저장하고 q에도 저장.
            if(cur_pos.distance + matrix[cur_pos.pos][i] < shortest_path[i]){
                shortest_path[i] = cur_pos.distance + matrix[cur_pos.pos][i];
                q.push({i, cur_pos.distance + matrix[cur_pos.pos][i]});
            }
        }
    }
    
    cout << shortest_path[end] << '\n';

}