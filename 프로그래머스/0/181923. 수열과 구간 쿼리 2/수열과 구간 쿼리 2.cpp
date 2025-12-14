#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(const vector<int>& query : queries)
    {
        int startIdx = query[0];
        int endIdx = query[1];
        int k = query[2];
        
        int res = -1;
        for(int idx = startIdx; idx <= endIdx; idx++)
        {
            if(arr[idx] > k)
            {
                res = res == -1 ? arr[idx] : min(res, arr[idx]);
            }
        }
        
        answer.push_back(res);
    }
    
    return answer;
}