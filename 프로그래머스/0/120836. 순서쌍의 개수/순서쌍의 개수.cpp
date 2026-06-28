#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i <= sqrt(n); i++)
        answer += n % i == 0 ? 2 : 0;
    
    int sqrtN = sqrt(n);
    if(sqrtN * sqrtN == n)
        answer--;
    
    return answer;
}