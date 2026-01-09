#include <bits/stdc++.h>

#define MAX_COURSES 10

using namespace std;

// 코스 요리가 단품 메뉴 n개로 구성되어 있을때, 가장 잘 팔린 조합은? (동점이면 전부 표시)
// 결과는 사전순으로 반환해라.
vector<bool> isCourseN(MAX_COURSES+1);
vector<map<string, int>> mCount(MAX_COURSES+1); 

void DfsUtil(string& o, string str, int idx)
{
    int len = str.length();
    if(isCourseN[len])
    {
        map<string, int>& m = mCount[len];
        m[str]++;
    }
    
    for(int i = idx; i < o.length(); i++)
    {
        DfsUtil(o, str + o[i], i+1);
    }
}

void Dfs(string& o)
{
    string str = "";
    DfsUtil(o, str, 0);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // Sort
    for(string& o : orders)
    {
        sort(o.begin(), o.end());    
    }
    
    for(int elem : course)
    {
        isCourseN[elem] = true;
    }
    
    for(string& o : orders)
    {
        Dfs(o);
    }
    
    for(int n : course)
    {
        map<string, int>& m = mCount[n];
        if(m.size() <= 1)
            continue;
        
        // Find MaxCnt
        int maxN = 0;
        for(auto& p : m)
        {
            maxN = max(maxN, p.second);
        }
        
        if(maxN <= 1)
            continue;
        
        // Find Max Course
        for(auto& p : m)
        {
            if(maxN == p.second)
            {
                answer.push_back(p.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}