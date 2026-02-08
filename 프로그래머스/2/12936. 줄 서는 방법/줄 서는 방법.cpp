#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int64 GetFactorial(int n)
{
    int64 res = 1;
    for(int i = 2; i <= n; i++)
        res *= i;
    
    return res;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> idxList;
    
    k--;
    for(int i = n; i > 0; i--)
    {
        int64 cycleUnit = GetFactorial(i-1);
        int64 cycleN = k / cycleUnit;
        idxList.push_back(cycleN % i);
    }
    
    vector<bool> used(n);
    for(int idx : idxList)
    {
        // cout << idx << ' ';
        int passN = 0;
        for(int i = 0; i < used.size(); i++)
        {
            if(!used[i])
            {
                if(idx == passN)
                {
                    used[i] = true;
                    answer.push_back(i+1);
                    break;
                }
                else
                {
                    passN++;
                }
            }
        }
    }
    
    
    return answer;
}