#include <bits/stdc++.h>

using namespace std;
using EdgeData = pair<int, pair<int, int>>;

vector<int> parent;

int GetRoot(int x)
{
    if(parent[x] == x)
        return x;
    
    return parent[x] = GetRoot(parent[x]);
}

void Union(int vtx1, int vtx2)
{
    if(vtx1 > vtx2)
        swap(vtx1, vtx2);   // 큰 번호가 root
    
    parent[vtx1] = vtx2;    
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    priority_queue<EdgeData, vector<EdgeData>, greater<EdgeData>> pq;
    for(vector<int> c : costs)
    {
        int vtx1 = c[0];
        int vtx2 = c[1];
        int w = c[2];
        
        pq.push(make_pair(w, make_pair(vtx1, vtx2)));
    }
    
    // Init
    parent.resize(n);
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    
    while(!pq.empty())
    {
        // for(int i = 0; i < n; i++)
        //     cout << parent[i] << ' ';
        // cout << '\n';
        
        auto p = pq.top(); pq.pop();
        int w = p.first;
        int vtx1 = p.second.first;
        int vtx2 = p.second.second;
        
        int root1 = GetRoot(vtx1);
        int root2 = GetRoot(vtx2);
        if(root1 == root2)
            continue;
        
        Union(root1, root2);
        answer += w;
    }
    
    return answer;
}