#include <bits/stdc++.h>

using namespace std;

string solution(int age) {
    string answer = "";
    
    while(age > 0)
    {
        int num = age % 10;
        age /= 10;
        answer += 'a' + num;
    }
    
    std::reverse(answer.begin(), answer.end());
    
    return answer;
}