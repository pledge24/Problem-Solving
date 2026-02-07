#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int e = 1;
    int sum = 1;
    for(int s = 1; s <= n; s++)
    {
        while(e < n && sum < n)
        {
            e++;
            sum += e;
        }
        
        if(sum == n)
            answer++;
        
        sum -= s;
    }
    
    return answer;
}