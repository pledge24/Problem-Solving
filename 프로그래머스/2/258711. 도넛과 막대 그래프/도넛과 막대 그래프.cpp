#include <bits/stdc++.h>

using namespace std;

using Graph = map<int, set<int>>;

// 그래프: 1개 이상의 정점 + 단방향 간선
// 도넛 모양 그래프: 한바퀴 돌고 돌아오는 구조(N/N) In: 1, Out: 1
// 막대 모양 그래프: 편도(N/N-1)                 In: 1, Out: 1 or 0
// 8자 모양 그래프: 8자로 이동(2N+1/2N+2)         In: 
// In이 하나도 없는 정점이 추가 정점.

enum 
{
    EXTRA_NO = 0,
    DONUT_GRAPH_COUNT,
    STICK_GRAPH_COUNT,
    EIGHT_GRAPH_COUNT
};

int getGraphType(Graph& graph, int start)
{
    
    int curVtx = start;
    while(graph[curVtx].size() == 1)
    {
        auto next = graph[curVtx].begin();
        curVtx = *next;
        
        if(curVtx == start)
            break;
    }
    
    if(graph[curVtx].size() == 0)
        return STICK_GRAPH_COUNT;
    
    if(graph[curVtx].size() == 2)
        return EIGHT_GRAPH_COUNT;
        
    return DONUT_GRAPH_COUNT;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    
    Graph graph;
    set<int> dstSet;
    for(const vector<int>& edge : edges)
    {
        int src = edge[0];
        int dst = edge[1];
        
        graph[src].insert(dst);
        
        dstSet.insert(dst);
    }
    
    // find Extra Vertex
    int extraNo = -1;
    for(auto& p : graph)
    {
        int vtxNo = p.first;
        bool NotIn = dstSet.find(vtxNo) == dstSet.end();
        bool MultiOut = graph[vtxNo].size() > 1;
        if(NotIn && MultiOut)
        {
            extraNo = vtxNo;
            answer[EXTRA_NO] = extraNo;
            break;
        }
    }
    
    for(int adj : graph[extraNo])
    {
        int graphType = getGraphType(graph, adj);
        answer[graphType]++;
    }
        
    return answer;
}