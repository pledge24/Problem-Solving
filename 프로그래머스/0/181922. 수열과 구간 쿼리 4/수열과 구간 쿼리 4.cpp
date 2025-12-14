#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(const vector<int>& query : queries)
    {
        int s = query[0];
        int e = query[1];
        int k = query[2];
        
        for(int i = s; i <= e; i++)
        {
            if(i % k == 0)
                arr[i]++;
        }
        
    }
    
    answer = arr;
    
    return answer;
}