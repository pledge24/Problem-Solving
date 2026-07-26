#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    auto IsSatisfy = [](int n){
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
                return true;
        }
        
        return false;
    };
    
    for(int i = 1; i <= n; i++)
        answer += IsSatisfy(i);
    
    return answer;
}