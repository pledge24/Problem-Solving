#include <bits/stdc++.h>

using namespace std;

int n, k; 
set<vector<int>> s1;
int test = 0;

void DfsUtil(vector<string>& user_id, vector<string>& banned_id, vector<bool>& visited, vector<int> seq)
{
    if(seq.size() == k)
    {
        test++;
        // for(int elem : seq)
        // {
        //     cout << elem << " ";
        // }    
        // cout << '\n';
        
        for(int i = 0; i < k; i++)
        {
            const string userStr = user_id[seq[i]];
            const string bannedStr = banned_id[i];
            
            if(userStr.length() != bannedStr.length())
                return;
            
            for(int j = 0; j < userStr.length(); j++)
            {
                if(bannedStr[j] == '*')
                    continue;
                
                if(userStr[j] != bannedStr[j])
                    return;
            }
        }
        
        // for(int elem : seq)
        // {
        //     cout << user_id[elem] << " ";
        // }    
        // cout << '\n';
        
        sort(seq.begin(), seq.end());
        s1.insert(seq);
        
        return;
    }
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            seq.push_back(i);
            DfsUtil(user_id, banned_id, visited, seq);
            visited[i] = false;
            seq.pop_back();
        }
    }
}

void Dfs(vector<string>& user_id, vector<string>& banned_id)
{
    vector<bool> visited(n);
    vector<int> seq;
    for(int i = 0; i < n; i++)
    {
        visited[i] = true;
        seq.push_back(i);
        DfsUtil(user_id, banned_id, visited, seq);
        visited[i] = false;
        seq.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    n = user_id.size();
    k = banned_id.size();
    
    Dfs(user_id, banned_id);
    
    answer = s1.size();
    
    return answer;
}