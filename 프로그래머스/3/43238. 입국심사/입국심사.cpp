#include <bits/stdc++.h>

#define MAX_TIME 1'000'000'000

using namespace std;

using int64 = long long;

bool IsValid(int n, const vector<int>& times, int64 deadline)
{
    int64 cnt = 0;
    for(int t : times)
    {
        cnt += deadline / t;
        if (cnt >= n) 
            return true; 
    }
    
    return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    // times에서 가장 큰 값을 찾습니다.
    int64 max_time = *max_element(times.begin(), times.end());
    
    // Parametric Searching
    int64 left = 1;
    // 가장 오래 걸리는 심사관이 혼자 n명을 다 심사할 때 걸리는 시간을 최댓값으로 설정
    int64 right = (int64)MAX_TIME * (int64)n; 
    
    while(left < right)
    {
        //int64 mid = left + (right - left) / 2; // (left + right) / 2 의 오버플로우 방지식
        int64 mid = (left + right) / 2;
        if(IsValid(n, times, mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    answer = left;
    return answer;
}