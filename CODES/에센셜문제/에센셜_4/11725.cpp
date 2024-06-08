#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;

int N; 

vector<int> bfs(){
    queue<int> q;

    visited[1] = true;
    q.push(1);

    vector<int> ans(N+1);
   
    while(!q.empty()){
        int cur_node = q.front(); q.pop();

        for(int next_node : nodes[cur_node]){
            if(!visited[next_node]){
                visited[next_node] = true;
                q.push(next_node);
                ans[next_node] = cur_node;
            }
            
        }
    }

    return ans;
}

int main() {
	fastio;
    cin >> N;

    nodes.resize(N+1);
    visited.resize(N+1);

    int node1, node2;
    for(int i = 0; i < N-1; i++){
        cin >> node1 >> node2;
        nodes[node1].push_back(node2);
        nodes[node2].push_back(node1);
    }
    
    vector<int> ans;
    ans = bfs();

    for(int i = 2; i <= N; i++){
        cout << ans[i] << '\n';
    }

}