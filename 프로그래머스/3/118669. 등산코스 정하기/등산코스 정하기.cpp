#include <bits/stdc++.h>

#define INF 100'000'000

using namespace std;

using EdgeData = pair<int, int>; // <cost, vtxNo>
using PathData = pair<int, int>; // <intensity, vtxNo>
using Graph = vector<vector<EdgeData>>;

PathData dijkstra(Graph& graph, vector<int>& gates, vector<int>& summits)
{
    int N = graph.size();
    priority_queue<PathData, vector<PathData>, greater<PathData>> pq; // 후보들이 들어감
    vector<int> minIntensity(N, INF);
    
    vector<bool> isGate(N, false);
    vector<bool> isSummit(N, false);
    
    // Init.
    {
        for(const int& gateNo : gates)
        {
            pq.push(make_pair(0, gateNo));
            isGate[gateNo] = true;
        }

        for(const int& summit : summits)
        {
            isSummit[summit] = true;
        }
    }
    
    // Process
    while(!pq.empty())
    {
        PathData pd = pq.top(); pq.pop();
        int intensity = pd.first;
        int vtxNo = pd.second;
        
        if(intensity >= minIntensity[vtxNo])
            continue;
        
        minIntensity[vtxNo] = intensity;
        
        if(isSummit[vtxNo])
            continue;
        
        for(EdgeData& ed : graph[vtxNo])
        {
            int pathIntensity = max(intensity, ed.first);
            int nextVtxNo = ed.second;

            if(isGate[nextVtxNo])
                continue;
            
            pq.push(make_pair(pathIntensity, nextVtxNo));
        }
    }
    
    // for(int elem : minIntensity)
    // {
    //     cout << elem << ' ';
    // }
    // cout << '\n';
    
    PathData minPd = make_pair(INF, -1);
    for(int summ : summits)
    {
        int inten = minIntensity[summ];
        PathData pd = make_pair(inten, summ);
        
        minPd = min(minPd, pd);
    }
    
    
    return minPd;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    Graph graph(n+1);
    for(const vector<int>& path : paths)
    {
        int vtx1 = path[0];
        int vtx2 = path[1];
        int w = path[2];
        
        graph[vtx1].push_back(make_pair(w, vtx2));
        graph[vtx2].push_back(make_pair(w, vtx1));
    }
    
    pair<int, int> p = dijkstra(graph, gates, summits);
    
    answer = {p.second, p.first};
    
    return answer;
}