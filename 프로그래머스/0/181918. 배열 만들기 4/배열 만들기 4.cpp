#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    
    for(int i = 0; i < arr.size();)
    {
        if(stk.empty())
        {
            stk.push_back(arr[i]);
            i++;
            continue;
        }
        
        if(stk.back() < arr[i])
        {
            stk.push_back(arr[i]);
            i++;
        }
        else
        {
            stk.pop_back();
        }
        
    }
    return stk;
}