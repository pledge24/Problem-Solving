#include <bits/stdc++.h>

using namespace std;

const int maxN = 8;

vector<char> friendList = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
vector<string> GData;

void DfsUtil(vector<char>& cur, vector<bool>& visited, int idx, int& answer)
{
    if(cur.size() == maxN)
    {
        // Check
        for(string& s : GData)
        {
            char c1 = s[0];
            char c2 = s[2];
            char op = s[3];
            int dist = s[4] - '0';
            
            int c1Pos = find(cur.begin(), cur.end(), c1) - cur.begin();
            int c2Pos = find(cur.begin(), cur.end(), c2) - cur.begin();
            int betweenN = abs(c1Pos - c2Pos) - 1;
            
            if(op == '=')
            {
                if(betweenN != dist)
                    return;
            }
            else if(op == '<')
            {
                if(betweenN >= dist)
                    return;
            }
            else if(op == '>')
            {
                if(betweenN <= dist)
                    return;
            }
        }
        
        answer++;
    }
    
    for(int i = 0; i < maxN; i++)
    {
        if(visited[i])
            continue;
        
        // Update
        {
            visited[i] = true;
            cur.push_back(friendList[i]);

            DfsUtil(cur, visited, i, answer);

            cur.pop_back();
            visited[i] = false;
        }
        
    }
}

void Dfs(int& answer)
{
    vector<bool> visited(maxN);
    vector<char> cur;
    DfsUtil(cur, visited, 0, answer);
}

int solution(int n, vector<string> data) {
    int answer = 0;
    
    GData = data;
    Dfs(answer);
    
    return answer;
}