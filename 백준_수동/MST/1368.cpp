#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct edgeData{
    int vertexNo;
    int weight;
};

struct cmp
{
    bool operator()(const edgeData& a, const edgeData& b){
        return a.weight > b.weight;
    }
};

int prim_algorithm(vector<vector<int>> graph, vector<int> umul, int N, int nextVertexNo){
    int totalCost = 0;
    vector<bool> visited; visited.resize(N);
    
    priority_queue<edgeData, vector<edgeData>, cmp> pq;

    for(int x = 0; x < N-1; x++){
       
        visited[nextVertexNo] = true;

        for(int i = 0; i < N; i++){
            if(!visited[i]) pq.push({i, graph[nextVertexNo][i]});  
        }

        // 우물을 파는게 다른 논에서 물을 길러오는 것보다 비용이 적은 경우
        if(!pq.empty()){
            
            int minUmulCost = INT32_MAX;
            int minIdx = -1;
            for(int i = 0; i < N; i++){
                if(!visited[i] && (umul[i] < minUmulCost)){
                    minUmulCost = umul[i];
                    minIdx = i;

                    // cout << "(cost, idx): "<< minUmulCost << " " << minIdx << '\n';
                } 
            }

            edgeData cur_edge = pq.top();
            if(minUmulCost < cur_edge.weight){
                totalCost += minUmulCost;
                nextVertexNo = minIdx;
                continue;
            }
        }
    
        while(!pq.empty()){
            edgeData cur_edge = pq.top(); pq.pop();
            if(!visited[cur_edge.vertexNo]){
                totalCost += cur_edge.weight;
                nextVertexNo = cur_edge.vertexNo;
                break;
            }
        }
    }
      
    return totalCost;
}

int main() {
	fastio;
    int N; cin >> N;

    vector<vector<int>> graph; graph.resize(N, vector<int>(N));
    vector<int> umul; umul.resize(N);

    for(int i = 0; i < N; i++){
        cin >> umul[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> graph[i][j];
        }
    }

    int ans =  INT32_MAX;
    for(int i = 0; i < N; i++){
        int umulCost = umul[i];
        int minEdgeCost = prim_algorithm(graph, umul, N, i);
        ans = min(ans, umulCost + minEdgeCost);
    }

    cout << ans << '\n';

    return 0;
}