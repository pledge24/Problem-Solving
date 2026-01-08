#include <bits/stdc++.h>

using namespace std;

void Split(string& str, vector<string>& res, const string& delimeter, const string& exceptStr = "")
{
    int pos = 0;
    while(pos < str.length())
    {
        int nextDelimeterPos = str.find(delimeter, pos);
        if(nextDelimeterPos == string::npos)
        {
            nextDelimeterPos = str.length();
        }
        
        int len = nextDelimeterPos - pos;
        if(len > 0)
        {
            string splitRes = str.substr(pos, len);
            if(splitRes != exceptStr)
                res.push_back(std::move(splitRes));
        }
        
        // delimeter가 붙어있는 경우 len이 0이 나올 수 있다.
        pos = nextDelimeterPos + delimeter.size();
    }
}

unordered_map<string, vector<int>> m;

void DfsUtil(int n, vector<string>& info, string curStr, int score)
{
    if(n == info.size())
    {
        m[curStr].push_back(score);
        return;
    }
    
    DfsUtil(n+1, info, curStr + info[n], score);
    DfsUtil(n+1, info, curStr + "-", score);
}

void Dfs(vector<string>& info, int score)
{
    int n = 0;
    string str = "";
    
    DfsUtil(n, info, str, score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    // Input
    for(string& info_ : info)
    {
        vector<string> splitted;
        Split(info_, splitted, " ");
        
        int score = stoi(splitted.back()); splitted.pop_back();
        Dfs(splitted, score);
    }
    
    // Sort
    for(auto& elem : m)
    {
        vector<int>& scoreList = elem.second;
        sort(scoreList.begin(), scoreList.end());
    }
    
    // Get Answer
    for(string& q : query)
    {
        vector<string> splitted;
        Split(q, splitted, " ", "and");  
        
        int score = stoi(splitted.back()); splitted.pop_back();
        
        string keyStr = "";
        for(string& str : splitted)
        {
            keyStr += str;
        }
        
        if(m.find(keyStr) == m.end())
        {
            answer.push_back(0);
            continue;
        }
        
        vector<int>& scoreList = m[keyStr];
        int cnt = scoreList.size() - (lower_bound(scoreList.begin(), scoreList.end(), score) - scoreList.begin());
        
        answer.push_back(cnt);
    }
    
    return answer;
}