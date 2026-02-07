#include <bits/stdc++.h>

using namespace std;

const int MAX_NO = 10'000'000;

int GetNumber(int num)
{
    if(num == 1)
        return 0;
    
    int res = 1;
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            if(num/i <= MAX_NO)
            {
                res = max(i, num/i);
                break;
            }
            else
            {
                res = i;
            }
            
        }
    }
    
    return res;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(int i = begin; i <= end; i++)
    {
        int num = GetNumber(i);
        answer.push_back(num);
    }
    
    return answer;
}