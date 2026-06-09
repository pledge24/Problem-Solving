#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int order = 1;
    int num = 0;
    while(order <= n)
    {
        num++;
        
        if((num % 3 == 0) || (to_string(num).find('3') != string::npos))
        {
            continue;
        }
        
        order++;
    }
    
    answer = num;
    
    return answer;
}