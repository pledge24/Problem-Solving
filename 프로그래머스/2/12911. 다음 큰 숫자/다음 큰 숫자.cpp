#include <bits/stdc++.h>

using namespace std;

int oneN = 0;

bool IsMatch(int oneN, int num)
{
    int cnt = 0;
    while(num > 0)
    {
        cnt += num % 2;
        num /= 2;
    }
    
    return cnt == oneN;
}

int solution(int n) {
    int answer = 0;
    
    int temp = n;
    while(temp > 0)
    {
        oneN += temp % 2;
        temp /= 2;
    }
    
    int curNum = n+1;
    while(true)
    {
        if(IsMatch(oneN, curNum))
        {
            answer = curNum;
            break;
        }
        
        curNum++;
    }
    
    return answer;
}