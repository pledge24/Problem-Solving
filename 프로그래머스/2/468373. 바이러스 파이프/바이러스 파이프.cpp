#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<pair<int, int>>>;   // pair<type, vtx>
Graph graph;
int infectVtx;
int maxInfectedN;

void Dfs(vector<int> order, int k)
{
    if(order.size() == k)
    {
        // for(int elem : order)
        //     cout << elem << ' ';
        // cout << '\n';
        
        set<int> infected = {infectVtx};
        for(int pipeType : order)
        {
            vector<int> newInfected;
            do
            {
                newInfected.clear();
                
                for(int vtx : infected)
                {
                    vector<pair<int, int>>& node = graph[vtx];
                    for(pair<int, int>& adj : node)
                    {
                        if(adj.first == pipeType && infected.find(adj.second) == infected.end())
                        {
                            newInfected.push_back(adj.second);
                        }
                    }
                }

                for(int x : newInfected)
                    infected.insert(x);
            }
            while(newInfected.size() > 0);
        }
        
        maxInfectedN = max(maxInfectedN, (int)infected.size());
        // for(int x : infected)
        //     cout << x << " ";
        // cout << "\n================\n";
        
        return;
    }
    
    for(int i = 1; i <= 3; i++)
    {
        order.push_back(i);
        Dfs(order, k);
        order.pop_back();
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    
    graph.resize(n+1);
    infectVtx = infection;
    
    for(vector<int>& ed : edges)
    {
        int vtx1 = ed[0];
        int vtx2 = ed[1];
        int type = ed[2];
        
        graph[vtx1].push_back(make_pair(type, vtx2));
        graph[vtx2].push_back(make_pair(type, vtx1));
    }
    
    vector<int> order;
    maxInfectedN = 0;
    Dfs(order, k);
    
    answer = maxInfectedN;
    
    return answer;
}