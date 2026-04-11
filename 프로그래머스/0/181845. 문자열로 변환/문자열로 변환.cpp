#include <bits/stdc++.h>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n > 0)
    {
        answer += (n % 10) + '0';
        n /= 10;
    }
    
    std::reverse(answer.begin(), answer.end());
    
    return answer;
}