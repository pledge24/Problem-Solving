#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct NodeData
{
    int jobCost = 0;
    int preCost = 0;
    vector<int> outdeg;
};

void TS(vector<NodeData>& graph, vector<int>& indeg)
{
    // Init Q
    queue<int> q;
    for(int i = 1; i < indeg.size(); i++)
    {
        if(indeg[i] == 0)
            q.push(i);
    }

    // Process
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        NodeData& nd = graph[cur];
        int totalCost = nd.jobCost + nd.preCost;

        for(int outNode : nd.outdeg)
        {
            NodeData& next = graph[outNode];
            next.preCost = max(next.preCost, totalCost);
            indeg[outNode]--;
            if(indeg[outNode] == 0)
                q.push(outNode);
        }
    }

    int totalCost = 0;
    for(int i = 1; i < graph.size(); i++)
        totalCost = max(totalCost, graph[i].jobCost + graph[i].preCost);

    cout << totalCost << '\n';
}

int main(void)
{
    fastio;

    int N; cin >> N;
    vector<NodeData> graph(N+1);
    vector<int> indeg(N+1);
    for(int i = 1; i <= N; i++)
    {
        NodeData& nd = graph[i];
        cin >> nd.jobCost;

        int prevN; cin >> prevN;
        indeg[i] = prevN;
        for(int j = 0; j < prevN; j++)
        {
            int preNode; cin >> preNode;
            graph[preNode].outdeg.push_back(i);
        }
    }

    TS(graph, indeg);

}