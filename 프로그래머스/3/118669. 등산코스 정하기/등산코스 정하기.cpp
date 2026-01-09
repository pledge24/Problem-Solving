#include <bits/stdc++.h>

using namespace std;
using EdgeData = pair<int, pair<int, int>>;     // <cost, <vtx1, vtx2>>
using AdjList = vector<pair<int, int>>;         // <dst, cost>
using Tree = vector<AdjList>;    

vector<int> parent;
const int MAX_W = 10'000'000;

// union-find 알고리즘(경로 압축 + union by rank포함)
int find(int x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

bool is_diff_group(int u, int v){
    u = find(u); 
    v = find(v);

    if(u == v) return false;

    if(parent[u] == parent[v]) parent[u]--;

    if(parent[u] < parent[v]) parent[v] = u;
    else parent[u] = v;

    return true;
}

pair<int, int> Bfs(Tree& mst, int gateNo, vector<bool>& isSummits)
{
    int N = mst.size();
    vector<bool> visited(N,false);
    queue<pair<int, int>> q;    // <MaxIntensity, curVtxNo>
    {
        q.push(make_pair(0, gateNo));
        visited[gateNo] = true;
    }
    
    pair<int, int> res = make_pair(MAX_W+1, -1); // intensity, vtxNo
    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();
        int maxIntensity = p.first;
        int vtxNo = p.second;
        
        AdjList& adj = mst[vtxNo];
        for(auto& p : adj)
        {
            int nextVtxNo = p.first;
            int intensity = p.second;
            
            if(visited[nextVtxNo])
                continue;
            
            visited[nextVtxNo] = true;
            pair<int, int> next = make_pair(max(intensity, maxIntensity), nextVtxNo);
            
            if(isSummits[nextVtxNo])
                res = min(res, next);
            else
                q.push(next);
        }
    }
    
    
    return res;
}

// MST를 크루스칼 알고리즘으로 만들면 끝난다.
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    priority_queue<EdgeData, vector<EdgeData>, greater<EdgeData>> pq;
    for(vector<int>& p : paths)
    {
        int i = p[0];
        int j = p[1];
        int w = p[2];
        
        EdgeData data = make_pair(w, make_pair(i, j));
        pq.push(std::move(data));
    }
    
    // Make MST
    Tree mst(n+1);
    parent.resize(n+1, -1);
    int cnt = 0;
    while(!pq.empty())
    {
        EdgeData ed = pq.top(); pq.pop();
        int cost = ed.first;
        pair<int, int> endPoint = ed.second;
        int vtx1 = endPoint.first;
        int vtx2 = endPoint.second;
        
        if(!is_diff_group(vtx1, vtx2))
            continue;
              
        // Add Adj
        mst[vtx1].push_back(make_pair(vtx2, cost));
        mst[vtx2].push_back(make_pair(vtx1, cost));
        
        cnt++;
        
        if(cnt == n-1)
            break;
    }
    
    vector<bool> isSummits(n, false);
    for(const int& elem : summits)
    {
        isSummits[elem] = true;
    }
    
    bool first = true;
    pair<int, int> res; // intensity, vtxNo
    for(const int& gate : gates)
    {
        pair<int, int> p = Bfs(mst, gate, isSummits);
        if(first)
        {
            first = false;
            res = p;
            continue;
        }
        
        res = min(res, p);
    }
    
    answer = {res.second, res.first};
    
    return answer;
}