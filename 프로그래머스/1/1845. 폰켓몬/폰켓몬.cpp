#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> m1;
    for(auto elem : nums){
        m1[elem]++;
    }
    
    int maxTakeN = nums.size() / 2;
    int maxKindOf = m1.size();
    
    answer = maxTakeN < maxKindOf ? maxTakeN : maxKindOf;
    
    return answer;
}