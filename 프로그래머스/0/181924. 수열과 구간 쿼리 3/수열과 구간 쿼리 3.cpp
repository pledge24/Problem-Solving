#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(const vector<int>& query : queries)
    {
        int idx1 = query[0];
        int idx2 = query[1];
        
        std::swap(arr[idx1], arr[idx2]);
    }
    
    answer = arr;
    
    return answer;
}