#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    auto Bfs = [](vector<vector<int>>& computers, vector<bool>& visited, int start){
        queue<int> q; 
        
        // Init.
        visited[start] = true;
        q.push(start);
        
        // Process.
        while(!q.empty())
        {
            int cur = q.front(); q.pop();
            vector<int>& adj = computers[cur];
            for(int i = 0; i < adj.size(); i++)
            {
                if(adj[i] && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    };
    
    vector<bool> visited(n);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])    
        {
            Bfs(computers, visited, i);
            answer++;
        }
    }
    
    return answer;
}