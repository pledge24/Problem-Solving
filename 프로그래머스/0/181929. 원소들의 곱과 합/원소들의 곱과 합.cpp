#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int res1 = 0;
    int res2 = 0;
    bool first = true;
    for(const int& num : num_list)
    {
        if(first)
        {
            first = false;
            res1 = num;
            res2 = num;
            
            continue;
        }
        
        res1 *= num;
        res2 += num;
    }
    
    answer = res1 < (res2*res2);
    
    return answer;
}