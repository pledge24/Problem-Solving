#include <bits/stdc++.h>

#define INF 100'000'000

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    
    std::sort(numlist.begin(), numlist.end());
    int startIdx = lower_bound(numlist.begin(), numlist.end(), n) - numlist.begin();
    
    int left = startIdx - 1;
    int right = startIdx;
    
    while(left >= 0 || right < numlist.size())
    {
        int leftGap = left >= 0 ? abs(n - numlist[left]) : INF;
        int rightGap = right < numlist.size() ? abs(n - numlist[right]) : INF;
        
        if(leftGap < rightGap)
        {
            answer.push_back(numlist[left]);
            left--;
        }
        else
        {
            answer.push_back(numlist[right]);
            right++;
        }
    }
    
    return answer;
}