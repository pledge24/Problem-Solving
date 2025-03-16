#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define OUT

using namespace std;
using Graph = vector<vector<int>>;

int bfs(Graph& graph, int start){
    int N = graph.size();
    int cnt = 0;
    vector<bool> visited(N);

    queue<int> q;
    q.push(start);
    visited[start] = true;
    cnt++;

    while(!q.empty()){
        int curIdx = q.front(); q.pop();

        for(int adjacent : graph[curIdx]){
            if(!visited[adjacent]){
                q.push(adjacent);
                visited[adjacent] = true;
                cnt++;
            }
        }
    }

    // for(bool elem : visited){
    //     cout << elem << ' ';
    // }
    // cout << '\n';

    return cnt;
}

struct cmp{
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
        if(p1.first == p2.first)
            return p1.second < p2.second;

        return p1.first > p2.first;
    }
};

int main(void){
    fastio;
    int N, M; cin >> N >> M;
    
    Graph graph(N+1);
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B;
        graph[B].push_back(A);
    }

    vector<pair<int, int>> ans; // comN, idx
    for(int i = 1; i <= N; i++){       
        int cnt = bfs(graph, i);
        ans.push_back(make_pair(cnt, i));
    }

    sort(ans.begin(), ans.end(), cmp());

    // for(auto elem : ans){
    //     cout << elem.first << ' ' << elem.second << '\n';
    // }

    for(int i = 0; i < ans.size(); i++){
        if(ans[i].first < ans[0].first)
            break;

        cout << ans[i].second << ' ';
    }
    cout << '\n';

    return 0;
}