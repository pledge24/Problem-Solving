#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    set<int> nums;
    int len = 0;
    for(int elem : arr)
    {
        if(nums.find(elem) == nums.end())    
        {
            nums.insert(elem);
            answer.push_back(elem);
            len++;
        }
        
        if(len == k)
            break;
    }
    
    while(answer.size() < k)
        answer.push_back(-1);
    
    return answer;
}