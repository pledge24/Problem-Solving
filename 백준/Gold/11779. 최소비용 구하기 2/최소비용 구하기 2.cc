#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using edge = pair<int, int>;
using Graph = vector<vector<pair<int, int>>>;

struct cmp
{
    bool operator()(const edge& a, const edge& b){
        return a.second > b.second;
    }
};

void printResult(vector<int> &dist, vector<int> &parent, int src, int dst){
    // minPath cost
    cout << dist[dst] << '\n';

    vector<int> path;
    for(int v = dst; v != -1; v = parent[v])
        path.push_back(v);

    // numOfCities
    cout << path.size() << '\n';

    // reverse 
    reverse(path.begin(), path.end());

    // path
    for(int v : path)
        cout << v << ' ';
    cout << '\n';
    
    return;
}

void dijkstra(Graph& graph, int src, int dst){
    int N = graph.size();

    priority_queue<edge, vector<edge>, cmp> pq;
    vector<int> dist(N+1, INT32_MAX);
    vector<int> parent(N+1, -1);

    // start Vtx
    dist[src] = 0;
    pq.push(make_pair(src, 0));

    while(!pq.empty()){
        edge curPath = pq.top(); pq.pop();

        if(curPath.second > dist[curPath.first])
            continue;
        
        for(edge adj : graph[curPath.first]){
            int nextVtx = adj.first;
            int nextDist = curPath.second + adj.second;

            if(nextDist < dist[nextVtx]){
                dist[nextVtx] = nextDist;
                pq.push(make_pair(nextVtx, dist[nextVtx]));
                parent[nextVtx] = curPath.first;
            }
        }
    }

    // for(int d : dist)
    //     cout << d << ' ';
    // cout << '\n';

    printResult(dist, parent, src, dst);

    return;
}

int main(void){
    fastio;
    int n, m; cin >> n >> m;
    Graph graph(n+1);
    for(int i = 0; i < m; i++){
        int s, t, cost; cin >> s >> t >> cost;
        graph[s].push_back(make_pair(t, cost));
    }

    int s, t; cin >> s >> t;
    dijkstra(graph, s, t);

    return 0;
}