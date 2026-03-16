#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int type;
    vector<int> child;
};

using Graph = vector<Node>;

int maxSheeps = 0;

void Backtracking(const Graph& graph, int cur, int sheeps, int wolves, set<int> nextSet)
{
    nextSet.erase(cur); // Erase curNode.
    
    int type = graph[cur].type;
    if(type == 0)
    {
        sheeps++;
        maxSheeps = max(maxSheeps, sheeps);
    }
    else
    {
        wolves++;
    }
    
    if(sheeps <= wolves)
        return;
    
    // Add next Node.
    for(int next : graph[cur].child)
    {
        nextSet.insert(next);
    }
    
    // Backtracking
    for(int next : nextSet)
    {
        Backtracking(graph, next, sheeps, wolves, nextSet);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int nodeN = info.size();
    
    Graph graph(nodeN);
    
    // Make Graph.
    {
        for(int i = 0; i < nodeN; i++)
        {
            graph[i].type = info[i];
        }

        for(vector<int> ed : edges)
        {
            int p = ed[0];
            int c = ed[1];

            graph[p].child.push_back(c);
        }
    }
    
    // Start Backtracking.
    int cur = 0;
    int sheeps = 0;
    int wolves = 0;
    set<int> next;
    Backtracking(graph, cur, sheeps, wolves, next); // 일단 되든 안되든 가는 방식.
    
    answer = maxSheeps;
    
    return answer;
}