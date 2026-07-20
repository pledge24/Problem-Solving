#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;

Graph g;
vector<pair<int, int>> scoreBoard;

void Dfs(vector<bool>& isWins, int vtxNo)
{
    for(int next : g[vtxNo])
    {
        if(isWins[next] == true)
            continue;
        
        isWins[next] = true;
        scoreBoard[next].second++;  // stack loses.
        
        Dfs(isWins, next);
    }
        
    return;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    g.resize(n+1);
    scoreBoard.resize(n+1);
    
    for(vector<int>& r : results)
    {
        int vtx1 = r[0];
        int vtx2 = r[1];
        
        g[vtx1].push_back(vtx2);
    }
    
    for(int i = 1; i <= n; i++)
    {
        vector<bool> isWins(n+1);
        Dfs(isWins, i); // Get Wins;
        scoreBoard[i].first = std::count(isWins.begin(), isWins.end(), true);
    }
    
    for(int i = 1; i <= n; i++)
    {
        pair<int, int> p = scoreBoard[i];
        answer += (p.first + p.second + 1) == n;
    }
    
    return answer;
}