#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b, int c) {
    int answer = 0;
    set<int> s = {a, b, c};
    
    if(s.size() <= 3)
        answer = (a + b + c); 
    if(s.size() <= 2)
        answer *= (a*a + b*b + c*c);
    if(s.size() <= 1)
        answer *= (a*a*a + b*b*b + c*c*c);

    return answer;
}