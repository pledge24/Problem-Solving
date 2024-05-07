#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF INT32_MAX

using namespace std;

int V, E; 
vector<vector<pair<int, int>>> graph;

int Dijkstra_algorithm(int Start, int End)
{
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, Start));
    vector<int> Dist(V+1, INF);
    Dist[Start] = 0;
    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
        for (int i = 0; i < graph[Cur].size(); i++)
        {
            int Next = graph[Cur][i].first;
            int nCost = graph[Cur][i].second;
            if (Dist[Next] > Cost + nCost)
            {
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }
    
    return Dist[End];
}

int main() {
	fastio;
    cin >> V >> E;

    graph.resize(V+1);
    int u, v, w;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int a, b;
    cin >> a >> b;

    int ans = -1;
    
    int s_a = Dijkstra_algorithm(1, a);
    int s_b = Dijkstra_algorithm(1, b);
    int a_b = Dijkstra_algorithm(a, b);
    int a_v = Dijkstra_algorithm(a, V);
    int b_v = Dijkstra_algorithm(b, V);
    
    //cout << x << " " <<  << y << " " << z << '\n';
    if(s_a == INF || a_b == INF || b_v == INF){
        
    } 
    else{
        ans = s_a + a_b + b_v;
    }

    if(s_b == INF || a_b == INF || a_v == INF){
        
    } 
    else{
        ans = min(ans, s_b + a_b + a_v);
    }

    cout << ans << '\n';

    return 0;
}